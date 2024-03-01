#ifndef PRODUCER_CONSUMER_H
#define PRODUCER_CONSUMER_H
#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <condition_variable>
using namespace std;
class ProducerConsumer {
public:
    ProducerConsumer(int bufferSize);
    void Producer(int value);
    void Consumer();
private:
    mutex mtx;
    condition_variable cv;
    deque<int> buffer;
    int maxBufferSize;
    bool productionComplete;
};
#endif

