#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "QSfmlWidget.h"
#include <iostream>

class MyCanvas : public QSfmlWidget
{

public:
   MyCanvas(QWidget *parent = nullptr);

   /// @brief Code to run when widget is created
   void onInit() override;
   void onUpdate() override;

private:
   sf::RectangleShape m_rect;
   sf::Sprite mySprite;
};
#endif // MYCANVAS_H

