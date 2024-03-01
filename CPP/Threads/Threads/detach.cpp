#include<iostream>
#include<thread>
using namespace std;
void run(int count){
	while(count-->0)
		cout<<count<<"running thread"<<endl;
	cout<<"thread finished"<<endl;
}
int main(){
	thread t1(run,5);
	cout<<"main"<<endl;
	t1.detach();
	cout<<"main after"<<endl;
	this_thread::sleep_for(chrono::seconds(3));
	return 0;
}
