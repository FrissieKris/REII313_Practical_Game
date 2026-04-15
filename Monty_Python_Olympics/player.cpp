#include "player.h"
#include <QDebug>

Player::Player()
    : sprite(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 0, 1),
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

    if (movement.left)
    {
        vel.setX(-speed);
        state = MovingLeft;

    }
    if (movement.right)
    {
        vel.setX(speed);
        state = MovingRight;
    }

    if (movement.up)
    {
        vel.setY(-speed);
        state = MovingUp;
    }

    if (movement.down)
    {
        vel.setY(speed);
        state = MovingDown;
    }
    if (!movement.left && !movement.right && !movement.down && !movement.up)
        state = Idle;


    if (prevstate != state)
    {
        switch(state)
            {
                case Idle:
                sprite.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233,0, 1);
                break;

                case MovingLeft:
                sprite.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233,2 , 3);
                qDebug() << "working";
                break;

                case MovingRight:

                break;

                case MovingUp:
                sprite.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 1, 3);
                break;

                case MovingDown:
                sprite.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 0, 3);
                break;


                default:
                break;
            }





    }

    prevstate = state;



//   switch(state)
//    {
//        case MovingLeft:

//        break;

//        case MovingRight:

//        break;

//        case MovingUp:

//        break;

//        case MovingDown:
//        sprite.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 3);

//        break;

//        case Idle:
//        sprite.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 1);
//        break;


//        default:
//        break;
//    }

    moveBy(vel.x(), vel.y());

    frameTick++;
    if (frameTick % 6 == 0)
    {
        sprite.updateFrame();
        setPixmap(sprite.getCurrentFrame());
    }
}
