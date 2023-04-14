#include "TimerControls.h"

#include <QDebug>


TimerControls::TimerControls(QWidget *parent) : QWidget(parent)
{
    m_incrementButton = new QPushButton("+", this);
    connect(m_incrementButton, &QPushButton::clicked, this, &TimerControls::incrementLimit);

    m_decrementButton = new QPushButton("-", this);
    connect(m_decrementButton, &QPushButton::clicked, this, &TimerControls::decrementLimit);

    m_startButton = new QPushButton("Start", this);
    connect(m_startButton, &QPushButton::clicked, this, &TimerControls::startTimer);

    m_stopButton = new QPushButton("Stop", this);
    connect(m_stopButton, &QPushButton::clicked, this, &TimerControls::stopTimer);

    m_holdButton = new QPushButton("Hold", this);
    connect(m_holdButton, &QPushButton::clicked, this, &TimerControls::toggleHold);

    m_countUpTimer = new CountUpTimer(this);
    m_currentLimit = 60;


}

void TimerControls::incrementLimit()
{
    m_currentLimit += 10;
    m_countUpTimer->start(0, m_currentLimit, 1,
        [](int value) { qDebug() << "Counting up:" << value; },
        []() { qDebug() << "Count up finished!"; });
}

void TimerControls::decrementLimit()
{
    m_currentLimit -= 10;
    if (m_currentLimit < 0) {
        m_currentLimit = 0;
    }
    m_countUpTimer->start(0, m_currentLimit, 1,
        [](int value) { qDebug() << "Counting up:" << value; },
        []() { qDebug() << "Count up finished!"; });
}

void TimerControls::startTimer()
{
    m_countUpTimer->start(0, m_currentLimit, 1,
        [](int value) { qDebug() << "Counting up:" << value; },
        []() { qDebug() << "Count up finished!"; });
}

void TimerControls::stopTimer()
{
    m_countUpTimer->stop();
}

void TimerControls::toggleHold()
{
    m_countUpTimer->setHold(!m_countUpTimer->isHold());
}




