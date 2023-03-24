#include "audiobeep.h"
#include <QVBoxLayout>
#include <QPushButton>

class Window : public QWidget
{
	Q_OBJECT

public:
	Window();

private:
	void playBeep() {
		audiobeep->play();
	}

	QPushButton* button;
	AudioBeep* audiobeep;
};
