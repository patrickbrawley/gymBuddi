#include "countuptimer.h"

CountUpTimer::CountUpTimer(QObject *parent) : QObject(parent)
{
    connect(&m_timer, &QTimer::timeout, this, &CountUpTimer::incrementTimer);
}

void CountUpTimer::start(int startValue, int endValue, int increment, std::function<void(int)> updateCallback, std::function<void()> finishedCallback)
{
    m_startValue = startValue;
    m_endValue = endValue;
    m_increment = increment;
    m_updateCallback = updateCallback;
    m_finishedCallback = finishedCallback;
    m_currentValue = startValue;

    m_timer.start(1000); // start the timer with a 1 second interval
}

void CountUpTimer::stop()
{
    m_timer.stop();
}

void CountUpTimer::incrementTimer()
{
    m_currentValue += m_increment;
    m_updateCallback(m_currentValue);

    if (m_currentValue >= m_endValue) {
        m_timer.stop();
        m_finishedCallback();
    }
}
