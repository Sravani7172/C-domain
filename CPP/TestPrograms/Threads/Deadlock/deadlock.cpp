#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mutex1,mutex2;
void Thread1(){
	lock_guard<mutex>lock1(mutex1);
	cout<<"Thread1 is acquried mutex1"<<endl;
	this_thread::sleep_for(chrono::seconds(2));
	lock_guard<mutex>lock2(mutex2);
	//cout<<"Thread1 is acquried mutex1"<<endl;
	cout<<"Thread1 is acquried mutex2"<<endl;
}
void Thread2(){
	lock_guard<mutex>lock2(mutex2);
	cout<<"Thread2 is acquried mutex2"<<endl;
	this_thread::sleep_for(chrono::seconds(3));
	lock_guard<mutex>lock1(mutex1);
	//cout<<"Thread2 is acquried mutex2"<<endl;
	cout<<"Thread2 is acquried mutex1"<<endl;
}
int main(){
	thread t1(Thread1);
	thread t2(Thread2);
	t1.join();
	t2.join();
	return 0;
}
