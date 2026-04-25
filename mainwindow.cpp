#include "mainwindow.h"
#include "gamescene.h"
#include <QGraphicsView>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    levelManager = new LevelManager(this);

    mainMenuScene = new MainMenu(this);
    connect(mainMenuScene, &MainMenu::startSinglePlayer, this, &MainWindow::startSinglePlayer);
    connect(mainMenuScene, &MainMenu::startMultiplayer, this, &MainWindow::startMultiplayer);
    connect(mainMenuScene, &MainMenu::quitGame, this, &QWidget::close);

    QGraphicsView* menuView = new QGraphicsView(mainMenuScene);
    menuView->setFixedSize( 1920, 600);
    setCentralWidget(menuView);

  //===========Ou Scene Manager================
//    GameScene *scene = new GameScene();
//    scene->setSceneRect(0, 0, 2000, 600);
//    QGraphicsView *view1 = new QGraphicsView(scene);
//    setCentralWidget(view1);
//    view1->setFocus();
//    view1->setFocusPolicy(Qt::StrongFocus);

//    view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view1->setFrameShape(QFrame::NoFrame);
//=============================================================
}

MainWindow::~MainWindow()
{
}

void MainWindow::startSinglePlayer()
    {
        currentGameScene = levelManager->currentScene();
        QGraphicsView* gameView = new QGraphicsView(currentGameScene);
        gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setCentralWidget(gameView);
        //currentGameScene->startGame();  //Moet nog insit
    }

    void MainWindow::startMultiplayer()
    {
        //Moet nog goed insit
    }

