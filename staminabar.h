#ifndef STAMINABAR_H
#define STAMINABAR_H

#include <QGraphicsItem>
#include <QPainter>

class StaminaBar: public QGraphicsItem
{
public:
    explicit StaminaBar(QGraphicsItem* parent = nullptr);
    void setValue(float value); //0 - 100
    void decrease(float amount);
    void increase(float amount);
    float getValue() const;

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;


private:
    float currentValue = 100.0f;
    float maxValue = 100.0f;


};

#endif // STAMINABAR_H
