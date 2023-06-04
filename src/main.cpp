#include <QApplication>
#include <QFrame>
#include "MyCanvas.h"

int main(int argc, char **argv)
{
    QApplication App(argc, argv);

    // Create the main frame
    QFrame *MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    MainFrame->resize(400, 400);
    MainFrame->show();

    // Create a SFML view inside the main frame
    MyCanvas *SFMLView = new MyCanvas(MainFrame);
    SFMLView->show();

    /* sf::Texture texture;
    if (!texture.loadFromFile("passion_flower.jpg"))
    {
        std::cout << "Could not load texture" << std::endl;
        return 0;
    }
        std::cout << "loaded texture successfully from main" << std::endl;
 */
    return App.exec();
}
