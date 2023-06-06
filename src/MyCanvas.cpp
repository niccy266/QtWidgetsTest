#include "MyCanvas.h"
#include <SFML/Graphics/Image.hpp>
#include <fmt/format.h>
#include <fmt/chrono.h>

MyCanvas::MyCanvas(QWidget *Parent, unsigned int frameTime) : QSfmlWidget(Parent, frameTime)
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
   
   
   if (!myTexture.loadFromImage(myImage))
   {
      fprintf(stdout, "failed to load image to texture");
      return;
   }
   fprintf(stdout, "Loaded image texture in MyCanvas.cpp \n");


   mySprite.setPosition(200, 200);
   mySprite.setOrigin(100, 100);
   mySprite.setScale(0.1, 0.1);

   // Setup the sprite
   mySprite.setTexture(myTexture, true);

   mySprite.setPosition(200, 200);
   mySprite.setOrigin(100, 100);
   mySprite.setScale(0.1, 0.1);
   draw(mySprite);

   m_rect.setPosition(100, 200);
   m_rect.setSize(sf::Vector2f(100, 50));
   m_rect.setFillColor(sf::Color::Red);

   std::cout << "timer activates every " << frameTime << "ms \n" << std::endl;
}

void MyCanvas::onUpdate()
{

   // std::cout << "running on update\n" << std::endl;
   //  Clear screen
   clear(sf::Color(128, 128, 0));

   // Rotate the sprite
   //mySprite.rotate(frameTime * -0.01f);
   // Rotate the sprite
   //m_rect.rotate(frameTime * 0.10f);


   //m_rect.setPosition(100, 200);

   //auto timer_count = std::chrono::round<std::chrono::milliseconds>(m_timer.remainingTimeAsDuration());
   //std::cout << m_timer.remainingTime() << std::endl;

   // Draw it
   draw(mySprite);
   draw(m_rect);
}