#ifndef COUNTUPTIMER_H
#define COUNTUPTIMER_H

#include <QObject>
#include <QTimer>

class CountUpTimer : public QObject
{
    Q_OBJECT
public:
    explicit CountUpTimer(QObject *parent = nullptr);

    void start(int min, int max, int step,
        const std::function<void(int)> &onUpdate,
        const std::function<void()> &onFinish = nullptr);

    void stop();
    bool isActive() const;
    int value() const;

    void setHold(bool hold);
    bool isHold() const;

private slots:
    void timerTick();

private:
    QTimer m_timer;
    int m_min;
    int m_max;
    int m_step;
    int m_value;
    bool m_hold;
    std::function<void(int)> m_onUpdate;
    std::function<void()> m_onFinish;
};

#endif // COUNTUPTIMER_H
