#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

#include "sprite.h"



class Player : public QGraphicsPixmapItem
{
public:
    Player();

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

    struct MoveMent{
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
    };

    MoveMent movement;

    void setState(PlayerState newState);

//    void keyPressEvent(QKeyEvent *e);
//    void keyReleaseEvent(QKeyEvent *e);

    protected:
    void advance(int step);

private:
    Sprite sprite;
    QPointF velocity;
    int frameTick = 0;
    PlayerState state = Idle;
    PlayerState prevstate = Idle;
    float speed = 3.0;





};

#endif // PLAYER_H
