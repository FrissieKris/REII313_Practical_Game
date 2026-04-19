#ifndef OBJECTS_H
#define OBJECTS_H

#include <QGraphicsPixmapItem>
#include "sprite.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>


class Objects : public QObject, public QGraphicsPixmapItem
{
public:
    Objects(QGraphicsItem* parent = nullptr);
    virtual ~Objects() = default;


    virtual void advance(int step) {};


    virtual bool isSolid() const { return false; }
    //virtual bool isConsumable() const { return false; }

    //virtual void onCollision(Objects* other) {}
    virtual void applyEffect(class Player* player) {};

};

#endif // OBJECTS_H
