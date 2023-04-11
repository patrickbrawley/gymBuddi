#ifndef COUNTUPTIMER_H
#define COUNTUPTIMER_H

#include <QObject>
#include <QTimer>
#include <functional>

class CountUpTimer : public QObject
{
    Q_OBJECT

public:
    CountUpTimer(QObject *parent = nullptr);

    void start(int startValue, int endValue, int increment, std::function<void(int)> updateCallback, std::function<void()> finishedCallback);
    void stop();

private slots:
    void incrementTimer();

private:
    QTimer m_timer;
    int m_startValue;
    int m_endValue;
    int m_increment;
    std::function<void(int)> m_updateCallback;
    std::function<void()> m_finishedCallback;
    int m_currentValue;
};

#endif // COUNTUPTIMER_H
