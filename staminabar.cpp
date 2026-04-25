#include "staminabar.h"


// StaminaBar::StaminaBar(QGraphicsItem* parent) : QGraphicsItem(parent)
// {
//     setZValue(10); //Blykbaar laat dit die ding bo alles teken
// }

// void StaminaBar::setValue(float value)
// {
//     currentValue = qBound(0.0f, value, maxValue);
//     update();
// }

// void StaminaBar::decrease(float amount)
// {
//     setValue(currentValue - amount);
// }

// void StaminaBar::increase(float amount)
// {
//     setValue(currentValue + amount);
// }

// QRectF StaminaBar::boundingRect() const
// {
//     return QRectF(0,0,200,20);
// }

// void StaminaBar::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
// {
//     painter->fillRect(0,0,200,20, Qt::darkGray);


//     float ratio = currentValue / maxValue;
//     int fillWidth = static_cast<int>(200 * ratio);
//     QColor color;
//     if(ratio > 0.6f)
//     {
//         color = Qt::green;
//     }
//         else if (ratio > 0.3f)
//     {
//         color = Qt::yellow;
//     }
//         else
//     {
//         color = Qt::red;
//     }
//     painter->fillRect(0,0,fillWidth, 20, color);

//     painter->setPen(Qt::white);
//     painter->drawRect(0,0,200,20);

//     // Text label
//         painter->setPen(Qt::white);
//         painter->drawText(QRect(5, 0, 190, 20), Qt::AlignVCenter, QString("Stamina: %1%").arg(static_cast<int>(currentValue)));
// }

// float StaminaBar::getValue() const
// {
//     return currentValue;
// }
//=======
 #include <QPainter>
 #include <QDebug>
 StaminaBar::StaminaBar(Player *p)
     :player(p)
 {


    staminaBar = QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar.png");
    staminaFill = staminaBar.copy(0,48, 136, 48);
    borders = staminaBar.copy(0,0, 136, 48);

    border = new QGraphicsPixmapItem(borders);
    fill = new QGraphicsPixmapItem(staminaFill);

    getStaminaLevel(6);
}


void StaminaBar::getStaminaLevel(int stamina)
{
    //qDebug() << "fill:" << fill;
    qDebug() << "border:" << border;

    switch(stamina)
    {
    case 0:
        return fill->setPixmap(staminaFill.copy(0, 0, 30, 48));
        break;

    case 1:
        return fill->setPixmap(staminaFill.copy(0, 0, 46, 48));
        break;
    case 2:
        return fill->setPixmap(staminaFill.copy(0, 0, 62, 48));
        break;
    case 3:
        return fill->setPixmap(staminaFill.copy(0, 0, 78, 48));
        break;
    case 4:
        return fill->setPixmap(staminaFill.copy(0, 0, 94, 48));
        break;
    case 5:
        return fill->setPixmap(staminaFill.copy(0, 0, 110, 48));
        break;
    case 6:
        return fill->setPixmap(staminaFill.copy(0, 0, 136, 48));
        break;
    }

    if (stamina >= 10)
    {

        qDebug() << stamina << "Stamina above";



    }
    else if (stamina >= 5 && stamina < 10)
    {

           qDebug() << stamina << "Stamina between";
     }

     else if (stamina < 5)
     {

           qDebug() << stamina << "Stamina below";
     }


//    int x = currentFrame * frameWidth;
//    int y = frameHeight * frameOffset;
//    return sheet.copy(x, y, frameWidth, frameHeight);
//     return fill->setPixmap(staminaFill.copy(0, 0, 136, 48));

 }
