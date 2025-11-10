#include "mywidgets.h"


MyWidgets::MyWidgets(QWidget *parent): QWidget (parent){
    mainLayout = new QVBoxLayout(this);

    QPushButton *addButton = new QPushButton("Add a widget");
    QPushButton *connectButton = new QPushButton("Connect all");

    widgetsLayout = new QVBoxLayout();

    mainLayout->addWidget(addButton);
    mainLayout->addWidget(connectButton);
    mainLayout->addLayout(widgetsLayout);

    connect(addButton, &QPushButton::clicked, this, &MyWidgets::WidgetsMenu);
    connect(connectButton, &QPushButton::clicked, this, &MyWidgets::connectAll);

    resize(500, 100);

    this->setStyleSheet("background-color: #f09cc4;");
}

void MyWidgets::WidgetsMenu(){
    mainLayout->itemAt(0)->widget()->hide();

    menuLayout = new QHBoxLayout();

    QPushButton *labelBtn = new QPushButton("Create a label");
    QPushButton *sliderBtn = new QPushButton("Create a slider");
    QPushButton *scrollBtn = new QPushButton("Create a scrollbar");
    QPushButton *spinBtn = new QPushButton("Create a spin box");
    QPushButton *deleteBtn = new QPushButton("Delete a random widget");

    labelBtn->setObjectName("label button");
    sliderBtn->setObjectName("slider button");
    scrollBtn->setObjectName("scroll button");
    spinBtn->setObjectName("spin button");
    deleteBtn->setObjectName("delete button");

    menuLayout->addWidget(labelBtn);
    menuLayout->addWidget(sliderBtn);
    menuLayout->addWidget(scrollBtn);
    menuLayout->addWidget(spinBtn);
    menuLayout->addWidget(deleteBtn);

    mainLayout->insertLayout(0, menuLayout);

    connect(labelBtn, &QPushButton::clicked, this, &MyWidgets::addLabel);
    connect(sliderBtn, &QPushButton::clicked, this, &MyWidgets::addSlider);
    connect(scrollBtn, &QPushButton::clicked, this, &MyWidgets::addScroll);
    connect(spinBtn, &QPushButton::clicked, this, &MyWidgets::addSpin);
    connect(deleteBtn, &QPushButton::clicked, this, &MyWidgets::deleteRandom);
}

void MyWidgets::addLabel(){
    static int labelCount = 0;
    labelCount++;
    QLabel *labelwidget = new QLabel("hi");
    labelwidget->setObjectName(QString("label_%1").arg(labelCount));

    widgetsLayout->addWidget(labelwidget);
}

void MyWidgets::addSlider(){
    static int sliderCount = 0;
    sliderCount++;
    QSlider *sliderwidget = new QSlider(Qt::Horizontal);
    sliderwidget->setObjectName(QString("slider_%1").arg(sliderCount));

    widgetsLayout->addWidget(sliderwidget);
}

void MyWidgets::addScroll(){
    static int scrollCount = 0;
    scrollCount++;
    QScrollBar *scrollwidget = new QScrollBar(Qt::Horizontal);
    scrollwidget->setObjectName(QString("scrollwidget_%1").arg(scrollCount));

    widgetsLayout->addWidget(scrollwidget);
}

void MyWidgets::addSpin(){
    static int spinCount = 0;
    spinCount++;
    QSpinBox *spinwidget = new QSpinBox();
    spinwidget->setObjectName(QString("spinwidget_%1").arg(spinCount));

    widgetsLayout->addWidget(spinwidget);
}

void MyWidgets::connectAll(){
    static int connectionCount = 0;
    connectionCount++;

    qDebug() << "Calling connectAll() №" << connectionCount;

    QList<QWidget*> widgets;
    for (int i = 0; i < widgetsLayout->count(); i++){
        QWidget* widget = widgetsLayout->itemAt(i)->widget();
        widgets.append(widget);
//        if (widget)
//            widget->disconnect();
    }

    for (int i = 0; i < widgets.size(); i++){
        for (int j = i + 1; j < widgets.size(); j++){

            const char* type1 = widgets[i]->metaObject()->className();
            const char* type2 = widgets[j]->metaObject()->className();

            if ((strcmp(type1, "QLabel") != 0) && (strcmp(type2, "QLabel") != 0)){
                connect(widgets[i], SIGNAL(valueChanged(int)), widgets[j], SLOT(setValue(int)), Qt::UniqueConnection); //fixme
                connect(widgets[j], SIGNAL(valueChanged(int)), widgets[i], SLOT(setValue(int)), Qt::UniqueConnection);
            }
            else if ((strcmp(type1, "QLabel") != 0) && (strcmp(type2, "QLabel") == 0)){
                connect(widgets[i], SIGNAL(valueChanged(int)), widgets[j], SLOT(setNum(int)), Qt::UniqueConnection);
            }
            else if ((strcmp(type1, "QLabel") == 0) && (strcmp(type2, "QLabel") != 0)){
                connect(widgets[j], SIGNAL(valueChanged(int)), widgets[i], SLOT(setNum(int)), Qt::UniqueConnection);
            }
        }
    }

    for (QWidget* widget : widgets){
        widget->dumpObjectInfo();
    }

    if (!widgets.isEmpty()){
        int general_value = 0;

        for (QWidget* widget : widgets){
            const char* type = widget->metaObject()->className();
            if (strcmp(type, "QLabel") != 0){
                QVariant value = widget->property("value");
                if (value.isValid()){
                    general_value = value.toInt();
                    break;
                }
            }
        }

        for (QWidget* widget: widgets){
            const char* type = widget->metaObject()->className();

            if (strcmp(type, "QLabel") == 0){
                QMetaObject::invokeMethod(widget, "setNum", Q_ARG(int, general_value));
            }
            else{
                widget->setProperty("value", general_value);
            }
        }
    }
}

void MyWidgets::deleteRandom(){
    int deleteIndex;
    if (widgetsLayout->count() > 0) {
        deleteIndex = rand() % widgetsLayout->count();
        widgetsLayout->itemAt(deleteIndex)->widget()->disconnect();
        widgetsLayout->itemAt(deleteIndex)->widget()->hide();
    }
    else {
        qDebug() << "Layout is empty, nothing to delete";
        return;
    }

}
