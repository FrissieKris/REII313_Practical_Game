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

protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

private:
    QTimer *timer;
    QList<Powerups*> powerUpsMap;


};

#endif // GAMESCENE_H
