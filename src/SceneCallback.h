#ifndef SCENECALLBACK_H
#define SCENECALLBACK_H

#include "Scene.h"

class SceneCallback{
public:
    virtual void NextScene(Scene next) = 0;
};

#endif
