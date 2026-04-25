#include "levelmanager.h"
#include "track.h"

LevelManager::LevelManager(QObject* parent) : QObject(parent)
{
    loadLevel(1);
}

void LevelManager::loadLevel(int levelNumber)
{
    if (currentGameScene)
    {
        delete currentGameScene;
    }

    currentGameScene = new GameScene();
    currentLevel = levelNumber;

    if(levelNumber == 1)
    {
        currentGameScene->setBackgroundBrush(Qt::green); // toets maar kan sprites insit
    }
    else if(levelNumber == 2)
    {
        currentGameScene->setBackgroundBrush(Qt::darkYellow);
    }

    //Spawn al die obstacles
    emit sceneChanged(currentGameScene);
}
