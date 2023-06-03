#include <QApplication>
#include <QFrame>
#include "MyCanvas.h"

int main(int argc, char **argv)
{
    QApplication App(argc, argv);

    // Create the main frame
    QFrame* MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    MainFrame->resize(400, 400);
    MainFrame->show();

    // Create a SFML view inside the main frame
    MyCanvas* SFMLView = new MyCanvas(MainFrame);
    SFMLView->show();

    return App.exec();
}
