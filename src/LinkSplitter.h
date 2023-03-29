#ifndef SCENELINKER_H
#define SCENELINKER_H

#include "PipelineLink.h"

// Declare the LinkSplitter class which extends the PipelineLink. NextScene is copied and added to another element. 
class LinkSplitter : public PipelineLink{
public:
    // Public method to handle the next scene in the pipeline
    void NextScene(Scene s);
    // Public method to register a secondary callback
    void RegisterSecondaryCallback(SceneCallback* scb);
public:
    // Public member variable to store the secondary callback
    SceneCallback* secondarySceneCallback = nullptr;
    
};


#endif
