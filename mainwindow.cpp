#include "mainwindow.h"
#include "gamescene.h"
#include <QGraphicsView>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //

        GameScene *scene = new GameScene();
        scene->setSceneRect(0, 0, 2000, 600);

        //-----------2 Side-by-side views se toets---------------
        QGraphicsView *view1 = new QGraphicsView(scene); //Player1 links
        QGraphicsView *view2 = new QGraphicsView(scene); //Player2 regs


        QWidget *container = new QWidget(this);
        QHBoxLayout *layout = new QHBoxLayout(container);
        layout->setContentsMargins(0,0,0,0);
        layout->setSpacing(2);
        layout->addWidget(view1);
        layout->addWidget(view2);

        setCentralWidget(container);

        //Style the views
        auto setupView = [](QGraphicsView* v) {
                v->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                v->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
                v->setFrameShape(QFrame::NoFrame);
                v->setFixedSize(960, 600);
        };
        setupView(view1);
        setupView(view2);

        //Focus both for independent input (Later wasd en ijkl)
        view1->setFocus();
        view1->setFocusPolicy(Qt::StrongFocus);
        view2->setFocusPolicy(Qt::StrongFocus);

        //------------------------------------------------------------

        //        view1->setFocus();
        //        view1->setFocusPolicy(Qt::StrongFocus);

//        view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//        view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//        view1->setFrameShape(QFrame::NoFrame);

}

MainWindow::~MainWindow()
{
}

