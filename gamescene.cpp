#include "gamescene.h"
#include <QDebug>

GameScene::GameScene()
{


    setSceneRect(0, 0, 2000, 600);
    setFocus();
    //setFocusItem(nullptr);
    addRect(0, 500, 2000, 50, QPen(Qt::NoPen), QBrush(Qt::darkGreen));

    localPlayer = new Player();
    remotePlayer = new Player();
    tree = new Tree();

    qDebug() << "localPlayer:" << localPlayer;


    addItem(remotePlayer);
    addItem(tree);
    addItem(localPlayer);

    QGraphicsRectItem *test = addRect(0, 0, 100, 100, QPen(Qt::red));


    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=]()
    {
        QGraphicsScene::advance();

        for (auto view : views())
        {
            //view->centerOn(localPlayer);
            QPointF c1 = localPlayer->pos();
            QRectF r1(c1.x() - 200, c1.y() - 300, 400, 600);


            view->setSceneRect(r1);
       }
    });

    timer->start(16);


//    timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &QGraphicsScene::advance);
//    timer->start(16);

}


void GameScene::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Right)
        localPlayer->movement.right = true;
        //localPlayer->setState(Player::MovingRight);

    else if (e->key() == Qt::Key_Left)
        localPlayer->movement.left = true;

    else if (e->key() == Qt::Key_Up)
        localPlayer->movement.up = true;

    else if (e->key() == Qt::Key_Down)
        localPlayer->movement.down = true;

    else if (e->key() == Qt::Key_Space)
        localPlayer->movement.increaseSpeed = true;


}

void GameScene::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Up)
        localPlayer->movement.up = false;

    if (e->key() == Qt::Key_Down)
        localPlayer->movement.down = false;

    if (e->key() == Qt::Key_Left)
        localPlayer->movement.left = false;

    if (e->key() == Qt::Key_Right)
        localPlayer->movement.right = false;
    if (e->key() == Qt::Key_Space)
        localPlayer->movement.increaseSpeed = false;
}
