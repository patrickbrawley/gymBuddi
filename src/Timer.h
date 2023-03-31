#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>

#include "Scene.h"

class Timer{
public:
    Timer();
    int GetProgress(std::string s, std::string task);
    void ResetProgress();
protected:
    int count = 0;
};

#endif
