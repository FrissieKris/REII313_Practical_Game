#include "sand.h"
#include "player.h"
#include <QTimer>

Sand::Sand()
    :sand(":/Sprites/Sprites/Sand/Sand.png", 32, 32, 0, 1)
{

    setPixmap(sand.getCurrentFrame());

}


void Sand::applyEffect(Player* player)
{
    player->movement.decreaseSpeed = true;
    player->speedTimer.start(500);

}


QRectF Sand::boundingRect() const
{
     return QRectF(0, 0, 32, 32);
}

QPainterPath Sand::shape() const
{
    QPainterPath path;
    path.addRect(0, 0,  32, 32); // same size as boundingRect
    return path;
}
