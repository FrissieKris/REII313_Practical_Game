#include "mainmenu.h"
#include <QFont>
#include <QGraphicsSceneMouseEvent>

MainMenu::MainMenu(QObject* parent) : QGraphicsScene(parent)
{
    setSceneRect(0, 0, 1920, 600);

    //Kan hierdie vervang met custom sprite

    title = new QGraphicsTextItem("MINTY PiTHAN\nOLYMPICS");
    title->setDefaultTextColor(Qt::yellow);
    title->setFont(QFont("Arial", 48, QFont::Bold));
    title->setPos(600, 100);
    addItem(title);

    auto* singleBtn = new QPushButton("SinglePlayer");
    singleBtn->setFixedSize(300, 60);
    auto* proxy1 = addWidget(singleBtn);
    proxy1->setPos(800, 280);

    auto* multiBtn = new QPushButton("Multiplayer");
    multiBtn->setFixedSize(300, 60);
    auto* proxy2 = addWidget(multiBtn);
    proxy2->setPos(800, 360);

    auto* quitBtn = new QPushButton("Quit");
    quitBtn->setFixedSize(300, 60);
    auto* proxy3 = addWidget(quitBtn);
    proxy3->setPos(800, 440);

    connect(singleBtn, &QPushButton::clicked, this, &MainMenu::startSinglePlayer);
    connect(multiBtn, &QPushButton::clicked, this, &MainMenu::startMultiplayer);
    connect(quitBtn, &QPushButton::clicked, this, &MainMenu::quitGame);


}
