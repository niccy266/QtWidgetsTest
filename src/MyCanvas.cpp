#include "MyCanvas.h"

MyCanvas::MyCanvas(QWidget *Parent) : QSfmlWidget(Parent)
{
}

void MyCanvas::onInit()
{
   fprintf(stdout, "setting up MyCanvas");

   // Load the image
   if(!myImage.loadFromFile("${workspaceFolder}/image/passion_flower.jpg")) {
      fprintf(stdout, "failed to load image");
   }
      

   // Setup the sprite
   mySprite.setTexture(myImage);
   mySprite.setPosition(myImage.getSize().x / 2, myImage.getSize().y / 2);
   draw(mySprite);

   m_rect.setPosition(100, 200);
   m_rect.setSize(sf::Vector2f(100, 50));
   m_rect.setFillColor(sf::Color::Red);
}


void MyCanvas::onUpdate()
{
   // Clear screen
   clear(sf::Color(0, 128, 0));

   // Rotate the sprite
   mySprite.rotate(m_timer.interval() * 100.f);

   // Draw it
   draw(mySprite);
   draw(m_rect);
}