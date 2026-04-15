#include "player.h"
#include <QDebug>

Player::Player()
    : sprite(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 3),
        velocity(0, 0)
  {
      setPixmap(sprite.getCurrentFrame());

//      setFlag(QGraphicsItem::ItemIsFocusable);
//      setFocus();
      qDebug() << sprite.getCurrentFrame().isNull();
  }

//void Player::keyPressEvent(QKeyEvent *e)
//{
//    if (e->key() == Qt::Key_Right)
//        velocity.setX(3);

//    else if (e->key() == Qt::Key_Left)
//        velocity.setX(-3);

//    else if (e->key() == Qt::Key_Up)
//        velocity.setY(-3);

//    else if (e->key() == Qt::Key_Down)
//        velocity.setY(3);
//}

//void Player::keyReleaseEvent(QKeyEvent *e)
//{
//    if (e->key() == Qt::Key_Left || e->key() == Qt::Key_Right)
//           velocity.setX(0);

//       if (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down)
//           velocity.setY(0);
//}

void Player::setState(PlayerState newState)
{
    state = newState;
}

void Player::advance(int step)

{
    if (!step) return;

    QPointF vel(0, 0);

    switch(state)
    {
        case MovingLeft:
        vel.setX(-speed);
        break;

        case MovingRight:
        vel.setX(speed);
        break;

        case MovingUp:
        vel.setY(-speed);
        break;

        case MovingDown:
        vel.setY(speed);
        break;

        default:
        break;
    }

    moveBy(vel.x(), vel.y());

    frameTick++;
    if (frameTick % 6 == 0)
    {
        sprite.updateFrame();
        setPixmap(sprite.getCurrentFrame());
    }
}
