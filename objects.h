#ifndef OBJECTS_H
#define OBJECTS_H

#include <QGraphicsPixmapItem>
#include "sprite.h"


class Objects: public QGraphicsPixmapItem
{
public:
    virtual void advance(int step) override
    {
        if (!step) return;
    }
};

#endif // OBJECTS_H
