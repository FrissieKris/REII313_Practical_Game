#ifndef TREE_H
#define TREE_H
#include "objects.h"
#include "sprite.h"

class Tree : public Objects
{
public:
    Tree();


    void advance(int step) override;
    bool isSolid() const override { return true; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    //void applyEffect(Player* player) override;

private:
    Sprite tree;

};

#endif // TREE_H
