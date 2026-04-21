#include "staminabar.h"
#include <QPainter>
#include <QDebug>
StaminaBar::StaminaBar(Player *p)
    :player(p)
{

    border = new QGraphicsPixmapItem(QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_border.png"));
    fill = new QGraphicsPixmapItem(QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png"));
    //fill = QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png");

    staminaFill = QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png");


   // setPixmap(border);
//    stam = new QLabel();
//    fil = new QLabel();
//    stam->setPixmap(border);
//    stam->show();

 //   setPixmap(staminaFill);

    getStaminaLevel(15);
}


void StaminaBar::getStaminaLevel(int stamina)
{
    qDebug() << "fill:" << fill;
    qDebug() << "border:" << border;
    //15 blocks
    if (stamina >= 10)
    {

        qDebug() << stamina << "Stamina above";

        //return staminaFill.copy(0,0,64,960);


    }
    else if (stamina >= 5 && stamina < 10)
    {

          qDebug() << stamina << "Stamina between";
    }

    else if (stamina < 5)
    {

          qDebug() << stamina << "Stamina below";
    }


//   int x = currentFrame * frameWidth;
//   int y = frameHeight * frameOffset;
//   return sheet.copy(x, y, frameWidth, frameHeight);
    return fill->setPixmap(staminaFill.copy(0, 0, 64, 960));

}
