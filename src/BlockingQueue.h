#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H
#include <deque>
#include <mutex>
#include <condition_variable>
#include "Scene.h"


template <typename T>

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
