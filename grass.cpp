#include "grass.h"

Grass::Grass(int w, int h)
    :grass(":/Sprites/Sprites/Grass/Grass.png", 64, 64, 0, 1), width(w),height(h)
{
    tile = grass.getCurrentFrame();

}

QRectF Grass::boundingRect() const
{
     return QRectF(0, 0, width, height);
}

QPainterPath Grass::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect()); // same size as boundingRect
    return path;

}

void Grass::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    painter->drawTiledPixmap(boundingRect(), tile);
}
