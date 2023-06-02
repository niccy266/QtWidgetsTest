#include <SFML/Graphics.hpp>
#include <Qwidget>
#include <Qtimer>
#include <iostream>

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:
   QSFMLCanvas(QWidget *Parent, const QPoint &Position, const QSize &Size, unsigned int FrameTime = 0);
   virtual ~QSFMLCanvas();

   sf::Clock clock;

private:
   virtual void onInit();

   virtual void onUpdate();

   virtual QPaintEngine *paintEngine() const;

   virtual void showEvent(QShowEvent *);

   virtual void paintEvent(QPaintEvent *);

   bool myInitialized;
};

QSFMLCanvas::QSFMLCanvas(QWidget *Parent, const QPoint &Position, const QSize &Size, unsigned int FrameTime) : QWidget(Parent),
                                                                                                                 myInitialized(false)
{
   // Setup some states to allow direct rendering into the widget
   setAttribute(Qt::WA_PaintOnScreen);
   setAttribute(Qt::WA_OpaquePaintEvent);
   setAttribute(Qt::WA_NoSystemBackground);

   // Set strong focus to enable keyboard events to be received
   setFocusPolicy(Qt::StrongFocus);

   // Setup the widget geometry
   move(Position);
   resize(Size);

}

QSFMLCanvas::~QSFMLCanvas()
{
}

#ifdef Q_WS_X11
   #include <Qt/qx11info_x11.h>
   #include <X11/Xlib.h>
#endif

QPaintEngine *QSFMLCanvas::paintEngine() const
{
   return 0;
}

void QSFMLCanvas::showEvent(QShowEvent *)
{
   if (!myInitialized)
   {
// Under X11, we need to flush the commands sent to the server to ensure that
// SFML will get an updated view of the windows
#ifdef Q_WS_X11
      XFlush(QX11Info::display());
#endif

      // Create the SFML window with the widget handle
      QWidget::create(winId());

      // Let the derived class do its specific stuff
      onInit();
      
      // Setup the timer
      clock.restart();

      myInitialized = true;
   }
}

void QSFMLCanvas::paintEvent(QPaintEvent *)
{
   // Let the derived class do its specific stuff
   onUpdate();

   // Display on screen
   display();
}

