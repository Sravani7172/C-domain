#include "UndergraduateStudent.h"
using namespace std;

UndergraduateStudent::UndergraduateStudent(int id,string name,float grade)
	:Student(id,name,grade){}

void UndergraduateStudent :: displayDetails() const{
    cout <<"Undergraduate"<<endl;	
    cout <<"Student id: "<<this->getID() <<endl;
    cout <<"Student name:"<<this->getName() <<endl;
    cout <<"Student grade: "<<this->getGrade() <<endl;
    }   
