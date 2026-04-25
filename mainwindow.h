#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescene.h"
#include "player.h"
#include "mainmenu.h"
#include "levelmanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    GameScene *scene;
    MainMenu* mainMenuScene = nullptr;
    LevelManager* levelManager = nullptr;
    GameScene* currentGameScene = nullptr;

private slots:
    void startSinglePlayer();
    void startMultiplayer();
};
#endif // MAINWINDOW_H
