#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mtx;
void resource(int threadid){
	if(mtx.try_lock()){
		cout<<"thread "<<threadid<<" access the resource"<<endl;
		this_thread::sleep_for(chrono::seconds(2));
	}
	else{
		cout<<"thread "<<threadid<<" failed to access the resource"<<endl;
	}
}
int main(){
	int numThreads=5;
	thread threads[numThreads];
	for(int i=0;i<numThreads;i++){
		threads[i]=thread(resource,i+1);
	}
	//join
	for(int i=0;i<numThreads;i++){
		threads[i].join();
	}
	return 0;
}
	
