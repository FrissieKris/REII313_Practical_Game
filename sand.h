#ifndef SAND_H
#define SAND_H
#include "objects.h"
#include "sprite.h"
#include <QPainter>


class Sand : public Objects
{
public:
    Sand(int width, int height);


    //void advance(int step) override;
    bool isSolid() const override { return false; }
   // void onCollision(Objects* other) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void applyEffect(class Player *player) override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *,
               QWidget *) override;

private:
    Sprite sand;
    int width;
    int height;
    QPixmap tile;

};

#endif // SAND_H
