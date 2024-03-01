#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mutex1, mutex2;

void Thread1() {
    unique_lock<mutex> lock1(mutex1, defer_lock);
    unique_lock<mutex> lock2(mutex2, defer_lock);
    std::lock(mutex1, mutex2); // locked two mutexes
    cout << "Thread1 acquired mutex1, mutex2" << endl;
}

void Thread2() {
    unique_lock<mutex> lock1(mutex1, defer_lock);
    unique_lock<mutex> lock2(mutex2, defer_lock);
    std::lock(mutex1, mutex2); // locked two mutexes in the same order
    cout << "Thread2 acquired mutex1, mutex2" << endl;
}

int main() {
    thread t1(Thread1);
    thread t2(Thread2);
    t1.join();
    t2.join();
    return 0;
}
	

