#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H
#include <QWidget>
#include <SFML/Graphics.hpp>
#include <QTimer>
class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
   // Q_OBJECT
public:
   explicit QSFMLCanvas(QWidget *parent, const QPoint &Position, const QSize &Size, unsigned int frameTime = 0);
   virtual void showEvent(QShowEvent *);
   virtual void paintEvent(QPaintEvent *);
   virtual QPaintEngine *paintEngine() const;
   virtual ~QSFMLCanvas();
   virtual void onInit() = 0;
   virtual void onUpdate() = 0;
   QTimer myTimer;

private:
   bool myInitialized;
};
#endif // QSMLCANVAS_H