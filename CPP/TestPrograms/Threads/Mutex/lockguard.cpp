#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int even=0;
mutex mtx;
void Even(int num){
	lock_guard<mutex> lock(mtx);
        for(int i=0;i<num;i++){
		if(i%2 == 0){
			even+=i;		
		}
}
cout<<"Even num: "<< even << endl;
}
int main(){
	int num=10;
	thread t1(Even,num);
	thread t2(Even,num);
	t1.join();
	t2.join();
	return 0;
}

