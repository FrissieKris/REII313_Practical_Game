#include "staminabar.h"

StaminaBar::StaminaBar(QGraphicsItem* parent) : QGraphicsItem(parent)
{
    setZValue(10); //Blykbaar laat dit die ding bo alles teken
}

void StaminaBar::setValue(float value)
{
    currentValue = qBound(0.0f, value, maxValue);
    update();
}

void StaminaBar::decrease(float amount)
{
    setValue(currentValue - amount);
}

void StaminaBar::increase(float amount)
{
    setValue(currentValue + amount);
}

QRectF StaminaBar::boundingRect() const
{
    return QRectF(0,0,200,20);
}

void StaminaBar::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->fillRect(0,0,200,20, Qt::darkGray);


    float ratio = currentValue / maxValue;
    int fillWidth = static_cast<int>(200 * ratio);
    QColor color;
    if(ratio > 0.6f)
    {
        color = Qt::green;
    }
        else if (ratio > 0.3f)
    {
        color = Qt::yellow;
    }
        else
    {
        color = Qt::red;
    }
    painter->fillRect(0,0,fillWidth, 20, color);

    painter->setPen(Qt::white);
    painter->drawRect(0,0,200,20);

    // Text label
        painter->setPen(Qt::white);
        painter->drawText(QRect(5, 0, 190, 20), Qt::AlignVCenter, QString("Stamina: %1%").arg(static_cast<int>(currentValue)));
}

float StaminaBar::getValue() const
{
    return currentValue;
}
