#include "sprite.h"

Sprite::Sprite()
{

}

//Set the path, width, height, offset which is layer 0,1,.. and so forth and count is how many images in a row
Sprite::Sprite(QString path, int fw, int fh, int offset, int count)
    : frameWidth(fw),
      frameHeight(fh),
      frameOffset(offset),
      frameCount(count),
      currentFrame(0)
{
    sheet = QPixmap(path);
}

//Set the path, width, height, offset which is layer 0,1,.. and so forth and count is how many images in a row
//Will check if the constructor is necessary because below is same
void Sprite::loadFrame(QString path, int fw, int fh, int offset, int count)
{
     sheet = QPixmap(path);

     frameWidth = fw;
     frameHeight = fh;
     frameOffset = offset;
     frameCount = count;

     currentFrame = 0;


}

//Called to move the index of the referenced frame
void Sprite::updateFrame()
{
      currentFrame = (currentFrame + 1) % frameCount;
}


//Copy the sheet to the size of the sprite frame
QPixmap Sprite::getCurrentFrame()
{
   int x = currentFrame * frameWidth;
   int y = frameHeight * frameOffset;
   return sheet.copy(x, y, frameWidth, frameHeight);

}
