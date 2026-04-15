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
        MovingDown

    };


    void setState(PlayerState newState);

//    void keyPressEvent(QKeyEvent *e);
//    void keyReleaseEvent(QKeyEvent *e);
    void setMovingLeft(bool enabled);
    void setMovingRight(bool enabled);
    void setMovingUp(bool enabled);
    void setMovingDown(bool enabled);

    protected:
    void advance(int step);

private:
    Sprite sprite;
    QPointF velocity;
    int frameTick = 0;
    PlayerState state = Idle;
    float speed = 3.0;



};

#endif // PLAYER_H
