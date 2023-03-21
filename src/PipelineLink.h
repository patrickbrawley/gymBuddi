#ifndef SCENELINKER_H
#define SCENELINKER_H

#include "SceneCallback.h"


class PipelineLink : public SceneCallback{
public:
    void RegisterCallback(SceneCallback* scb);

protected:
    void NextScene(Scene scene);
    SceneCallback* sceneCallback = nullptr;
};

#endif
