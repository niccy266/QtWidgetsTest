#include "QSFMLCanvas.h"

class MyCanvas : public QSFMLCanvas
{
public:
   MyCanvas(QWidget *Parent, const QPoint &Position, const QSize &Size) : QSFMLCanvas(Parent, Position, Size)
   {
   }

private:
   void onInit() override
   {
      // Load the image
      myImage.loadFromFile("~/Desktop/passion_flower.jpg");

      // Setup the sprite
      mySprite.setTexture(myImage);
      mySprite.setPosition(myImage.getSize().x / 2, myImage.getSize().y /2);
   }

   void onUpdate() override
   {
      // Clear screen
      clear(sf::Color(0, 128, 0));

      // Rotate the sprite
      mySprite.rotate(myTimer.interval() * 100.f);

      // Draw it
      draw(mySprite);
   }

   sf::Texture myImage;
   sf::Sprite mySprite;
};
