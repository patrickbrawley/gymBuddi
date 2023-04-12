#include "repcounter.h"

RepCounter::RepCounter(QObject* parent)
    : QObject(parent)
    , m_counter(0)
{
}

int RepCounter::counter() const
{
    return m_counter;
}

bool RepCounter::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Space)
        {
            ++m_counter;
            emit counterChanged(m_counter);
        }
    }

    // Pass the event on to the parent class for normal processing
    return QObject::eventFilter(watched, event);
}
