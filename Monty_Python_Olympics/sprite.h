#ifndef SPRITE_H
#define SPRITE_H
#include <QPixmap>

class Sprite
{
public:
    Sprite();
    Sprite(QString path, int fw, int fh, int count);
    void updateFrame();
    QPixmap getCurrentFrame();

private:
    QPixmap sheet;
    int frameWidth;
    int frameHeight;
    int frameCount;
    int currentFrame;
};

#endif // SPRITE_H
