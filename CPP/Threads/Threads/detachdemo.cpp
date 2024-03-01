#include <iostream>
#include <thread>
using namespace std;
void thread1() {
    cout << "sravani likes chocolates" << endl;
}
int main() {
    thread t1(thread1);
    thread t2(thread1);
    // Main thread continues executing while the new thread is running
    cout << "Main Thread: Waiting for the thread to finish..." << endl;

    t1.detach();
    t2.detach();
    cout << " Thread has finished execution" << endl;

    return 0;
}

