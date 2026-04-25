#ifndef ENEMY_H
#define ENEMY_H
#include "sprite.h"
#include "objects.h"
#include <QPainter>

class Enemy : public Objects
{
public:
    Enemy();
    void applyEffect(class Player *player) override;
    void advance(int step) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
    Sprite enemy;
    //QTimer *coolDown;

    QPointF velocity;

    enum enemyState{
        Idle,
        Tracking,
        Attacking
    };
    enemyState state;
};

#endif // ENEMY_H
