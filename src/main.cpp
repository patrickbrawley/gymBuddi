#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <stdio.h>
#include <queue>

#include "Camera.h"
#include "CNNProcessor.h"
#include "stdlib.h"
#include "PreProcessor.h"
#include "gymBuddi.h"
#include "LinkSplitter.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
    gymBuddi::welcomeMessage();
    

    //make pipeline components
    CameraSettings cameraSettings;
    Camera camera(cameraSettings);
    PreProcessorSettings preProcessorSettings;
    PreProcessor preProcessor(preProcessorSettings);
    LinkSplitter linkSplitter;
    CNNProcessorSettings cnnSettings;
    CNNProcessor cnn(cnnSettings);
    
    //register callbacks (link pipeline)
    camera.RegisterCallback(&preProcessor);
    preProcessor.RegisterCallback(&linkSplitter);
    linkSplitter.RegisterCallback(&cnn);
    linkSplitter.RegisterSecondaryCallback(&gui);
    cnn.RegisterCallback(&gui);
    
    //start camera and cnn
    cnn.Start();
    camera.Start();
    
    //stop camera and cnn
    camera.Stop();
    cnn.Stop();
    
    //exit
    return 0;
}
