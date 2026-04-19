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
#include "staminabar.h"
#include "sand.h"
#include "grass.h"
#include "track.h"
#include "trackbarrier.h"


class GameScene : public QGraphicsScene
{
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

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

private:
    QTimer *timer;
    QList<Powerups*> powerUpsMap;
    StaminaBar* localStaminaBar = nullptr;
    StaminaBar* remoteStaminaBar = nullptr;

};

#endif // GAMESCENE_H
