#include "MyCanvas.h"
#include <SFML/Graphics/Image.hpp>

MyCanvas::MyCanvas(QWidget *Parent) : QSfmlWidget(Parent)
{
   setFixedSize(QSize(400, 400));
}

void MyCanvas::onInit()
{
   fprintf(stdout, "setting up MyCanvas \n");

   // Load the image
   sf::Image myImage;
   if (!myImage.loadFromFile("passion_flower.jpg"))
   {
      fprintf(stdout, "failed to load image");
      return;
   }
   sf::Texture myTexture;
   if (!myTexture.loadFromImage(myImage))
   {
      fprintf(stdout, "failed to load image to texture");
      return;
   }
   fprintf(stdout, "Loaded image texture in MyCanvas.cpp");

   // Setup the sprite
   mySprite.setTexture(myTexture);
   mySprite.setPosition(200, 200);
   mySprite.setOrigin(100, 100);
   mySprite.setScale(0.1, 0.1);
   draw(mySprite);

   m_rect.setPosition(100, 200);
   m_rect.setSize(sf::Vector2f(100, 50));
   m_rect.setFillColor(sf::Color::Red);
}

void MyCanvas::onUpdate()
{

   //std::cout << "running on update\n" << std::endl;
   // Clear screen
   clear(sf::Color(128, 128, 0));

   // Rotate the sprite
   mySprite.rotate(m_timer.interval() * 100.f);
   // Rotate the sprite
   m_rect.rotate(m_timer.interval() * 100.f);

   // Draw it
   draw(mySprite);
   draw(m_rect);
}