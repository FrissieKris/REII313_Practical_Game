#include "timingbar.h"
#include "player.h"

TimingBar::TimingBar(QGraphicsItem* parent) : QGraphicsItem(parent)
{
    setZValue(15);
}

void TimingBar::activate(float playerSpeedFactor)
{
    active = true;
    position = 0.0f;
    direction = 1.0f;
    lastResult = TimingResult::None;
    resultDisplayFrames = 0;

    speed = 0.018f + (0.015f * playerSpeedFactor);
    float zoneShrink = 1.0f / (1.0f + playerSpeedFactor * 0.8f);

    perfectZoneStart = 0.5f - (0.5f * zoneShrink);
    perfectZoneEnd = 0.5f + (0.05f * zoneShrink);

    goodZoneStart = 0.5f - (0.20f * zoneShrink);
    goodZoneEnd = 0.5f + (0.20f * zoneShrink);

    update();
}


void TimingBar::deactivate()
{
    active = false;
    update();
}

bool TimingBar::isActive() const
{
    return active;
}

TimingResult TimingBar::evaluateHit()
{
    if (!active) return TimingResult::None;

    if (position >= perfectZoneStart && position <= perfectZoneEnd)
        return TimingResult::Perfect;
    else if (position >= goodZoneStart && position <= goodZoneEnd)
        return TimingResult::Good;
    else
        return TimingResult::Miss;
}

void TimingBar::showResult(TimingResult result)
{
    lastResult = result;
    resultDisplayFrames = 45;
    update();
}

void TimingBar::advance(int step)
{
    if(!step || !active)
        return;

    position += speed * direction;

    if(position >= 1.0f)
    {
        position = 1.0f;
        direction = -1.0f;
    }
    else if(position <= 0.0f)
    {
        position = 0.0f;
        direction = 1.0f;
    }

    if(resultDisplayFrames > 0)
        resultDisplayFrames--;
    update();

}


