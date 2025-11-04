#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = nullptr);
};

#endif // MYWIDGET_H
