#include "window.h"

Window::Window() {
	button = new QPushButton;
	button->resize(100, 50);
	button->setText("Play");
	button->show();

	auto vlayout = new QVBoxLayout;
	vlayout->addWidget(button);
	setLayout(vlayout);

	audiobeep = new AudioBeep(this);
	connect(button, &QPushButton::clicked,
		this, &Window::playBeep);
}
