#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(QString path, int fw, int fh, int offset, int count)
    : frameWidth(fw),
      frameHeight(fh),
      frameOffset(offset),
      frameCount(count),
      currentFrame(0)
{
    sheet = QPixmap(path);
}

void Sprite::loadFrame(QString path, int fw, int fh, int offset, int count)
{
     sheet = QPixmap(path);

     frameWidth = fw;
     frameHeight = fh;
     frameOffset = offset;
     frameCount = count;

     currentFrame = 0;


}
void Sprite::updateFrame()
{
      currentFrame = (currentFrame + 1) % frameCount;
}


QPixmap Sprite::getCurrentFrame()
{
   int x = currentFrame * frameWidth;
   int y = frameHeight * frameOffset;
   return sheet.copy(x, y, frameWidth, frameHeight);

}
