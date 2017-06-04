#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QQuickView>
#include <QSpinBox>
#include <QQmlContext>
#include <QLineEdit>
#include <QQuickItem>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
signals:
    void setX(int value);
    void setY(int value);
    void setHeight(int value);
    void setWidth(int value);

public slots:
    void onSetX(int value);
    void onSetY(int value);
    void onSetHeight(int value);
    void onSetWidth(int value);
    void onTestSignal(const qreal, const qreal);

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QQuickView * quickView;
    QWidget * quickViewContainer;

    QGridLayout * grid;

    QSpinBox * frstSpinBox;
    QSpinBox * scndSpinBox;
    QSpinBox * thrdSpinBox;
    QSpinBox * frthSpinBox;

    QLabel * fsbLabel;
    QLabel * ssbLabel;
    QLabel * tsbLabel;
    QLabel * frsbLabel;

    QLineEdit * frstLineEdit;
    QLineEdit * scndLineEdit;

    QLabel * fleLabel;
    QLabel * sleLabel;

    QQuickItem * rect;
};

#endif // WIDGET_H
