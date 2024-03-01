#include<iostream>
#include<thread>
using namespace std;
void run(int count){
	while(count-->0)
		cout<<"c++"<<endl;
		this_thread::sleep_for(chrono::seconds(2));
}
int main(){
	thread t1(run,5);
	cout<<"main"<<endl;
	t1.join();
	if(t1.joinable())
		t1.join();
	cout<<"main after"<<endl;
	return 0;
}
	
