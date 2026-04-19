#ifndef TRACK_H
#define TRACK_H
#include "objects.h"
#include "sprite.h"
#include <QPainter>


class Track : public Objects
{
public:
    Track(int width, int height);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *) override;

private:
    Sprite track;
    int width;
    int height;
    QPixmap tile;

};

#endif // TRACK_H
