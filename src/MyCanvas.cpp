#include "QSFMLCanvas.cpp"

class MyCanvas : public QSFMLCanvas
{
public:
   MyCanvas(QWidget *Parent, const QPoint &Position, const QSize &Size) : QSFMLCanvas(Parent, Position, Size)
   {
   }

private:
   void OnInit()
   {
      // Load the image
      myImage.loadFromFile("~/Desktop/passion_flower.jpg");

      // Setup the sprite
      mySprite.setTexture(myImage);
      mySprite.setOrigin(myImage.getSize() / 2.f);
   }

   void OnUpdate()
   {
      // Clear screen
      clear(sf::Color(0, 128, 0));

      // Rotate the sprite
      mySprite.rotate(clock.getElapsedTime().asMilliseconds() * 100.f);

      // Draw it
      draw(mySprite);
   }

   sf::Texture myImage;
   sf::Sprite mySprite;
};
