#ifndef PROJECTILEMOVEMENT_H
#define PROJECTILEMOVEMENT_H
#include "objects.h"
#include <QPointF>
#include "sprite.h"


class ProjectileMovement : public Objects
{

public:
    ProjectileMovement(QPointF start, QPointF vel);

    Objects* owner = nullptr;

    void advance(int step) override;



private:
    QPointF velocity;
    enum class ProjectileState
    {
        Flying,
        Hit,
        Idle,
    };
    ProjectileState projectileState;
    Sprite ninjastar;
};

#endif // PROJECTILEMOVEMENT_H
