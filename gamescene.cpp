#include "gamescene.h"
#include "staminabar.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QtGlobal>



GameScene::GameScene()
{
    //setSceneRect(0, 0, 2000, 600); //Klaar declare in mainwindow.cpp
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

    //-------------------------Ek position die players hier----------------------
    localPlayer->setPos(300, 300);
    remotePlayer->setPos(700, 300);
    //---------------------------------------------------------------------------

    //***********************************************************************************

    //All the stuffs for the Stamina bar
    //Creates 2 instances, one per player

    localStaminaBar = new StaminaBar();
    addItem(localStaminaBar);
    localStaminaBar->setPos(50 , 30); //Can be adjusted later

    remoteStaminaBar = new StaminaBar();
    addItem(remoteStaminaBar);
    remoteStaminaBar->setPos(1050,30);

    localPlayer->staminaBar = localStaminaBar;
    localPlayer->staminaBar = remoteStaminaBar;

    //************************************************************************************************
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

    qDebug() << "localPlayer:" << localPlayer;

    addItem(remotePlayer);
    addItem(tree);


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
//            QPointF c1 = localPlayer->pos();
//            QRectF r1(c1.x() - 200, c1.y() - 300, 400, 600);


//            view->setSceneRect(r1);
//          --------Kan dalk hierdie vervang met hieronder vir slegs centering--------
//             if(localPlayer)
//             {
//                 view->centerOn(localPlayer); //
//             }
            //----------------------------------------------------------------------
//            ------------of hierdie vir net effense centering--------------
//            QPointF target = localPlayer->pos();
//            view->setSceneRect(target.x()- 200, target.y() - 300,400,600);
            //--------------------------------------------------------------
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
    //Ek gaan hierso net switchcase insit. Kan aanpas of verander
    //-----------------------------------------------------------
    switch(e->key())
    {
    case Qt::Key_Right: localPlayer->movement.right = true; break;
    case Qt::Key_Left:  localPlayer->movement.left  = true; break;
    case Qt::Key_Up:    localPlayer->movement.up    = true; break;
    case Qt::Key_Down:  localPlayer->movement.down  = true; break;
    case Qt::Key_Space:  localPlayer->movement.increaseSpeed = true; break;
    default: break;
    }

    //Hier is die stuff vir remoteplayer solank met ijkl as local input
    switch(e->key())
    {
    case Qt::Key_L:  remotePlayer->movement.right = true; break;
    case Qt::Key_J:  remotePlayer->movement.left  = true; break;
    case Qt::Key_I:  remotePlayer->movement.up    = true; break;
    case Qt::Key_K:  remotePlayer->movement.down  = true; break;
    case Qt::Key_M:  remotePlayer->movement.increaseSpeed = true; break; //Eers net M ingesit in plaas van space
    default: break;
    }

    //----------------KeyPressTiming vir Stamina Bar---------------
    if(e->key() == Qt::Key_Space)
    {
        //Chuck this in before the minigame to be added
        if(localPlayer && localPlayer->staminaBar)
        {
            localPlayer->staminaBar->increase(15.0f);

        }
        if(remotePlayer && remotePlayer->staminaBar)
        {
            remotePlayer->staminaBar->increase(15.0f);
        }
    }

    //--------------------------------------------------------------------------


    //-----------------------------------------------------------
//    if (e->key() == Qt::Key_Right)
//        localPlayer->movement.right = true;
//        //localPlayer->setState(Player::MovingRight);

//    else if (e->key() == Qt::Key_Left)
//        localPlayer->movement.left = true;

//    else if (e->key() == Qt::Key_Up)
//        localPlayer->movement.up = true;

//    else if (e->key() == Qt::Key_Down)
//        localPlayer->movement.down = true;

//    else if (e->key() == Qt::Key_Space)
//        localPlayer->movement.increaseSpeed = true;


}

//Release key for false
void GameScene::keyReleaseEvent(QKeyEvent *e)
{

    //-----------Ek doen dieselfde hier as daar bo--------------
    switch(e->key())
    {
    case Qt::Key_Right: localPlayer->movement.right = false; break;
    case Qt::Key_Left:  localPlayer->movement.left  = false; break;
    case Qt::Key_Up:    localPlayer->movement.up    = false; break;
    case Qt::Key_Down:  localPlayer->movement.down  = false; break;
    case Qt::Key_Space:  localPlayer->movement.increaseSpeed = false; break;
    default: break;
    }

    switch(e->key())
    {
    case Qt::Key_L:  remotePlayer->movement.right = false; break;
    case Qt::Key_J:  remotePlayer->movement.left  = false; break;
    case Qt::Key_I:  remotePlayer->movement.up    = false; break;
    case Qt::Key_K:  remotePlayer->movement.down  = false; break;
    case Qt::Key_M:  remotePlayer->movement.increaseSpeed = true; break; //Eers net M ingesit in plaas van space
    default: break;
    }
    //--------------------------------------------------------------------
//    if (e->key() == Qt::Key_Up)
//        localPlayer->movement.up = false;

//    if (e->key() == Qt::Key_Down)
//        localPlayer->movement.down = false;

//    if (e->key() == Qt::Key_Left)
//        localPlayer->movement.left = false;

//    if (e->key() == Qt::Key_Right)
//        localPlayer->movement.right = false;
//    if (e->key() == Qt::Key_Space)
//        localPlayer->movement.increaseSpeed = false;
}
