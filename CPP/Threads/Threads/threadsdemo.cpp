#include <iostream>
#include <thread>
using namespace std;
void thread1() {
    cout << "sravani likes chocolates" << endl;
}
int main() {
    thread t(thread1); 
    cout << "Main Thread: Waiting for the thread to finish..." << endl;

    t.join(); // Wait for the thread to finish its execution

    cout << " Thread has finished execution" << endl;

    return 0;
}

