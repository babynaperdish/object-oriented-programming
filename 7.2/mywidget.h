#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QStatusBar>
#include <QRandomGenerator>
#include <QMainWindow>
#include "myfigures.h"


class myWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = nullptr);
    QVBoxLayout *mainLayout;

private slots:
    void addRectangle();
    void addTriangle();
    void addEllipse();
    void removeFigure();
    void clearAll();
    void updateStatus();

private:
    myFigures* figureWidget;
    QPushButton* rectButton;
    QPushButton* triangleButton;
    QPushButton* ellipseButton;
    QPushButton* removeButton;
    QPushButton* clearButton;
    QLabel* statusLabel;

    void setupUI();
};

#endif // MYWIDGET_H
