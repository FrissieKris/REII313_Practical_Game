#include "staminabar.h"
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
    //15 blocks
    switch(stamina)
    {
    case 1:
        return fill->setPixmap(staminaFill.copy(0, 0, 26, 48));
        break;
    case 2:
        return fill->setPixmap(staminaFill.copy(0, 0, 52, 48));
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

//    if (stamina >= 10)
//    {

//        qDebug() << stamina << "Stamina above";



//    }
//    else if (stamina >= 5 && stamina < 10)
//    {

//          qDebug() << stamina << "Stamina between";
//    }

//    else if (stamina < 5)
//    {

//          qDebug() << stamina << "Stamina below";
//    }


//   int x = currentFrame * frameWidth;
//   int y = frameHeight * frameOffset;
//   return sheet.copy(x, y, frameWidth, frameHeight);
   // return fill->setPixmap(staminaFill.copy(0, 0, 136, 48));

}
