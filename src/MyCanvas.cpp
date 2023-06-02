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
      myImage.LoadFromFile("datas/qt/sfml.png");

      // Setup the sprite
      mySprite.SetImage(myImage);
      mySprite.SetCenter(mySprite.GetSize() / 2.f);
   }

   void OnUpdate()
   {
      // Clear screen
      Clear(sf::Color(0, 128, 0));

      // Rotate the sprite
      mySprite.Rotate(GetFrameTime() * 100.f);

      // Draw it
      Draw(mySprite);
   }

   sf::Image myImage;
   sf::Sprite mySprite;
};

MyCanvas::MyCanvas()
{
}

MyCanvas::~MyCanvas()
{
}