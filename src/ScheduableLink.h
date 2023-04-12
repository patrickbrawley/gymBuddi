#ifndef SCHEDULABLESCENELINKER_H
#define SCHEDULABLESCENELINKER_H

#include <thread>
#include <chrono>
#include <ctime>

#include "PipelineLink.h"
#include "BlockingQueue.h"

// This class, extended from PipleineLink, is used to allow the video processing to be utalised without resulting in delays in the video stream to become laggy. Helps meet realtime requirements




class SchedulableLink : public PipelineLink{
public:
    void NextScene(Scene s); //this function adds scenes to the to the Blockingque
    virtual Scene ProcessScene(Scene s) = 0; //This is a pure virtual function (= 0) tallows other classes to define the processing behavior for the Scene object.
    void Start(); //This function starts a new method called Run() to process the scene. This is called by the scheduleWorker Thread
    void Stop(); //This function stops the thread
    bool Available(); //Checks if there is a Scene in the BlockingQueue
protected:
    void Enqueue(Scene s); //This function adds a Scene to the BlockingQueue.
    void Run();  //The scheduleWorker thread wakes up this method
    BlockingQueue<Scene> scheduleQueue;
    bool isOn = true;
    std::thread scheduleWorker; //the purpose of this thread is to run the Run() method in a separate thread so that schedualworker can continue processing scenes even while the main thread is busy with other tasks.
};


#endif 
