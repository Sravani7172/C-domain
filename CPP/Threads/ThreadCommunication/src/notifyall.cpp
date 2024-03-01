#include "notifyall.h"
using namespace std;
mutex mtx;
condition_variable cv;
bool ready = false;

void thread1() {
    unique_lock<mutex> lock(mtx);
    this_thread::sleep_for(chrono::seconds(2));
    ready = true;
    cout << "thread1 is running" << endl;
    cout << "thread ID: " << this_thread::get_id() << endl;
    cv.notify_all();
}

void thread2() {
    unique_lock<mutex> lock(mtx);
    while (!ready) {
        cv.wait(lock);
    }
    this_thread::sleep_for(chrono::seconds(1));
    cout << "thread2 is running" << endl;
    cout << "thread ID: " << this_thread::get_id() << endl;
}

void thread3() {
    unique_lock<mutex> lock(mtx);
    while (!ready) {
        cv.wait(lock);
    }
    this_thread::sleep_for(chrono::seconds(2));
    cout << "thread3 is running" << endl;
    cout << "thread ID: " << this_thread::get_id() << endl;
}

