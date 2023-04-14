#ifndef COUNTUPTIMER_H
#define COUNTUPTIMER_H

#include <QObject>
#include <QTimer>
#include <functional>


// Declare the CountUptimer class as an QObject
class CountUpTimer : public QObject
{
    Q_OBJECT

public:
    // Constructor that takes a QObject pointer as a parent
    CountUpTimer(QObject *parent = nullptr);

    // Method to start the timer with given parameters and callbacks
    void start(int startValue, int endValue, int increment, std::function<void(int)> updateCallback, std::function<void()> finishedCallback);
    
    // Method to stop timer
    void stop();

private slots:
    // Slots to incement the timer value
    void incrementTimer();

private:

    // Timer object to control the timeing of the count up 
    QTimer m_timer;

    // Start value of the count up
    int m_startValue;

    // End value of the count up
    int m_endValue;

    // Increment value for each count up step
    int m_increment;
    
    // Callback function to be called on each update
    std::function<void(int)> m_updateCallback;
    
    // Callback function to be called when the count up is finished
    std::function<void()> m_finishedCallback;

    //current count up value
    int m_currentValue;
};

#endif // COUNTUPTIMER_H
