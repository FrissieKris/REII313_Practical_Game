#include "track.h"

Track::Track(int w, int h)
:track(":/Sprites/Sprites/Track/Track.png", 1920, 1080, 0, 1), width(w),height(h)
{
    tile = track.getCurrentFrame();

}

QRectF Track::boundingRect() const
{
     return QRectF(0, 0, width, height);
}

QPainterPath Track::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect()); // same size as boundingRect
    return path;
}

void Track::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    painter->drawTiledPixmap(boundingRect(), tile);
}
