#include<iostream>
#include<thread>
using namespace std;
int even=0;
void Even(int num){
	for(int i=0;i<num;i++){
		if(i%2 == 0){
			even+=i;
			
		}
	}
cout<<"Even sum: "<< even << endl;
}
int main(){
	int num=3;
	thread t1(Even,num);
	thread t2(Even,num);
	t1.join();
	t2.join();
	return 0;
}
