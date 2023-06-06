#ifndef QSFMLWIDGET_H
#define QSFMLWIDGET_H

#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtWidgets/QWidget>
#include "SFML/Graphics.hpp"

class QSfmlWidget : public QWidget, public sf::RenderWindow
{
    Q_OBJECT

public:
    explicit QSfmlWidget(QWidget *parent = nullptr, unsigned int frameTime = 0);
    virtual QPaintEngine * paintEngine() const override;
    virtual void showEvent(QShowEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void onInit();
    virtual void onUpdate();
    int frameTime;

private:
    bool m_initialized;
    QTimer m_timer;
};

#endif // QSFMLWIDGET_H