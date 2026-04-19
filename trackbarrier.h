#ifndef TRACKBARRIER_H
#define TRACKBARRIER_H
#include "objects.h"
#include "sprite.h"
#include <QPainter>


class TrackBarrier : public Objects
{
public:
    TrackBarrier(int width, int height);


    //void advance(int step) override;
    bool isSolid() const override { return true; }
   // void onCollision(Objects* other) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    //void applyEffect(class Player *player) override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *) override;


private:
    Sprite barrier;
    int width;
    int height;
    QPixmap tile;

};

#endif // TRACKBARRIER_H
