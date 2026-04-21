#include "staminabar.h"
#include <QPainter>

StaminaBar::StaminaBar(Player *p)
    :player(p)
{

    border = new QGraphicsPixmapItem(QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_border.png"));
    fill = new QGraphicsPixmapItem(QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png"));
    //fill = QPixmap(":/Sprites/Sprites/StaminaBar/Staminabar_fill-Sheet.png");



   // setPixmap(border);
//    stam = new QLabel();
//    fil = new QLabel();
//    stam->setPixmap(border);
//    stam->show();

 //   setPixmap(staminaFill);

    getStaminaLevel(10);
}


QPixmap StaminaBar::getStaminaLevel(int stamina)
{
    //15 blocks
    if (stamina >= 10)
    {

        return staminaFill.copy(0,0,64,960);


    }
    else if (stamina >= 5 && stamina < 10)
    {

    }

    else if (stamina < 5)
    {

    }


//   int x = currentFrame * frameWidth;
//   int y = frameHeight * frameOffset;
//   return sheet.copy(x, y, frameWidth, frameHeight);
    return staminaFill.copy(10,10,10,10);

}
