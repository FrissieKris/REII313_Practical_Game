#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QGraphicsScene>
#include "player.h"
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsView>
#include "tree.h"
#include "powerups.h"
#include <QList>
#include "sand.h"
#include "grass.h"
#include "track.h"
#include "trackbarrier.h"
#include "timingbar.h"
#include <QGraphicsSceneMouseEvent>
#include "ninjastar.h"
#include "staminabar.h"
#include "enemy.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene();
    Player *localPlayer;
    Player *remotePlayer;
    Tree *tree;
    Powerups *powerUp;
    Sand *sand;
    Grass *grass;
    Track *track;
    TrackBarrier *barrier;
    NinjaStar *ninjaStar;
    StaminaBar *staminaBar;
    Enemy *enemy;

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);


private:
    QTimer* timer;
    QTimer* breathingTimer = nullptr;
    QList<Powerups*> powerUpsMap;
    StaminaBar* localStaminaBar = nullptr;
    StaminaBar* remoteStaminaBar = nullptr;
    TimingBar* localTimingBar = nullptr;
    TimingBar* remoteTimingBar = nullptr;


    private slots:
    void triggerBreathingMinigame();

};

#endif // GAMESCENE_H
