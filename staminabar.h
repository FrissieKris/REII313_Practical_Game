#ifndef STAMINABAR_H
#define STAMINABAR_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>

class Player;

class StaminaBar
{
public:
    StaminaBar(Player *player);

   QGraphicsPixmapItem *border;
   QGraphicsPixmapItem *fill;
    void updateBar();
    void getStaminaLevel(int stamina);

private:
    Player *player;
    QPixmap staminaFill;
    QPixmap borders;
    QPixmap staminaBar;


>>>>>>>>> Temporary merge branch 2


};

#endif // STAMINABAR_H
