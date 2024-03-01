#include<iostream>
#include<string>
using namespace std;
//enum type named WeekDays with constants Mon to Sun
enum WeekDays{
	Mon,Tue,Wed,Thu,Fri,Sat,Sun
};
int main(int argc,char *argv[]){
	//check if the program is provided with the correct number of arguments
	if(argc != 2){
	   //print error message if the number of arguments is incorrect
           cerr<<"Error: "<<argv[0]<<endl;
  	   return 1;
	}
	//convert the second command line argument into a C++ string
	string inputDay(argv[1]);
	WeekDays day;
	if(inputDay=="mon"){
		day=Mon;
	}
	else if(inputDay=="tue"){
		day=Tue;
	}
	else if(inputDay=="wed"){
                day=Wed;
        }
	else if(inputDay=="thu"){
		day=Thu;
	}
	else if(inputDay=="fri"){
		day=Fri;
	}
	else if(inputDay=="sat"){
		day=Sat;
	}
	else if(inputDay=="sun"){
		day=Sun;
	}
	else{
		cerr<<"Invalid input"<<endl;
	}
	//print the numerical value corresponding to the day enum constant
	cout<<static_cast<int>(day)<<endl;
	return 0;
}

