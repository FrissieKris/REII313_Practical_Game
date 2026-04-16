#include "player.h"
#include <QDebug>

Player::Player()
    : player(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 0, 1),
        velocity(0, 0)
  {
      setPixmap(player.getCurrentFrame());
      qDebug() << player.getCurrentFrame().isNull();
  }


void Player::advance(int step)

{
    if (!step) return;

    setState();
    updateAnim();

    moveBy(velocity.x(), velocity.y());

    frameTick++;
    if (frameTick % 6 == 0)
    {
        player.updateFrame();
        setPixmap(player.getCurrentFrame());
    }
}

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

void Player::updateAnim()
{
    if (prevstate != state)
    {
        switch(state)
            {
                case Idle:
                player.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233,0, 1);
                //sprite.getCurrentFrame();
                break;

                case MovingLeft:
                player.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233,2 , 3);
                qDebug() << "working";
                player.getCurrentFrame();
                break;

                case MovingRight:

                break;

                case MovingUp:
                player.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 1, 3);
                //sprite.getCurrentFrame();
                break;

                case MovingDown:
                player.loadFrame(":/sprites/Sprites/top-down-game-3-animations-example.png", 160, 233, 0, 3);
                //sprite.getCurrentFrame();
                break;


                default:
                break;
            }

    }

    setPixmap(player.getCurrentFrame());

    prevstate = state;

}
