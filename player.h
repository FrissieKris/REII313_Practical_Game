#ifndef PLAYER_H
#define PLAYER_H


#include "sprite.h"
#include "objects.h"



class Player : public Objects
{
public:
    Player();
    struct MoveMent{
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        bool increaseSpeed = false;
    };

    MoveMent movement;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

//    void keyPressEvent(QKeyEvent *e);
//    void keyReleaseEvent(QKeyEvent *e);

    protected:
    void advance(int step) override;

private:

    enum PlayerState {
        Idle,
        MovingLeft,
        MovingRight,
        MovingUp,
        MovingDown,
       // DiagTopRight,
       // DiagTopLeft,
        //DiagBottomRight,
       // DiagBottomLeft

    };

    Sprite player;
    QPointF velocity;
    int frameTick = 0;
    PlayerState state = Idle;
    PlayerState prevstate = Idle;
    float speed = 3.0;
    void setState();
    void updateAnim();
    void collision();



};

#endif // PLAYER_H
