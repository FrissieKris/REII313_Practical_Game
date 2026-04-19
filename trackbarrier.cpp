#include "trackbarrier.h"

TrackBarrier::TrackBarrier(int w, int h)
    :barrier(":/Sprites/Sprites/TrackBarrier/TrackBarrier.png", 16, 128, 0, 1), width(w),height(h)
{

    tile = barrier.getCurrentFrame();

}


QRectF TrackBarrier::boundingRect() const
{
     return QRectF(0, 0, width, height);
}

QPainterPath TrackBarrier::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect()); // same size as boundingRect
    return path;
}

void TrackBarrier::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    painter->drawTiledPixmap(boundingRect(), tile);
}
