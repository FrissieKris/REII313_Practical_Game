#include "sand.h"
#include "player.h"
#include <QTimer>

Sand::Sand(int w, int h)
    :sand(":/Sprites/Sprites/Sand/Sand.png", 64, 64, 0, 1), width(w),height(h)
{

    tile = sand.getCurrentFrame();

}


void Sand::applyEffect(Player* player)
{
    player->movement.decreaseSpeed = true;
    player->speedTimer.start(500);

}


QRectF Sand::boundingRect() const
{
     return QRectF(0, 0, width, height);
}

QPainterPath Sand::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect()); // same size as boundingRect
    return path;
}

void Sand::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    painter->drawTiledPixmap(boundingRect(), tile);
}

