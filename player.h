#ifndef PLAYER_H
#define PLAYER_H

//#include <ninjastar.h>
#include "sprite.h"
#include "objects.h"
#include "staminabar.h"
#include "timingbar.h"
#include <QTimer>
#include "staminabar.h"


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
        bool decreaseSpeed = false;
    };

    StaminaBar* staminaBar = nullptr;
    TimingBar* timingBar = nullptr;

    float baseSpeed = 5.0f; //change value stuffs
    float getCurrentSpeedFactor() const;
    bool isThrowing = false;

    int currentStamina = 15;


    bool itemPickedUp;
    void throwShuriken(QPointF target);
    int maxStamina = 15;

    QTimer speedTimer;
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
        MovingDown

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
