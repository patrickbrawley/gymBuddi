#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H
#include <deque>
#include <mutex>
#include <condition_variable>
#include "Scene.h"

//T is a template parameter that can represent any type of data, eg integers or scenes.
template <typename T>

// BlockingQueue Class
//The Push, Pop, IsEmpty, and Size functions provide a thread-safe way that allows elements to be added to one end of the queue and removed from the other end and check the queues status. 


class BlockingQueue {
public:
    void Push(T toPush);
    T Pop();
    bool IsEmpty();
    int Size();
private:
    std::deque<T> internalQueue;
    std::mutex mutex;
    std::condition_variable condition;
};


#endif 
