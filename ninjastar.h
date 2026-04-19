#ifndef NINJASTAR_H
#define NINJASTAR_H
#include "objects.h"
#include "sprite.h"

class Player;

class NinjaStar : public Objects
{
public:
    NinjaStar();
    bool isSolid() const override { return false; }
    QRectF boundingRect() const override;
    void applyEffect(class Player *player) override;
    void advance(int step) override ;;


private:
    Sprite ninjaStar;
    //QTimer *coolDown;

    enum NinjaStarState{
        Unused,
        Collected
    };

     NinjaStarState state;


};

#endif // NINJASTAR_H
