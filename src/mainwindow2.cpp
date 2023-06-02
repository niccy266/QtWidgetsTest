#include "mainwindow2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    // Set the window properties (title, size, etc.)
    setWindowTitle("Qt with SFML");
    resize(800, 600);

    // Create an instance of SFMLWidget and add it to the central widget
    sfmlWidget = new MyCanvas(this, QPoint(0, 0), size(), 16 );
    setCentralWidget(sfmlWidget);

    // Set up a QTimer to trigger the SFMLWidget updates
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), sfmlWidget, SLOT(repaint()));
    timer->start(16); // Update roughly every 16 milliseconds (about 60 FPS)
}

MainWindow::~MainWindow()
{
}