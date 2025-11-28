#include "mywidget.h"


myWidget::myWidget(QWidget* parent)
    : QMainWindow(parent)
{
    setupUI();
    updateStatus();
}

void myWidget::setupUI()
{
    setWindowTitle("Figure Collection Demo");
    setMinimumSize(800, 600);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    figureWidget = new myFigures(this);

    rectButton = new QPushButton("Add Rectangle", this);
    triangleButton = new QPushButton("Add Triangle", this);
    ellipseButton = new QPushButton("Add Ellipse", this);
    removeButton = new QPushButton("Remove Active", this);
    clearButton = new QPushButton("Clear All", this);

    connect(rectButton, &QPushButton::clicked, this, &myWidget::addRectangle);
    connect(triangleButton, &QPushButton::clicked, this, &myWidget::addTriangle);
    connect(ellipseButton, &QPushButton::clicked, this, &myWidget::addEllipse);
    connect(removeButton, &QPushButton::clicked, this, &myWidget::removeFigure);
    connect(clearButton, &QPushButton::clicked, this, &myWidget::clearAll);

    QGroupBox* controlGroup = new QGroupBox("Figure Controls", this);
    QVBoxLayout* controlLayout = new QVBoxLayout(controlGroup);
    controlLayout->addWidget(rectButton);
    controlLayout->addWidget(triangleButton);
    controlLayout->addWidget(ellipseButton);
    controlLayout->addWidget(removeButton);
    controlLayout->addWidget(clearButton);
    controlLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(figureWidget, 1);
    mainLayout->addWidget(controlGroup);

    statusLabel = new QLabel(this);
    statusBar()->addWidget(statusLabel);
}

void myWidget::addRectangle()
{
    QRect bounds(QRandomGenerator::global()->bounded(400),
                QRandomGenerator::global()->bounded(300),
                80, 60);
    figureWidget->addRectangle(bounds);
    updateStatus();
}

void myWidget::addTriangle()
{
    QRect bounds(QRandomGenerator::global()->bounded(400),
                QRandomGenerator::global()->bounded(300),
                80, 60);
    figureWidget->addTriangle(bounds);
    updateStatus();
}

void myWidget::addEllipse()
{
    QRect bounds(QRandomGenerator::global()->bounded(400),
                QRandomGenerator::global()->bounded(300),
                80, 60);
    figureWidget->addEllipse(bounds);
    updateStatus();
}

void myWidget::removeFigure()
{
    figureWidget->removeActiveFigures();
    updateStatus();
}

void myWidget::clearAll()
{
    figureWidget->clearAllFigures();
    updateStatus();
}

void myWidget::updateStatus()
{
    statusLabel->setText(QString("Figures: %1").arg(figureWidget->figureCount()));
}
