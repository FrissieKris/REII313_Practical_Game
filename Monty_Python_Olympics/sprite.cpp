#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(QString path, int fw, int fh, int count)
    : frameWidth(fw),
      frameHeight(fh),
      frameCount(count),
      currentFrame(0)
{
    sheet = QPixmap(path);
}
void Sprite::updateFrame()
{
      currentFrame = (currentFrame + 1) % frameCount;

}

QPixmap Sprite::getCurrentFrame()
{
   int x = currentFrame * frameWidth;
   return sheet.copy(x, 0, frameWidth, frameHeight);

}
