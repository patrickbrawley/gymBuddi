#include "LinkSplitter.h"

// Implementation of the NextScene method

void LinkSplitter::NextScene(Scene s) {
     // Call the NextScene of the primary callback
    if(sceneCallback) sceneCallback->NextScene(s);
     // Call the NextScene of the secondary callback
    if(secondarySceneCallback) secondarySceneCallback->NextScene(s);
}
// Implementation of the Secondary Callback method
void LinkSplitter::RegisterSecondaryCallback(SceneCallback *scb) {
    secondarySceneCallback = scb;
}
