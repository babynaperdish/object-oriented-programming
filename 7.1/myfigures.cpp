#include "myfigures.h"


myFigures::myFigures(QWidget* parent)
    : QWidget(parent), fActiveFigure(nullptr), fIsDragging(false)
{
    setMinimumSize(600, 400);
    setMouseTracking(true);
}

void myFigures::addRectangle(const QRect& bounds)
{
    auto* rect = new rectangleFigure(bounds, this);
    fFigures.append(rect);
    setActiveFigure(rect);

    qDebug() << "Rectangle added. Total figures:" << fFigures.size();
    qDebug() << "Bounds:" << bounds;

    update();
}

void myFigures::addTriangle(const QRect& bounds)
{
    auto* triangle = new triangleFigure(bounds, this);
    fFigures.append(triangle);
    setActiveFigure(triangle);

    qDebug() << "Triangle added. Total figures:" << fFigures.size();
    qDebug() << "Bounds:" << bounds;

    update();
}

void myFigures::addEllipse(const QRect& bounds)
{
    auto* ellipse = new ellipseFigure(bounds, this);
    fFigures.append(ellipse);
    setActiveFigure(ellipse);

    qDebug() << "Ellipse added. Total figures:" << fFigures.size();
    qDebug() << "Bounds:" << bounds;

    update();
}

void myFigures::removeActiveFigure()
{
    if (fActiveFigure) {
        fFigures.removeAll(fActiveFigure);
        delete fActiveFigure;
        fActiveFigure = nullptr;
        update();
        qDebug() << "Active figure removed. Total figures:" << fFigures.size();
    }
}

void myFigures::clearAllFigures()
{
    qDeleteAll(fFigures);
    fFigures.clear();
    fActiveFigure = nullptr;
    update();
}

void myFigures::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(rect(), Qt::white);

    for (int i = 0; i < fFigures.size(); ++i) {
        qDebug() << "Drawing figure" << i << "with bounds:" << fFigures[i]->bounds();
        fFigures[i]->draw(&painter);
    }
}

void myFigures::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        figure* clickedFigure = nullptr;
        for (int i = fFigures.size() - 1; i >= 0; --i) {
            if (fFigures[i]->contains(event->pos())) {
                clickedFigure = fFigures[i];
                break;
            }
        }

        setActiveFigure(clickedFigure);

        if (fActiveFigure) {
            fIsDragging = true;
            fLastMousePos = event->pos();
            bringToFront(fActiveFigure);
        } else{
            emit figureClicked(event->pos());
        }

        update();
    }
}

void myFigures::mouseMoveEvent(QMouseEvent* event)
{
    if (fIsDragging && fActiveFigure) {
        QPoint offset = event->pos() - fLastMousePos;
        fActiveFigure->moveBy(offset);
        fLastMousePos = event->pos();
        update();
    }
}

void myFigures::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    fIsDragging = false;
}

void myFigures::setActiveFigure(figure* figure)
{

    for (int i = 0; i < fFigures.count(); ++i) {
            fFigures.at(i)->setActive(false);
     }

    fActiveFigure = figure;
    if (fActiveFigure) {
        fActiveFigure->setActive(true);
    }
}

void myFigures::bringToFront(figure* figure)
{
    fFigures.removeAll(figure);
    fFigures.append(figure);
}
//    mainLayout = new QVBoxLayout(this);

//    QPushButton *addRectangleButton = new QPushButton("Add a rectangle");
//    QPushButton *addTriangleButton = new QPushButton("Add a triangle");
//    QPushButton *addEllipseButton = new QPushButton("Add an ellipse");

//    mainLayout->addWidget(addRectangleButton);
//    mainLayout->addWidget(addTriangleButton);
//    mainLayout->addWidget(addEllipseButton);

//    connect(addRectangleButton, &QPushButton::clicked, this, &myFigures::addRectangle);
//    connect(addTriangleButton, &QPushButton::clicked, this, &myFigures::addRectangle);
//    connect(addEllipseButton, &QPushButton::clicked, this, &myFigures::addRectangle);

//    //connect()

//    resize(1000, 300);
//    this->setStyleSheet("background-color: #f09cc4;");

//вместо addRectangle перегрузка paintEvent<Rectangle>?
//или и то и то? скорее всего это для учета фигур
//отдельный контейнер фигур?
//mouse press - activateFigure -> //move to foreground
//mouse move - moveFigure ->      //using QCursor::pos()
//mouse release                   // exit from both

//void myFigures::addRectangle(){
//    static int rectCount = 0;
//    rectCount++;
//    QRect *rectangle = new QRect;
//    rectangle->set

//    widgetsLayout->addWidget(labelwidget);
//}


