//This code provides the implementation for a Blocking Queue, 
//which is a data structure that allows one thread to push elements into the queue 
//while another thread waits until there is an element available to pop. 
//The implementation is based on a deque and uses a mutex and a condition variable to ensure thread safety.

#include "BlockingQueue.h"

// Pop an element from the blocking queue
template <typename T>
T BlockingQueue<T>::Pop() {
    std::unique_lock<std::mutex> lock(mutex); // Lock the mutex so other threads cannot access the data. Data blocked untill mutex is released.
    condition.wait(lock, [=]{ return !internalQueue.empty(); }); // Wait until the queue is not empty
    T ret = internalQueue.back();  // Get the last element of the queue
    internalQueue.pop_back(); // Remove the last element from the queue
    return ret; // Return the removed element from the queue
}
// Check if the blocking queue is empty
template <typename T>
bool BlockingQueue<T>::IsEmpty(){
    return internalQueue.empty(); // Check if the internal queue is empty and returns a boolean value. True if empty, false if not
}

// Get the size of the queue
template <typename T>
int BlockingQueue<T>::Size(){
    return internalQueue.size();  // Return the size of the internal queue
}

// adds an element into the queue
template <typename T>
void BlockingQueue<T>::Push(T toPush) {
    {
        internalQueue.push_front(toPush); // Add the element to the front of the queue
    }
    condition.notify_all(); // Notify all waiting threads that an element has been added to the queue
}
