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

QRectF TimingBar::boundingRect() const
{
    return QRectF(0, 0, 220, 50);
}

void TimingBar::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    // Background track
    painter->fillRect(10, 15, 200, 10, Qt::darkGray);
    painter->setPen(Qt::white);
    painter->drawRect(10, 15, 200, 10);

    // Good zone (wider, yellow)
    int goodLeft = 10 + static_cast<int>(200 * goodZoneStart);
    int goodWidth = static_cast<int>(200 * (goodZoneEnd - goodZoneStart));
    painter->fillRect(goodLeft, 12, goodWidth, 16, QColor(255, 255, 0, 80));

    // Perfect zone (small, green)
    int perfLeft = 10 + static_cast<int>(200 * perfectZoneStart);
    int perfWidth = static_cast<int>(200 * (perfectZoneEnd - perfectZoneStart));
    painter->fillRect(perfLeft, 10, perfWidth, 20, QColor(0, 255, 0, 120));

    // Moving indicator
    int indicatorX = 10 + static_cast<int>(200 * position);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawLine(indicatorX, 8, indicatorX, 28);

    // Result text
    if (resultDisplayFrames > 0) {
        QString text;
        QColor col;
        if (lastResult == TimingResult::Perfect) { text = "PERFECT!"; col = Qt::green; }
        else if (lastResult == TimingResult::Good) { text = "GOOD"; col = Qt::yellow; }
        else if (lastResult == TimingResult::Miss) { text = "MISS"; col = Qt::red; }

        painter->setPen(col);
        painter->setFont(QFont("Arial", 12, QFont::Bold));
        painter->drawText(10, 45, 200, 20, Qt::AlignCenter, text);
    }
}

