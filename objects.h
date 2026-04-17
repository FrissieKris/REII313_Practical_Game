#ifndef OBJECTS_H
#define OBJECTS_H

#include <QGraphicsPixmapItem>
#include "sprite.h"
#include <QGraphicsItem>


class Objects : public QGraphicsPixmapItem
{
public:
    Objects(QGraphicsItem* parent = nullptr);

    virtual void advance(int step) override
    {
        if (!step) return;
    }

    virtual bool isSolid() const { return false; }
    //virtual bool isConsumable() const { return false; }

    virtual void onCollision(Objects* other) {}

};

#endif // OBJECTS_H
