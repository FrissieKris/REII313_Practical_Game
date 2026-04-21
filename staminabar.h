#ifndef STAMINABAR_H
#define STAMINABAR_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>

class Player;

class StaminaBar: public QGraphicsPixmapItem
{
public:
    StaminaBar(Player *player);
   QGraphicsPixmapItem *border;
 QGraphicsPixmapItem *fill;
    void updateBar();
    QPixmap getStaminaLevel(int stamina);

private:
    Player *player;
    QPixmap staminaFill;
    QPixmap borders;




};

#endif // STAMINABAR_H
