#include "tree.h"

Tree::Tree()
    :tree(":/Sprites/Sprites/Trees/Tree", 256, 256, 0, 1)
{

    setPixmap(tree.getCurrentFrame());

}


void Tree::advance(int step)
{
//    if (!step) return;
//    tree.updateFrame();
//    setPixmap(tree.getCurrentFrame());
//
}

QRectF Tree::boundingRect() const
{
     return QRectF(0, 0, 256, 256);
}

QPainterPath Tree::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 256, 256); // same size as boundingRect
    return path;
}
