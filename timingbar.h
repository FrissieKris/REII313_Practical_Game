#ifndef TIMINGBAR_H
#define TIMINGBAR_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

enum class TimingResult {Perfect, Good, Miss, None};

class TimingBar : public QGraphicsItem
{
public:
    explicit TimingBar(QGraphicsItem* parent = nullptr);

    TimingResult evaluateHit();
    QRectF boundingRect() const override;
    float getCurrentSpeedFactor();
    bool isActive() const;

    void showResult(TimingResult result);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void activate(float playerSpeedFactor = 1.0f);
    void deactivate();
    void advance(int step) override;


private:

    TimingResult lastResult = TimingResult::None;
    float position = 0.0f;      // 0.0 to 1.0 (normalized)
    float speed = 0.02f;        // pixels per frame normalized
    float direction = 1.0f;

    float perfectZoneStart = 0.45f;
    float perfectZoneEnd   = 0.55f;
    float goodZoneStart    = 0.30f;
    float goodZoneEnd      = 0.70f;

    int resultDisplayFrames = 0;

    bool active = false;

    class Player* linkedPlayer = nullptr;
};

#endif // TIMINGBAR_H
