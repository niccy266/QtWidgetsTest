#include "MyCanvas.h"

MyCanvas::MyCanvas(QWidget *Parent) : QSfmlWidget(Parent)
{
}

void MyCanvas::onInit()
{
   fprintf(stdout, "setting up MyCanvas");

   // Load the image
   myImage.loadFromFile("~/Desktop/passion_flower.jpg");

   // Setup the sprite
   mySprite.setTexture(myImage);
   mySprite.setPosition(myImage.getSize().x / 2, myImage.getSize().y / 2);
   draw(mySprite);
}

void MyCanvas::onUpdate()
{
   // Clear screen
   clear(sf::Color(0, 128, 0));

   // Rotate the sprite
   mySprite.rotate(m_timer.interval() * 100.f);

   // Draw it
   draw(mySprite);
}