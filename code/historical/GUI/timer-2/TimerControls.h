#ifndef TIMERCONTROLS_H
#define TIMERCONTROLS_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QLayout>
#include "CountUpTimer.h"

class TimerControls : public QWidget
{
    Q_OBJECT

public:
    TimerControls(QWidget *parent = nullptr);

private slots:
    void incrementLimit();
    void decrementLimit();
    void startTimer();
    void stopTimer();
    void toggleHold();

private:
    QPushButton *m_incrementButton;
    QPushButton *m_decrementButton;
    QPushButton *m_startButton;
    QPushButton *m_stopButton;
    QPushButton *m_holdButton;
    CountUpTimer *m_countUpTimer;
    int m_currentLimit;
   
};

#endif // TIMERCONTROLS_H
