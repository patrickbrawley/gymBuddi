#ifndef SCENELINKER_H
#define SCENELINKER_H

#include "SceneCallback.h"

//This class is a subclass of the SceneCallback class and provides an implementation for registering and invoking scene callbacks in a pipeline.

//The PipelineLink class inherits from the SceneCallback class and implements its "NextScene" method as a protected method. 
//The private member variable "sceneCallback" that is a pointer to a SceneCallback object.
class PipelineLink : public SceneCallback{
public:
    // allows the user to register a new SceneCallback function to the PipelineLink object.
    void RegisterCallback(SceneCallback* scb);

protected:
    //invokes the registered callback function.
    void NextScene(Scene scene);
    SceneCallback* sceneCallback = nullptr;
};

#endif
