#include "producerconsumer.h"
using namespace std;
ProducerConsumer::ProducerConsumer(int bufferSize) : maxBufferSize(bufferSize), productionComplete(false) {}

void ProducerConsumer::Producer(int value) {
    while(value){
        unique_lock<mutex> lock(mtx);
        if(buffer.size() >= maxBufferSize){
            cv.wait(lock);
        }
        buffer.push_back(value);
        cout << "Producer: " << value << endl;
        value--;
        lock.unlock();
        cv.notify_one();
    }
    // Notify consumers that production is complete
    productionComplete = true;
    cv.notify_all();
}

void ProducerConsumer::Consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        if (buffer.size() == 0) {
            if (productionComplete) {
                break;
            }
            cv.wait(lock);
        }
        int value = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << value << endl;
        lock.unlock();
        cv.notify_one();
    }
}

