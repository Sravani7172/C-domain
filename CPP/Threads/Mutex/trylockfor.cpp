#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
timed_mutex m;
int amount=0;
void increment(int i){
	if(m.try_lock_for(chrono::seconds(2))){
		amount++;
		this_thread::sleep_for(chrono::seconds(3));
		cout<<"thread "<<i<<" entered"<<endl;
		m.unlock();
	}
	else{
		cout<<"thread "<<i<<" not entered"<<endl;
	}
}
int main(){
	thread t1(increment,2);
	thread t2(increment,3);
	t1.join();
	t2.join();
	cout<<amount<<endl;
	return 0;
}
