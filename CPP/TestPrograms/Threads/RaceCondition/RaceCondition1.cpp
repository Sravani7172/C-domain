#include<iostream>
#include<thread>
#include<string>
using namespace std;
string message="hello";
void appendString(const string& addtext){
	for(int i=0;i<3;i++){
		message+=addtext;
	}
}
int main(){
	thread t1(appendString,"sravani");
	thread t2(appendString,"Hari");
	t1.join();
	t2.join();
	cout <<"Final value of message: "<< message <<endl;
	return 0;
}	
		


