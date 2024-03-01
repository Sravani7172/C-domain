#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;
recursive_mutex m1;
int buffer=0;
void recursion(char c,int i){
	if(i<0)
		return;
 	m1.lock();
	cout<<"threadid:"<<c<<" "<<buffer++<<endl;
	recursion(c,--i);
	m1.unlock();
	cout<<"unlock by thread "<<c<<endl;
}
int main(){
	thread t1(recursion,'A',10);
	thread t2(recursion,'B',10);
	t1.join();
	t2.join();
	return 0;
}
