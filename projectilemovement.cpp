#include "projectilemovement.h"

ProjectileMovement::ProjectileMovement(QPointF start, QPointF vel)
    : velocity(vel), projectileState(ProjectileState::Flying), ninjastar(":/Sprites/Sprites/NinjaStar/NinjaStar-Sheet.png", 64, 64, 0, 4)
{
    setPos(start);
    setPixmap(ninjastar.getCurrentFrame());
}

void ProjectileMovement::advance(int step)
{

    if (!step) return;
    setPos(pos() + velocity);
    for (auto item : collidingItems())
    {
        Objects* obj = dynamic_cast<Objects*>(item);

        if (!obj) continue;
        if (obj->isSolid())
        {
            projectileState = ProjectileState::Hit;

            scene()->removeItem(this);
            deleteLater();
            return;
        }


    }
    ninjastar.updateFrame();
    setPixmap(ninjastar.getCurrentFrame());



}
