#ifndef SCENECALLBACK_H
#define SCENECALLBACK_H

#include "Scene.h"

//this class provides a way to pass scenes through a pipleline to allow the camera stream to be processed by the Neural retwork and the other methods present in 'scene.h'

class SceneCallback{
public:
    // NextScene is a pure virtual function, (becuase = 0) 
    //this allows any class that implements NextScene to provide its own implementation for handling the Scene passed down the pipeline
    //Nextscene ensures that the SceneCallback interface is used consistently throughout the video processing architecture, 
    //and it allows for greater flexibility in how different parts of the pipeline can be implemented.
    virtual void NextScene(Scene next) = 0;
};

#endif
