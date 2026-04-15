#include "mainwindow.h"
#include "gamescene.h"
#include <QGraphicsView>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{



      GameScene *scene = new GameScene();
      scene->setSceneRect(0, 0, 2000, 600);


//       Player *p1 = new Player();
//       Player *p2 = new Player();

//       p1->setPos(100, 300);
//       p2->setPos(300, 300);

//       scene->addItem(p1);
//       scene->addItem(p2);

       QGraphicsView *view1 = new QGraphicsView(scene);
       setCentralWidget(view1);
       view1->setFocus();
       view1->setFocusPolicy(Qt::StrongFocus);


//       //QGraphicsView *view2 = new QGraphicsView(scene);

//       view1->adjustSize();
//       //view2->setFixedSize(400, 600);

       view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

////       view2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
////       view2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

       view1->setFrameShape(QFrame::NoFrame);
//      // view2->setFrameShape(QFrame::NoFrame);

//       QWidget *container = new QWidget(this);
//       QHBoxLayout *layout = new QHBoxLayout(container);

//       layout->setContentsMargins(0, 0, 0, 0);
//       layout->setSpacing(0);

//       layout->addWidget(view1);
//       //layout->addWidget(view2);

//       setCentralWidget(container);

//       QTimer *cameraTimer = new QTimer(this);

//       connect(cameraTimer, &QTimer::timeout, this, [=]()
//       {
//           view1->centerOn();
////           QPointF c1 = p1->pos();
////           QPointF c2 = p2->pos();

////           QRectF r1(c1.x() - 200, c1.y() - 300, 400, 600);
////           QRectF r2(c2.x() - 200, c2.y() - 300, 400, 600);

////           view1->setSceneRect(r1);
//////         view2->setSceneRect(r2);
//       });



//       cameraTimer->start(16);



}

MainWindow::~MainWindow()
{
}

