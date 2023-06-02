#include <SFML/Graphics.hpp>
#include <Qwidget>
#include<iostream>

class graphicspane : public QWidget, public sf::RenderWindow
{
private:
   /* data */
public:
   graphicspane(/* args */);
   ~graphicspane();
};

graphicspane::graphicspane(/* args */)
{
}

graphicspane::~graphicspane()
{
}
