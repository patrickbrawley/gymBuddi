#include <QObject>
#include <QKeyEvent>

class RepCounter : public QObject
{
    Q_OBJECT

public:
    RepCounter(QObject* parent = nullptr)
        : QObject(parent)
        , m_counter(0)
    {
    }

    int counter() const { return m_counter; }

signals:
    void counterChanged(int newCounter);

protected:
    bool eventFilter(QObject* watched, QEvent* event) override
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

private:
    int m_counter;
};
