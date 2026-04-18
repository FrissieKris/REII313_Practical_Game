#ifndef POWERUPS_H
#define POWERUPS_H
#include "objects.h"
#include "sprite.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>

class Powerups : public Objects
{
public:
    Powerups();
    bool isSolid() const override { return false; }
    //void onCollision(Objects* other) override;
    QRectF boundingRect() const override;
    void applyEffect(class Player *player) override;
    void advance(int step) override {}

private:
    Sprite powerUp;
    QTimer *coolDown;
private slots:
    void coolDownStop();

};

#endif // POWERUPS_H
