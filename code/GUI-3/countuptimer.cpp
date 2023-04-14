#include "countuptimer.h"


// Constructor for countuptimer class
CountUpTimer::CountUpTimer(QObject *parent) : QObject(parent)
{
    // Connect the timeout signal of m_timer to the increment slot of the object
    connect(&m_timer, &QTimer::timeout, this, &CountUpTimer::incrementTimer);
}


// Method to start the count up timer with the parameters and callbacks
void CountUpTimer::start(int startValue, int endValue, int increment, std::function<void(int)> updateCallback, std::function<void()> finishedCallback)
{
    // Initalize the member varialbes
    m_startValue = startValue;
    m_endValue = endValue;
    m_increment = increment;
    m_updateCallback = updateCallback;
    m_finishedCallback = finishedCallback;
    m_currentValue = startValue;

    // Start the timer with a 1 second interval
    m_timer.start(1000); 
}

// Method to stop the count up timer
void CountUpTimer::stop()
{
    // stop the timer
    m_timer.stop();
}

// Method to increment the count up timer and call the update callback
void CountUpTimer::incrementTimer()
{
    
    // Increment the current value with the set increment
    m_currentValue += m_increment;
    
    // Call the update callback with the current value
    m_updateCallback(m_currentValue);

    // Check if the current vlaue has reached the end value
    if (m_currentValue >= m_endValue) {
        
        // Stop the timer
        m_timer.stop();

        // Call the finish callback
        m_finishedCallback();
    }
}
