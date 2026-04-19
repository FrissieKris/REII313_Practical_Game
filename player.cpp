#include "player.h"
#include "staminabar.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QtGlobal>
#include <cmath>

Player::Player()
    : player(":/Sprites/Sprites/Character/Character.png", 128, 128, 0, 1),
        velocity(0, 0)
  {
           staminaBar = new StaminaBar();
    setPixmap(player.getCurrentFrame());
    qDebug() << player.getCurrentFrame().isNull();
      setPixmap(player.getCurrentFrame());
      qDebug() << player.getCurrentFrame().isNull();

      speedTimer.setSingleShot(true);

      connect(&speedTimer, &QTimer::timeout, this, [this]() {
          if (movement.increaseSpeed == true)
            movement.increaseSpeed = false;
          else if (movement.decreaseSpeed == true)
              movement.decreaseSpeed = false;
      });

  }


//Player updates
void Player::advance(int step)

{
    //Skip first one, as there are two checks done one at 0 and another at 1; 1 updates all
    if (!step) return;

    setState();
    updateAnim();

    collision();

    //---------------Stamina Bar Implementation------------------------

    if(staminaBar)
    {
        float speedFactor = std::sqrt(velocity.x()*velocity.x() + velocity.y()*velocity.y()) / baseSpeed;
        if(speedFactor > 1.0f)
        {
            staminaBar->decrease(0.08f * speedFactor);
        }
        if(velocity.isNull() && staminaBar->getValue() < 100.0f)
        {
            staminaBar->increase(0.03f);
        }
    }

    //Sit die collision stamina penalty se stuffs hier


    //-----------------------------------------------------------------
    //    QPointF nextPosX(pos().x(),pos().x()+ velocity.x());


    //    QList<QGraphicsItem*> hits = collidingItems();

    //    bool blocked = false;

    //    //Check collision with player
    //    for (QGraphicsItem* item : hits)
    //    {
    //        qDebug() << "Colliding with:" << item;
    //        Objects* obj = dynamic_cast<Objects*>(item);

    //        if (!obj)
    //            continue;

    //        if (obj->isSolid())
    //        {
    //            blocked = true;

    //        }

    //        obj->onCollision(this);
    //     }

    //        if (!blocked)
    //        {
    //            setPos(nextPos);
    //        }

    //------Moontlike bounds vir die player se track--------

//    const QRectF bounds(50, 50, 1900, 500);
//    if (pos().x() < bounds.left())
//        setPos(bounds.left(), pos().y());
//    if (pos().x() > bounds.right())
//        setPos(bounds.right(), pos().y());
//    if (pos().y() < bounds.top())
//        setPos(pos().x(), bounds.top());
//    if (pos().y() > bounds.bottom())
//        setPos(pos().x(), bounds.bottom());
    //----------------------------------------------------

    //Na collision handling se goed
    //if (hitObstacle)
    //  staminaBar->decrease(8.0f);


    frameTick++;
    if (frameTick % 6 == 0)
    {
        player.updateFrame();
        setPixmap(player.getCurrentFrame());
    }
}

//Movement direction checker, uses true and false to check as keyboard input only read one input at a time
void Player::setState()
{
    velocity = QPointF(0, 0);
    //---------------Kyk maar net hierdie het ek bygesit vir scaling------------
    float currentSpeed = speed;
    if(movement.increaseSpeed) currentSpeed *= 2.0f;
    //--------------------------------------------------------------

    if (movement.left)
    {
        velocity.setX(-currentSpeed);
    }
    if (movement.right)
    {
        velocity.setX(+currentSpeed);
    }

    if (movement.up)
    {
        velocity.setY(-currentSpeed);
    }

    if (movement.down)
    {
        velocity.setY(+currentSpeed);
    }

    //Cancel opposite keys
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
