#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m1,m2;
void task1(){
	while(1){
		lock(m1,m2);
		cout<<"task1\n";
		m1.unlock();
		m2.unlock();
	}
}
void task2(){
	while(1){
		lock(m2,m1);
		cout<<"task2\n";
		m2.unlock();
		m1.unlock();
	}
}
int main(){
	thread t1(task1);
	thread t2(task2);
	t1.join();
	t2.join();
	return 0;
}	
