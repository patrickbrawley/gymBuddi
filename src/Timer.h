#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>

#include "Scene.h"

//class that times how long the user can perform the exercise with good form

class Timer{
public:
    Timer();
    int GetGainz(std::string s, std::string task);
    void NewGainz();
protected:
    int count = 0;
};

#endif
