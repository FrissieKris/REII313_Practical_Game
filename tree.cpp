#include "tree.h"

Tree::Tree()
    :tree(":/sprites/Trees/Trees.png", 1822, 2032, 0, 3)
{

    setPixmap(tree.getCurrentFrame());
}


void Tree::advance(int step)
{
    if (!step) return;
}
