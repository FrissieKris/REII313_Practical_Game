#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QPushButton>

class MainMenu : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MainMenu(QObject* parent = nullptr);

signals:
    void startSinglePlayer();
    void startMultiplayer();
    void quitGame();

private:
    QGraphicsTextItem* title = nullptr;
};

#endif // MAINMENU_H
