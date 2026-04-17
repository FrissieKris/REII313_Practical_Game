#include "powerups.h"
#include <QDebug>


Powerups::Powerups()
    :powerUp(":/sprites/Needle/pixil-frame-0.png", 128, 128, 0, 1)
{

    setPixmap(powerUp.getCurrentFrame());
}


void Powerups::onCollision(Objects *other)
{
    Player* player = dynamic_cast<Player*>(other);

       if (player)
       {

           qDebug() << "Player takes damage!";
           player->movement.increaseSpeed = true;
           QTimer::singleShot(5000, [player]() {
               player->movement.increaseSpeed = false;
           });

           scene()->removeItem(this);
           delete this;

       }

}

QRectF Powerups::boundingRect() const
{
    return QRectF(0, 0, 128, 32);
}

