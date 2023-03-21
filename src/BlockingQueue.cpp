#include "BlockingQueue.h"

template <typename T>
T BlockingQueue<T>::Pop() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [=]{ return !internalQueue.empty(); });
    T ret = internalQueue.back();
    internalQueue.pop_back();
    return ret;
}

template <typename T>
bool BlockingQueue<T>::IsEmpty(){
    return internalQueue.empty();
}

template <typename T>
int BlockingQueue<T>::Size(){
    return internalQueue.size();
}


template <typename T>
void BlockingQueue<T>::Push(T toPush) {
    {
        internalQueue.push_front(toPush);
    }
    condition.notify_all();
}
