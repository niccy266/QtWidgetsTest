#include <QMainWindow>
#include "MyCanvas.cpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MyCanvas* sfmlWidget;
};
