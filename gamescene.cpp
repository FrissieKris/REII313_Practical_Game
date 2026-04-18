#include "gamescene.h"
#include "staminabar.h"
#include <QDebug>
#include <QRandomGenerator>


GameScene::GameScene()
{


    setSceneRect(0, 0, 2000, 600);
    setFocus();
    //setFocusItem(nullptr);
    addRect(-1000, 0, 5000, 10000, QPen(Qt::NoPen), QBrush(Qt::darkGreen));



    localPlayer = new Player();
    remotePlayer = new Player();
    tree = new Tree();
    tree->setPos(0,600);
    //***********************************************************************************

    //All the stuffs for the Stamina bar
    //Creates 2 instances, one per player

//    localStamina = new staminaBar();
//    addItem(localStamina);
//    localStamina->setPos(50 , 20); //Can be adjusted later

//    remoteStamina = new StaminaBar();
//    addItem(remoteStamina);
//    remoteStamina->SetPos(1050,20);

    //************************************************************************************************

    //Spawn the powerups, need to be done better
    for (int i = 0; i < 10; i++)
    {
        Powerups* p = new Powerups();

        int x = QRandomGenerator::global()->bounded(2000);
        int y = QRandomGenerator::global()->bounded(600);

        p->setPos(x, y);
        addItem(p);
    }



    qDebug() << "localPlayer:" << localPlayer;


    addItem(remotePlayer);
    addItem(tree);

    addItem(localPlayer);





    //Small window that follows with the player as he/she moves
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]()
    {
        QGraphicsScene::advance();

        for (auto view : views())
        {
            //view->centerOn(localPlayer);
//            QPointF c1 = localPlayer->pos();
//            QRectF r1(c1.x() - 200, c1.y() - 300, 400, 600);


//            view->setSceneRect(r1);
//            Kan dalk hierdie vervang met hieronder vir slegs centering
            if(localPlayer)
            {
                view->centerOn(localPlayer); //
            }
//            of hierdie vir net effense centering
//            QPointF target = localPlayer->pos();
//            view->setSceneRect(target.x()- 200, target.y() - 300,400,600);
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
