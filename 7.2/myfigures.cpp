#include "myfigures.h"


myFigures::myFigures(QWidget* parent)
    : QWidget(parent), fActiveFigure(nullptr)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    fScene = new QGraphicsScene(this);
    connect(fScene, &QGraphicsScene::selectionChanged, this, &myFigures::updateFigureColors);
    fView = new QGraphicsView(fScene, this);
    fScene->setSceneRect(0, 0, 800, 600);

     layout->addWidget(fView);
     setLayout(layout);
}

void myFigures::addRectangle(const QRectF& bounds)
{
    QColor lightPink(255, 182, 193);
    QColor activePink(255, 105, 180);
    QColor purple(205, 25, 255);
    auto* rect = new QGraphicsRectItem(bounds);
    rect->setBrush(lightPink);
    rect->setPen(purple);
    fFigures.append(rect);
    fScene->addItem(rect);
    rect->setVisible(true);
    rect->setFlag(QGraphicsItem::ItemIsMovable, true);
    rect->setFlag(QGraphicsItem::ItemIsSelectable, true);
    rect->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    qDebug() << "Rectangle added. Total figures:" << fFigures.size();
    qDebug() << "Bounds:" << bounds;

    update();
}

void myFigures::addTriangle(const QRect& bounds)
{
    QPolygonF pTriangle;
       pTriangle << QPointF(bounds.left(), bounds.bottom())
                << QPointF(bounds.right(), bounds.bottom())
                << QPointF(bounds.center().x(), bounds.top());
    QColor lightPink(255, 182, 193);
    QColor activePink(255, 105, 180);
    QColor purple(205, 25, 255);
    auto* triangle = new QGraphicsPolygonItem(pTriangle);
    triangle->setBrush(lightPink);
    triangle->setPen(purple);
    fScene->addItem(triangle);
    fFigures.append(triangle);
    triangle->setVisible(true);
    triangle->setFlag(QGraphicsItem::ItemIsMovable, true);
    triangle->setFlag(QGraphicsItem::ItemIsSelectable, true);
    triangle->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    qDebug() << "Triangle added. Total figures:" << fFigures.size();
    qDebug() << "Bounds:" << bounds;

    update();
}

void myFigures::addEllipse(const QRect& bounds)
{
    QColor lightPink(255, 182, 193);
    QColor activePink(255, 105, 180);
    QColor purple(205, 25, 255);
    auto* ellipse = new QGraphicsEllipseItem(bounds);
    ellipse->setBrush(lightPink);
    ellipse->setPen(purple);
    fFigures.append(ellipse);
    fScene->addItem(ellipse);
    ellipse->setVisible(true);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable, true);
    ellipse->setFlag(QGraphicsItem::ItemIsSelectable, true);
    ellipse->setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    qDebug() << "Ellipse added. Total figures:" << fFigures.size();
    qDebug() << "Bounds:" << bounds;

    update();
}

void myFigures::updateFigureColors()
{
 QColor lightPink(255, 182, 193);
 QColor activePink(255, 105, 180);

 for (QGraphicsItem* item : fFigures) {
     if (auto* rectItem = dynamic_cast<QGraphicsRectItem*>(item)) {
         rectItem->setBrush(lightPink);
     } else if (auto* polyItem = dynamic_cast<QGraphicsPolygonItem*>(item)) {
         polyItem->setBrush(lightPink);
     } else if (auto* ellipseItem = dynamic_cast<QGraphicsEllipseItem*>(item)) {
         ellipseItem->setBrush(lightPink);
     }
 }

 QList<QGraphicsItem*> selectedItems = fScene->selectedItems();
 for (QGraphicsItem* item : selectedItems) {
     if (auto* rectItem = dynamic_cast<QGraphicsRectItem*>(item)) {
         rectItem->setBrush(activePink);
     } else if (auto* polyItem = dynamic_cast<QGraphicsPolygonItem*>(item)) {
         polyItem->setBrush(activePink);
     } else if (auto* ellipseItem = dynamic_cast<QGraphicsEllipseItem*>(item)) {
         ellipseItem->setBrush(activePink);
     }
 }
}

bool myFigures::event(QEvent* event)
{
    if (event->type() == QEvent::LayoutRequest ||
        event->type() == QEvent::UpdateRequest) {
        updateFigureColors();
    }
    return QWidget::event(event);
}

void myFigures::removeActiveFigures()
{
    QList<QGraphicsItem*> activeItems = fScene->selectedItems();

    if (activeItems.isEmpty()) {
        return;
    }

    qDebug() << "Removing" << activeItems.size() << "selected items";

    for (QGraphicsItem* item : activeItems) {
        fScene->removeItem(item);
        fFigures.removeAll(item);
        delete item;
    }

    update();
    qDebug() << "Active figures removed. Total figures:" << fFigures.size();
}

void myFigures::clearAllFigures()
{
    fScene->clear();
    fFigures.clear();
    fActiveFigure = nullptr;
    qDebug() << "All figures cleared";
    update();
}



