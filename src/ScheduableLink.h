#ifndef SCHEDULABLESCENELINKER_H
#define SCHEDULABLESCENELINKER_H

#include <thread>
#include <chrono>
#include <ctime>

#include "PipelineLink.h"
#include "BlockingQueue.h"


class SchedulableLink : public PipelineLink{
public:
    void NextScene(Scene s);
    virtual Scene ProcessScene(Scene s) = 0;
    void Start();
    void Stop();
    bool Available();
protected:
    void Enqueue(Scene s);
    void Run();
    BlockingQueue<Scene> scheduleQueue;
    bool isOn = true;
    std::thread scheduleWorker;
};


#endif 
