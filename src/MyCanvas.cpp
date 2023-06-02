#pragma once
#include "QSFMLCanvas.h"
#include <QTimer>
#include <SFML/Graphics.hpp>

class MyCanvas : public QSFMLCanvas
{
public:
   MyCanvas(QWidget *parent, const QPoint &position, const QSize &size, unsigned int frameTime)
       : QSFMLCanvas(parent, position, size, frameTime)
   {
      // Set up a QTimer to trigger the SFMLWidget updates
      connect(&myTimer, SIGNAL(timeout()), this, SLOT(repaint()));
      myTimer.setInterval(frameTime);
      myTimer.start(frameTime);
      ; // Update according to the provided frame time
   }

private:
   void onInit() override
   {
      // Load the image
      myImage.loadFromFile("~/Desktop/passion_flower.jpg");

      // Setup the sprite
      mySprite.setTexture(myImage);
      mySprite.setOrigin(myImage.getSize().x / 2.f, myImage.getSize().y / 2.f);
      mySprite.setPosition(myImage.getSize().x / 2.f, myImage.getSize().y / 2.f);
   }

   void onUpdate() override
   {
      // Clear the screen
      clear(sf::Color(0, 128, 0));

      // Rotate the sprite
      mySprite.rotate(myTimer.interval() * 100.f);

      // Draw the sprite
      draw(mySprite);
   }

   sf::Texture myImage;
   sf::Sprite mySprite;
   QTimer myTimer;
};
