#include "CountUpTimer.h"

CountUpTimer::CountUpTimer(QObject *parent) : QObject(parent)
{
    m_hold = false;
}

void CountUpTimer::start(int min, int max, int step,
                          const std::function<void(int)> &onUpdate,
                          const std::function<void()> &onFinish)
{
    m_min = min;
    m_max = max;
    m_step = step;
    m_value = min;
    m_onUpdate = onUpdate;
    m_onFinish = onFinish;

    m_timer.start(1000);
    connect(&m_timer, &QTimer::timeout, this, &CountUpTimer::timerTick);
}

void CountUpTimer::stop()
{
    m_timer.stop();
}

bool CountUpTimer::isActive() const
{
    return m_timer.isActive();
}

int CountUpTimer::value() const
{
    return m_value;
}

void CountUpTimer::setHold(bool hold)
{
    m_hold = hold;
}

bool CountUpTimer::isHold() const
{
    return m_hold;
}

void CountUpTimer::timerTick()
{
    if (!m_hold) {
        m_value += m_step;
        if (m_value > m_max) {
            m_value = m_max;
            m_timer.stop();
            if (m_onFinish) {
                m_onFinish();
            }
        } else {
            m_onUpdate(m_value);
        }
    }
}
