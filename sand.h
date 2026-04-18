#ifndef SAND_H
#define SAND_H
#include "objects.h"
#include "sprite.h"


class Sand : public Objects
{
public:
    Sand();


    //void advance(int step) override;
    bool isSolid() const override { return false; }
   // void onCollision(Objects* other) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void applyEffect(class Player *player) override;

private:
    Sprite sand;
};

#endif // SAND_H
