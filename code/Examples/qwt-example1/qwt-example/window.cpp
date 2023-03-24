#include "window.h"

#include <cmath>  // for sine stuff


Window::Window()
{
	// set up the thermometer
	thermo = new QwtThermo; 
	thermo->setFillBrush( QBrush(Qt::darkYellow) );
	thermo->setScale(0, 100);
	thermo->show();


	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData[index] = 0;
	}

	curve = new QwtPlotCurve;
	plot = new QwtPlot;
	// make a plot curve from the data and attach it to the plot
	curve->setSamples(xData, yData, plotDataSize);
	curve->attach(plot);

	plot->replot();
	plot->show();

	button1 = new QPushButton("Reset");
	// see https://doc.qt.io/qt-5/signalsandslots-syntaxes.html
	connect(button1,&QPushButton::clicked,this,&Window::reset);

	button2 = new QPushButton("Something else");
	// see https://doc.qt.io/qt-5/signalsandslots-syntaxes.html
	connect(button2,&QPushButton::clicked,this,&Window::reset);

	// set up the layout - button above thermometer
	vLayout = new QVBoxLayout();
	vLayout->addWidget(button1);
	vLayout->addWidget(button2);
	vLayout->addWidget(thermo);

	// plot to the left of button and thermometer
	hLayout = new QHBoxLayout();
	hLayout->addLayout(vLayout);
	hLayout->addWidget(plot);

	setLayout(hLayout);
}

void Window::reset() {
	// set up the initial plot data
	for( int index=0; index<plotDataSize; ++index )
	{
		xData[index] = index;
		yData[index] = 0;
	}
}


void Window::timerEvent( QTimerEvent * )
{
	double inVal = gain * sin( M_PI * count/5.0 );
	++count;

	// add the new input to the plot
	std::move( yData, yData + plotDataSize - 1, yData+1 );
	yData[0] = inVal;
	curve->setSamples(xData, yData, plotDataSize);
	plot->replot();

	// set the thermometer value
	thermo->setValue( fabs(inVal) );
}
