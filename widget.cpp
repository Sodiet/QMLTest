#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setWindowTitle("Test");
    setMinimumSize(500, 300);

    quickView = new QQuickView();
    quickViewContainer = Widget::createWindowContainer(quickView);

    grid = new QGridLayout(this);

    frstSpinBox = new QSpinBox(this);
    scndSpinBox = new QSpinBox(this);
    thrdSpinBox = new QSpinBox(this);
    frthSpinBox = new QSpinBox(this);

    fsbLabel = new QLabel("X", this);
    ssbLabel = new QLabel("Y", this);
    tsbLabel = new QLabel("Width", this);
    frsbLabel = new QLabel("Height", this);

    frstLineEdit = new QLineEdit(this);
    scndLineEdit = new QLineEdit(this);

    fleLabel = new QLabel("Mouse X", this);
    sleLabel = new QLabel("Mouse Y", this);

    quickView->rootContext()->setContextProperty("widget", this);
    quickView->setSource(QUrl::fromLocalFile("E:/Test/Rectangle.qml"));

    rect = qobject_cast<QQuickItem*>(quickView->rootObject());

    QObject::connect(frstSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSetX(int)));
    QObject::connect(scndSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSetY(int)));
    QObject::connect(thrdSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSetWidth(int)));
    QObject::connect(frthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onSetHeight(int)));
    QObject::connect(rect, SIGNAL(testSignal(qreal, qreal)), this, SLOT(onTestSignal(qreal, qreal)));

    grid->addWidget(fsbLabel, 2, 1, 1, 1, Qt::AlignRight);
    grid->addWidget(ssbLabel, 2, 3, 1, 1, Qt::AlignRight);
    grid->addWidget(tsbLabel, 3, 1, 1, 1, Qt::AlignRight);
    grid->addWidget(frsbLabel, 3, 3, 1, 1, Qt::AlignRight);

    grid->addWidget(frstSpinBox, 2, 2, 1, 1, Qt::AlignLeft);
    grid->addWidget(scndSpinBox, 2, 4, 1, 1, Qt::AlignLeft);
    grid->addWidget(thrdSpinBox, 3, 2, 1, 1, Qt::AlignLeft);
    grid->addWidget(frthSpinBox, 3, 4, 1, 1, Qt::AlignLeft);

    grid->addWidget(fleLabel, 4, 1, 1, 1, Qt::AlignRight);
    grid->addWidget(sleLabel, 5, 1, 1, 1, Qt::AlignRight);

    grid->addWidget(frstLineEdit, 4, 2, 1, 2, Qt::AlignLeft);
    grid->addWidget(scndLineEdit, 5, 2, 1, 2, Qt::AlignLeft);

    grid->addWidget(quickViewContainer, 2, 7, 5, 5);
}

Widget::~Widget()
{
    delete quickView;
}

void Widget::onSetX(int value)
{
    emit this->setX(value);
}

void Widget::onSetY(int value)
{
    emit this->setY(value);
}

void Widget::onSetHeight(int value)
{
    emit this->setHeight(value);
}

void Widget::onSetWidth(int value)
{
    emit this->setWidth(value);
}

void Widget::onTestSignal(const qreal x, const qreal y)
{
    this->frstLineEdit->setText(QString::number(x));
    this->scndLineEdit->setText(QString::number(y));
}
