#include "gamescene.h"
#include "staminabar.h"
#include "timingbar.h"
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

    //staminaBar = new StaminaBar(localPlayer);
    staminaBar = new StaminaBar(localPlayer);


    enemy = new Enemy();



    remotePlayer = new Player();
    remotePlayer->setPos(800,0);

    //-------------------------Ek position die players hier----------------------
    //localPlayer->setPos(300, 300);
    //remotePlayer->setPos(700, 300);
    //---------------------------------------------------------------------------

    //***********************************************************************************

    //All the stuffs for the Stamina bar
    //Creates 2 instances, one per player

    // localStaminaBar = new StaminaBar();
    // addItem(localStaminaBar);
    // localStaminaBar->setPos(50 , 30); //Can be adjusted later

    // remoteStaminaBar = new StaminaBar();
    // addItem(remoteStaminaBar);
    // remoteStaminaBar->setPos(1050,30);

    // localTimingBar = new TimingBar();
    // addItem(localTimingBar);
    // localTimingBar->setPos(40, 60);        // below stamina bar on left side

    // remoteTimingBar = new TimingBar();
    // addItem(remoteTimingBar);
    // remoteTimingBar->setPos(1040, 60);     // below stamina on right side

    // localPlayer->staminaBar = localStaminaBar;
    // remotePlayer->staminaBar = remoteStaminaBar;

    // localPlayer->timingBar = localTimingBar;
    // remotePlayer->timingBar = remoteTimingBar;

    // breathingTimer = new QTimer(this);
    // connect(breathingTimer, &QTimer::timeout, this, &GameScene::triggerBreathingMinigame);
    // breathingTimer->start(4000);   // every 4 seconds

    //************************************************************************************************
   // sand = new Sand(256*1000,256*1000);

    sand = new Sand(256*2,256*2);
    sand->setPos(100, -30);

    grass = new Grass(256*1000,256*1000);
    grass->setPos(-256*1000,-256*1000);


    tree = new Tree();
    tree->setPos(100,100);

    ninjaStar = new NinjaStar();
    ninjaStar->setPos(400,100);

    //addItem(remotePlayer);
    addItem(track);

    addItem(sand);
    addItem(grass);
    addItem(barrier);
    addItem(tree);
    addItem(ninjaStar);
    addItem(enemy);


    staminaBar->border->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    //staminaBar->fill->setFlag(QGraphicsItem::ItemIgnoresTransformations);

    //Spawn the powerups, need to be done better
    for (int i = 0; i < 10; ++i)
    {
        Powerups* p = new Powerups();

        int x = QRandomGenerator::global()->bounded(2000);
        int y = QRandomGenerator::global()->bounded(600);

        p->setPos(x, y);
        addItem(p);
    }

    for (int i = 0; i < 10; ++i)
    {
        NinjaStar* s = new NinjaStar();

        int x = QRandomGenerator::global()->bounded(2000);
        int y = QRandomGenerator::global()->bounded(600);

        s->setPos(x, y);
        addItem(s);
    }



    //qDebug() << "localPlayer:" << localPlayer;

    addItem(localPlayer);
//    addItem(staminaBar->border);
//    addItem(staminaBar->fill);


    //Small window that follows with the player as he/she moves
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]()
    {
        QGraphicsScene::advance();

        for (auto* view : views())
        {
            //view->centerOn(localPlayer);
            QPointF c1 = localPlayer->pos();
            QRectF r1(c1.x() - 100, c1.y() - 150, 200, 300);



            view->setSceneRect(r1);
            staminaBar->border->setPos(c1.x(), c1.y() - 55);
            staminaBar->fill->setPos(c1.x() , c1.y() - 55);
            staminaBar->getStaminaLevel(localPlayer->currentStamina);

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

    //----------------KeyPressTiming vir Stamina Bar and Timing Bar---------------
    if(e->key() == Qt::Key_Space)
    {

        //Chuck this in before the minigame to be added
        if(localPlayer && localPlayer->timingBar && localPlayer->timingBar->isActive())
        {
            TimingResult res = localPlayer->timingBar->evaluateHit();
            localPlayer->timingBar->showResult(res);


            if(localPlayer->staminaBar)
            {
                if(res == TimingResult::Perfect)
                    localPlayer->staminaBar->increase(28.0f);
                else if(res == TimingResult::Good) localPlayer->staminaBar->increase(14.0f);
                //Miss means no gain
            }
            localPlayer->timingBar->deactivate();
        }
//        if (localPlayer && localPlayer->timingBar && localPlayer->timingBar->isActive())
//        {
//            activePlayer = localPlayer;
//            activeBar = localPlayer->timingBar;
//        }
//        else if (remotePlayer && remotePlayer->timingBar && remotePlayer->timingBar->isActive())
//        {
//            activePlayer = remotePlayer;
//            activeBar = remotePlayer->timingBar;
//        }

//        if (activeBar && activePlayer)
//        {
//            TimingResult result = activeBar->evaluateHit();
//            activeBar->showResult(result);

//            if (activePlayer->staminaBar)
//            {
//                if (result == TimingResult::Perfect)
//                    activePlayer->staminaBar->increase(28.0f);
//                else if (result == TimingResult::Good)
//                    activePlayer->staminaBar->increase(14.0f);
//                // Miss = small penalty or nothing
//            }

//            activeBar->deactivate();
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

    else if (e->key() == Qt::Key_Up)
        localPlayer->movement.up = true;

    else if (e->key() == Qt::Key_Down)
        localPlayer->movement.down = true;

    else if (e->key() == Qt::Key_Space && localPlayer->currentStamina != localPlayer->minStamina && !e->isAutoRepeat())
    {
        localPlayer->movement.increaseSpeed = true;
        localPlayer->currentStamina = localPlayer->currentStamina - 1;
        localPlayer->coolDownTimer.stop();
    }
    else if (e->key() == Qt::Key_Space && localPlayer->currentStamina != localPlayer->minStamina && e->isAutoRepeat())
    {
        localPlayer->movement.increaseSpeed = true;
        localPlayer->currentStamina = localPlayer->currentStamina - 1;
        localPlayer->coolDownTimer.stop();
    }


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
    {
        localPlayer->movement.increaseSpeed = false;
        localPlayer->coolDownTimer.start(1000);
    }

}


void GameScene::triggerBreathingMinigame()
{
    if (localPlayer && localPlayer->timingBar && !localPlayer->timingBar->isActive())
    {
        float speedFactor = localPlayer->getCurrentSpeedFactor();
        localPlayer->timingBar->activate(speedFactor);
    }
    // same for remotePlayer
}
void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        localPlayer->throwShuriken(e->scenePos());
    }
}
