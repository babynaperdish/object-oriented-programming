#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QLabel>
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
    void handleFigureClick(const QPoint& position);
private:
    myFigures* figureWidget;
    QPushButton* rectButton;
    QPushButton* triangleButton;
    QPushButton* ellipseButton;
    QPushButton* removeButton;
    QPushButton* clearButton;
    QLabel* statusLabel;
    QPoint lastClickPos;
    bool hasLastClickPos = false;

    void setupUI();
};

#endif // MYWIDGET_H
