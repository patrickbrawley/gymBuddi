#include "PipelineLink.h"

// Register a new callback function for the scene.
void PipelineLink::RegisterCallback(SceneCallback *scb) {
    sceneCallback = scb;
}

// Call the next scene callback function.
void PipelineLink::NextScene(Scene scene) {
    // If no callback function is registered, simply return.
    if(!sceneCallback) return;
    // Otherwise, call the registered callback function.
    sceneCallback->NextScene(scene);
}
