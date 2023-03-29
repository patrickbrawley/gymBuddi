#include <opencv2/core.hpp>
#include "Scene.h"
#include "PipelineLink.h"
#include "PreProcessorSettings.h"


//This class processes an input scene, then it is passed on to the next component in the pipeline.

class PreProcessor : public PipelineLink{
public:
    PreProcessor();
    PreProcessor(PreProcessorSettings settings);
    void NextScene(Scene scene);
    void SetBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY);
    
private:
    //private member function that draws a box or rectangle on the input image based on the bounding box coordinates and converts the scene from RGB to BGR color format to allow the Neural Network to read the scene. 
    Scene drawBox(Scene s);
    Scene switchRGB2BGR(Scene s);
    PreProcessorSettings settings;
};
