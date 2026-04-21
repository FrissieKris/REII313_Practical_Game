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
//=======
// #include <QPainter>
// #include <QDebug>
// StaminaBar::StaminaBar(Player *p)
//     :player(p)
// {

//     border = new QGraphicsPixmapItem(QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_border.png"));
//     fill = new QGraphicsPixmapItem(QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png"));
//     //fill = QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png");

//     staminaFill = QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png");


   // setPixmap(border);
//    stam = new QLabel();
//    fil = new QLabel();
//    stam->setPixmap(border);
//    stam->show();

 //   setPixmap(staminaFill);

   // getStaminaLevel(15);
//}


// void StaminaBar::getStaminaLevel(int stamina)
// {
//     qDebug() << "fill:" << fill;
//     qDebug() << "border:" << border;
//     //15 blocks
//     if (stamina >= 10)
//     {

//         qDebug() << stamina << "Stamina above";

//         //return staminaFill.copy(0,0,64,960);


//     }
//     else if (stamina >= 5 && stamina < 10)
//     {

//           qDebug() << stamina << "Stamina between";
//     }

//     else if (stamina < 5)
//     {

//           qDebug() << stamina << "Stamina below";
//     }


// //   int x = currentFrame * frameWidth;
// //   int y = frameHeight * frameOffset;
// //   return sheet.copy(x, y, frameWidth, frameHeight);
//     return fill->setPixmap(staminaFill.copy(0, 0, 64, 960));

// }
