#include "QSfmlWidget.h"

QSfmlWidget::QSfmlWidget(QWidget *parent, unsigned int frameTime)
    : QWidget(parent),
      m_initialized(false)
{
   // Setup some states to allow direct rendering into the widget
   setAttribute(Qt::WA_PaintOnScreen);
   setAttribute(Qt::WA_OpaquePaintEvent);
   setAttribute(Qt::WA_NoSystemBackground);

   // Set strong focus to enable keyboard events to be received
   setFocusPolicy(Qt::StrongFocus);

   /* // Setup the widget geometry
   move(position);
   resize(size);
 */

   // Create a QTimer to trigger the widget updates
   m_timer.setInterval(frameTime); // Update roughly every 16 milliseconds (about 60 FPS)
}

void QSfmlWidget::showEvent(QShowEvent * event)
{
   Q_UNUSED(event);

   if (m_initialized)
   {
      // Create the SFML window with the widget handle
      sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()));
      // Let the derived class do its specific stuff
      onInit();
      // Setup the timer to trigger a refresh at specified framerate
      connect(&m_timer, SIGNAL(timeout()), this, SLOT(repaint()));
      m_timer.start();
      m_initialized = true;
   }
}

void QSfmlWidget::paintEvent(QPaintEvent *event)
{
   Q_UNUSED(event);

   RenderWindow::clear(sf::Color::White);
   // Let the derived class do its specific stuff
   onUpdate();
   // Display on screen
   RenderWindow::display();
}

QPaintEngine *QSfmlWidget::paintEngine() const
{
   return nullptr;
}

// to overwrite
void QSfmlWidget::onInit() {}
void QSfmlWidget::onUpdate() {}