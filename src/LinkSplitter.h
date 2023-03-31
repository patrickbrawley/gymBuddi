#ifndef SCENELINKER_H
#define SCENELINKER_H

#include "PipelineLink.h"

//subclass of PipelineLink and is used to split a pipeline into two separate pipelines by registering a secondary scene callback function. 
//When a scene is passed through the NextScene function, it will be passed on to both the primary and secondary scene callback functions for further processing. 
//This allows the same scene to be processed in two different ways at the same time.
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
