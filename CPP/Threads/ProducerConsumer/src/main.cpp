#include "producerconsumer.h"
#include <iostream>
using namespace std;
int main() {
    ProducerConsumer pc(20); 
    thread t1(&ProducerConsumer::Producer, &pc, 30);
    thread t2(&ProducerConsumer::Consumer, &pc);
    t1.join();
    t2.join();
    return 0;
}

