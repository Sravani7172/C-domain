#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx;
int result=0;
void naturalNumbers(){
	unique_lock<mutex>lock(mtx);
	for(int i=0;i<10;i++){
		result+=1;
		cout<<result<<endl;
	}
lock.unlock();
}
int main(){
	thread t1(naturalNumbers);
	thread t2(naturalNumbers);
	thread t3(naturalNumbers);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
		
	
