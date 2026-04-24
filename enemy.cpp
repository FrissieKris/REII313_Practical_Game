#include "enemy.h"
#include <QDebug>
#include "player.h"
#include <cmath>
Enemy::Enemy()
{

    state = Idle;
}

void Enemy::applyEffect(class Player *player)
{

    state = Tracking;
    qDebug()<<"Tracking";


}

void Enemy::advance(int step)
{
    if(state == Idle || !step)
        return;


    for (auto item : collidingItems())
    {
        Objects* obj = dynamic_cast<Objects*>(item);

        Player* player = dynamic_cast<Player*>(obj);
//        if (!obj)
//        {
//            state = Idle;
//            qDebug()<<"Idle";
//            continue;
//        }
        if (player)
        {
            QPointF dir = player->pos() - scenePos();
            qreal length = std::sqrt(dir.x()*dir.x() + dir.y()*dir.y());

            if (length == 0) return;

            dir /= length;

            QPointF velocity = dir * 3.0;
            setPos(pos() + velocity);


            qDebug()<<"Tracking";
            continue;
        }


    }


}

QRectF Enemy::boundingRect() const
{
    return QRectF(-256+64, -256+64, 512, 512);
}

QPainterPath Enemy::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;

}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // draw your normal pixmap first
    painter->drawPixmap(-256, -256, pixmap());

    // DEBUG: draw the shape outline
    painter->setPen(QPen(Qt::red, 2));
    painter->setBrush(Qt::red);
    painter->drawPath(shape());
}
