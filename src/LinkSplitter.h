#ifndef SCENELINKER_H
#define SCENELINKER_H

#include "PipelineLink.h"


class LinkSplitter : public PipelineLink{
public:
    void NextScene(Scene s);
    void RegisterSecondaryCallback(SceneCallback* scb);
public:
    SceneCallback* secondarySceneCallback = nullptr;
    
};


#endif
