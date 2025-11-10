#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QScrollBar>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QList>
#include <cstdlib>

class MyWidgets : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QVBoxLayout *widgetsLayout;
    QHBoxLayout *menuLayout;

public:
    MyWidgets(QWidget *parent = nullptr);
public slots:
    void connectAll();
    void WidgetsMenu();

    void addLabel();
    void addSlider();
    void addScroll();
    void addSpin();

    void deleteRandom();
};

#endif // MYWIDGET_H
