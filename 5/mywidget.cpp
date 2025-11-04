#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QLabel *label = new QLabel("Hello World", this);
    QPushButton *button = new QPushButton("Quit", this);
    label->setGeometry(50, 30, 200, 30);
    button->setGeometry(50, 80, 100, 30);
    connect(button, &QPushButton::clicked, this, &MyWidget::close);
    QLabel *label2 = new QLabel("Additional text", this);
    QPushButton *button2 = new QPushButton("secret button", this);
    label2->setGeometry(50, 130, 200, 30);
    button2->setGeometry(50, 180, 100, 30);
    setFixedSize(300, 250);
    setWindowTitle("oop 5");
}
