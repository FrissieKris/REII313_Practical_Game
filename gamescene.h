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


class GameScene : public QGraphicsScene
{
public:
    GameScene();
    Player *localPlayer;
    Player *remotePlayer;
    Tree *tree;
    Powerups *powerUp;

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
