#define X0 0.25f
#define Y0 0.25f
#define X1 0.75f
#define Y1 0.75f

// contains configuration settings for the preprocessor component.
//  struct used to define the relative coordinates of a bounding box that is used for preprocessing a scene to be passed down the pipeline.

struct PreProcessorSettings{
    //This default constructor initialises the relativeBoundingBox array with the values defined earlier.
    PreProcessorSettings(){
        relativeBoundingBox[0] = X0;
        relativeBoundingBox[1] = Y0;
        relativeBoundingBox[2] = X1;
        relativeBoundingBox[3] = Y1;
    }
    
    //This copy constructor copies the values of the relativeBoundingBox array.
    PreProcessorSettings(const PreProcessorSettings& cpy){
        relativeBoundingBox[0] = cpy.relativeBoundingBox[0];
        relativeBoundingBox[1] = cpy.relativeBoundingBox[1];
        relativeBoundingBox[2] = cpy.relativeBoundingBox[2];
        relativeBoundingBox[3] = cpy.relativeBoundingBox[3];
    }
    float relativeBoundingBox[4];
};
