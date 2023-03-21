#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <stdio.h>

#include "Scene.h"

class ProgressBar{
public:
    ProgressBar();
    int GetProgress(std::string s, std::string task);
    void ResetProgress();
    void SetThreshold(int thres);
protected:
    int threshold;
    int count = 0;
};

#endif
