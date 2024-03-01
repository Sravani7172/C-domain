#include<iostream>
#include<thread>
using namespace std;
int count=0;
void incrementCounter(){
	for(int i=0;i<10000;i++){
		count++;
	}
}
int main(){
	thread t1(incrementCounter);
	thread t2(incrementCounter);
	t1.join();
	t2.join();
	cout<<"Final value of counter: "<<count<<endl;
	return 0;
}	

