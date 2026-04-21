#include "ninjastar.h"
#include "player.h"


NinjaStar::NinjaStar()
    :ninjaStar(":/Sprites/Sprites/NinjaStar/NinjaStar-Sheet.png", 64, 64, 0, 1)
{

     setPixmap(ninjaStar.getCurrentFrame());
     state = Unused;

}

void NinjaStar::applyEffect(class Player *player)
{

   player->itemPickedUp = true;
   state = Collected;
   scene()->removeItem(this);
   this->deleteLater();
}

QRectF NinjaStar::boundingRect() const
{
    return QRectF(0, 0, 64, 64);
}


void NinjaStar::advance(int step)
{
    if (!step) return;

    switch (state)
    {
        case Unused:
        //ninjaStar.updateFrame();
        setPixmap(ninjaStar.getCurrentFrame());
            // static or slow spin
        break;


        case Collected:
            // nothing (waiting for deletion)
        break;


    }
}
