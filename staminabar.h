#ifndef STAMINABAR_H
#define STAMINABAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>

class staminaBar: public QGraphicsItem
{
public:
    staminaBar(QGraphicsItem* parent = nullptr);
    void setValue(float value); //0 - 100
    void decrease(float amount);
    void increase(float amount);
    QRectF boundingRect() const override;
    void paint(Qpainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

private:
    float currentValue = 100.0f;
    float maxValue = 100.0f;

};

#endif // STAMINABAR_H
