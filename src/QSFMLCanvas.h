#pragma once
#include <SFML/Graphics.hpp>
#include <QWidget>
#include <QTimer>
#include <QEvent>

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
   QSFMLCanvas(QWidget *Parent, const QPoint &Position, const QSize &Size, unsigned int FrameTime = 16);
   virtual ~QSFMLCanvas();

private:
   virtual void onInit() = 0;
   virtual void onUpdate() = 0;

   virtual void showEvent(QShowEvent *);
   virtual void paintEvent(QPaintEvent *);

   bool myInitialized;

   virtual QPaintEngine *paintEngine() const;
};

QSFMLCanvas::QSFMLCanvas(QWidget *Parent, const QPoint &position, const QSize &size, unsigned int frameTime) : QWidget(Parent),
                                                                                                               myInitialized(false)
{
   // Setup some states to allow direct rendering into the widget
   setAttribute(Qt::WA_PaintOnScreen);
   setAttribute(Qt::WA_OpaquePaintEvent);
   setAttribute(Qt::WA_NoSystemBackground);

   // Set strong focus to enable keyboard events to be received
   setFocusPolicy(Qt::StrongFocus);

   // Setup the widget geometry
   move(position);
   resize(size);
}

QSFMLCanvas::~QSFMLCanvas()
{
}

#ifdef Q_OS_LINUX
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif

QPaintEngine *QSFMLCanvas::paintEngine() const
{
   return nullptr;
}

void QSFMLCanvas::showEvent(QShowEvent *)
{
   if (!myInitialized)
   {
      // Under X11, we need to flush the commands sent to the server to ensure that
      // SFML will get an updated view of the windows
#ifdef Q_OS_LINUX
      XFlush(QX11Info::display());
#endif

      // Get the native window handle of the QWidget
      sf::WindowHandle handle = reinterpret_cast<sf::WindowHandle>(winId());

      // Create the SFML window with the widget handle
      sf::RenderWindow::create(handle);

      // Let the derived class do its specific initialization
      onInit();

      myInitialized = true;
   }
}

void QSFMLCanvas::paintEvent(QPaintEvent *)
{
   // Let the derived class do its specific rendering and logic
   onUpdate();

   // Display the SFML rendering on the widget
   display();
}
