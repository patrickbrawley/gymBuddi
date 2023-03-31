#include "LinkSplitter.h"


//passes a scene onto the next link in the pipeline by calling the NextScene function of the sceneCallback member variable. It also passes the Scene object to another callback function (secondarySceneCallback).

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
