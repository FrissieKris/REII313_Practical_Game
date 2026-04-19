#include "gamescene.h"
#include <QDebug>
#include <QRandomGenerator>


GameScene::GameScene()
{


    setSceneRect(0, 0, 2000, 600);
    setFocus();
    //setFocusItem(nullptr);
    //addRect(-1000, 0, 5000, 10000, QPen(Qt::NoPen), QBrush(Qt::darkGreen));


    track = new Track(1920,1080*1000);
    track->setPos(0, -1080*1000);

    barrier = new TrackBarrier(16,128*100);
    barrier->setPos(-16, -128*100);

    localPlayer = new Player();
    localPlayer->setPos(960,0);

    remotePlayer = new Player();

   // sand = new Sand(256*1000,256*1000);
    grass = new Grass(256*1000,256*1000);
    grass->setPos(-256*1000,-256*1000);


    tree = new Tree();
    tree->setPos(100,100);

    addItem(remotePlayer);
    addItem(track);

    //addItem(sand);
    addItem(grass);
    addItem(barrier);
    addItem(tree);

    //Spawn the powerups, need to be done better
    for (int i = 0; i < 10; ++i)
    {
        Powerups* p = new Powerups();

        int x = QRandomGenerator::global()->bounded(2000);
        int y = QRandomGenerator::global()->bounded(600);

        p->setPos(x, y);
        addItem(p);
    }



    //qDebug() << "localPlayer:" << localPlayer;

    addItem(localPlayer);

    //Small window that follows with the player as he/she moves
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]()
    {
        QGraphicsScene::advance();

        for (auto view : views())
        {
            //view->centerOn(localPlayer);
            QPointF c1 = localPlayer->pos();
            QRectF r1(c1.x() - 100, c1.y() - 150, 200, 300);


            view->setSceneRect(r1);
       }
    });

    timer->start(16);

}


//Keyboard input, use true and false and then in Player class check if conditions are met
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

//Release key for false
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
