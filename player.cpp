#include "player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <cmath>
#include <projectilemovement.h>

Player::Player()
    : player(":/Sprites/Sprites/Character/Character.png", 128, 128, 0, 1),
        velocity(0, 0)
  {
      setPixmap(player.getCurrentFrame());
      qDebug() << player.getCurrentFrame().isNull();

      speedTimer.setSingleShot(true);

      connect(&speedTimer, &QTimer::timeout, this, [this]() {
          if (movement.increaseSpeed == true )
            movement.increaseSpeed = false;
          if (movement.decreaseSpeed == true)
              movement.decreaseSpeed = false;

      });
      connect(&coolDownTimer, &QTimer::timeout, this, [this]() {
          currentStamina += 1;
          if (currentStamina > maxStamina)
              currentStamina = maxStamina;

      });
      coolDownTimer.start(1000);

  }


//Player updates
void Player::advance(int step)

{
    //Skip first one, as there are two checks done one at 0 and another at 1; 1 updates all
    if (!step) return;

    setState();
    updateAnim();

    collision();

    ++frameTick;
    if (frameTick % 6 == 0)
    {
        player.updateFrame();
        setPixmap(player.getCurrentFrame());
        frameTick = 0;

    }
}

//Movement direction checker, uses true and false to check as keyboard input only read one input at a time
void Player::setState()
{
    velocity = QPointF(0, 0);

    if (movement.left)
    {
        velocity.setX(-speed);
    }
    if (movement.right)
    {
        velocity.setX(+speed);
    }

    if (movement.up)
    {
        velocity.setY(-speed);
    }

    if (movement.down)
    {
        velocity.setY(speed);
    }

    if (movement.left && movement.right)
    {
        velocity.setX(0);
    }
    if (movement.up && movement.down)
    {
        velocity.setY(0);
    }

    if ( velocity.y() != 0 && movement.increaseSpeed )
        velocity.setY(velocity.y()*2);
    if ( velocity.y() != 0 && movement.decreaseSpeed)
    {
        velocity.setY(velocity.y()/2);
        qDebug()<<"decreasespeed is"<<movement.decreaseSpeed;
    }


    //Animation direction
    if (velocity == QPointF(0,0 ))
        state = Idle;
    else if (velocity.x() > 0)
        state = MovingRight;
    else if (velocity.x() < 0)
        state = MovingLeft;
    else if (velocity.y() > 0)
        state = MovingDown;
    else if (velocity.y() < 0)
        state = MovingUp;

}

//Update animation, might need to change the directories to strings and save them all in a struct
void Player::updateAnim()
{
    if (prevstate != state)
    {
        switch(state)
        {
        case Idle:
        player.loadFrame(":/Sprites/Sprites/Character/Character.png", 128, 128, 0, 1);
        //sprite.getCurrentFrame();
        break;

        case MovingLeft:
        player.loadFrame(":/Sprites/Sprites/Character/Character.png", 128, 128, 2, 4);
        qDebug() << "working";
        player.getCurrentFrame();
        break;

        case MovingRight:
        player.loadFrame(":/Sprites/Sprites/Character/Character.png", 128, 128, 1, 4);
        break;

        case MovingUp:
        player.loadFrame(":/Sprites/Sprites/Character/Character.png", 128, 128, 3, 4);
        //sprite.getCurrentFrame();
        break;

        case MovingDown:
        player.loadFrame(":/Sprites/Sprites/Character/Character.png", 128, 128, 0, 4);
        //sprite.getCurrentFrame();
        break;


        default:
        break;
        }

    }


    setPixmap(player.getCurrentFrame());

    prevstate = state;

}

void Player::collision()
{

    QPointF oldPos = pos();
    QPointF nextPos = oldPos + velocity;
    setPos(nextPos);

    QList<QGraphicsItem*> hits = collidingItems();

    bool blocked = false;
//Check collision with player in x direction
    //Have to implement again
    for (QGraphicsItem* item : hits)
    {
        Objects* obj = dynamic_cast<Objects*>(item);

        if (!obj)
            continue;

        if (obj->isSolid())
        {
            blocked = true;
            if (velocity.x() > 0)
            {
                movement.right = false;

            }

            else if (velocity.x() < 0)
            {
                 movement.left = false;

            }

            if (velocity.y() < 0)
            {
                movement.down = false;

            }
            else if (velocity.y() > 0)
            {
                movement.up = false;

            }

        }

        obj->applyEffect(this);
    }

    //Revert position
    setPos(oldPos);

    //Apply movement if not blocked
    if (!blocked)
    {
        setPos(nextPos);
    }

    oldPos = pos();

}
void Player::throwShuriken(QPointF target)
{
    if (!itemPickedUp) return;

        itemPickedUp = false;
        isThrowing = true;

        QPointF dir = target - scenePos();

        qreal length = std::sqrt(dir.x()*dir.x() + dir.y()*dir.y());

        if (length == 0) return;

        dir /= length;

        QPointF velocity = dir * 12.0;


        ProjectileMovement *proj = new ProjectileMovement(scenePos(), velocity);
        scene()->addItem(proj);

}

QRectF Player::boundingRect() const
{
     return QRectF(0, 0, 160, 230);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(40, 0, 80, 180);
    return path;
}
