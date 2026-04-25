#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QObject>
#include "gamescene.h"

class LevelManager : public QObject
{
    Q_OBJECT
public:
    explicit LevelManager(QObject* parent = nullptr);

    void loadLevel(int levelNumber);
    GameScene* currentScene() const {return currentGameScene; }
signals:
    void sceneChanged(GameScene* newScene);

private:
    GameScene* currentGameScene = nullptr;
    int currentLevel = 1;

};


#endif // LEVELMANAGER_H
