#include "gamescene.h"
#include <QDebug>

GameScene::GameScene()
{


    setSceneRect(0, 0, 2000, 600);
    setFocus();
    //setFocusItem(nullptr);
    //addRect(0, 500, 2000, 50, QPen(Qt::NoPen), QBrush(Qt::darkGreen));

    localPlayer = new Player();
    remotePlayer = new Player();

    setSceneRect(0, 0, 2000, 600);



    qDebug() << "localPlayer:" << localPlayer;

    addItem(localPlayer);
    addItem(remotePlayer);



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
        localPlayer->setState(Player::MovingRight);

    else if (e->key() == Qt::Key_Left)
        localPlayer->setState(Player::MovingLeft);

    else if (e->key() == Qt::Key_Up)
        localPlayer->setState(Player::MovingUp);

    else if (e->key() == Qt::Key_Down)
        localPlayer->setState(Player::MovingDown);

}

void GameScene::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Left || e->key() == Qt::Key_Right)
    {
        localPlayer->setState(Player::Idle);

    }

    if (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down)
    {
         localPlayer->setState(Player::Idle);
    }

}
