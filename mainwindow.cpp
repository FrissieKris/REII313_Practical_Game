#include "mainwindow.h"
#include "gamescene.h"
#include <QGraphicsView>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

        GameScene *scene = new GameScene();
        scene->setSceneRect(0, 0, 2000, 600);
        QGraphicsView *view1 = new QGraphicsView(scene);
        setCentralWidget(view1);
        view1->setFocus();
        view1->setFocusPolicy(Qt::StrongFocus);

        view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1->setFrameShape(QFrame::NoFrame);

}

MainWindow::~MainWindow()
{
}

