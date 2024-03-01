#include "notifyall.h"
#include<thread>
using namespace std;
int main() {
    thread t1(thread1);
    thread t2(thread2);
    thread t3(thread3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

