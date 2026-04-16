#ifndef TREE_H
#define TREE_H
#include "objects.h"
#include "sprite.h"

class Tree : public Objects
{
public:
    Tree();


void advance(int step);

private:
Sprite tree;
};

#endif // TREE_H
