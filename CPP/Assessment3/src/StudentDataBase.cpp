#include "StudentDatabase.h"
//student class implementation
Student::Student(int stuid,string stuname,float stugrade){
	id=stuid;
	name=stuname;
	grade=stugrade;
}
Student::~Student(){}

int Student::getID(){
    return id;
}
string Student::getName(){
    return name;
}
float Student::getGrade(){
    return grade;
}

void Student::displayDetails() const {
    cout << "\nStudent ID: " << id << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Grade: " << grade << endl;
}
//undergraduateStudent class implementation

UndergraduateStudent::UndergraduateStudent(int id,string name,float grade)
	:Student(id,name,grade){}

//graduateStudent class implementation
GraduateStudent::GraduateStudent(int id,string name,float grade,int totalSubjects)
	:Student(id,name,(0.6*grade*totalSubjects)),totalSubjects(totalSubjects){}
int GraduateStudent::getTotalSubjects() const{
	return totalSubjects;
}

	
void displayDetails( Student* students[],int size,int id){
	for(int i=0;i<size;i++){
		if(students[i]->getID() == id){
			students[i]->displayDetails();
			return;
		}
	}
	cout<<"Student id "<<id<<"not found"<<endl;
}

Student* findHighScoreStudent(Student* students[],int size){
	if(size==0){
		return nullptr;
	}
	Student* highScoreStudent=students[0];
	for(int i=0;i<size;i++){
		if(students[i]->getGrade() > highScoreStudent->getGrade()){
			highScoreStudent=students[i];
		}
	}
	return highScoreStudent;
}

Student* findLowScoreStudent( Student* students[],int size){
	if(size==0){
		return nullptr;
	}
	Student* lowScoreStudent=students[0];
	for(int i=0;i<size;i++){
		if(students[i]->getGrade() < lowScoreStudent->getGrade()){
			lowScoreStudent=students[i];
		}
	}
	return lowScoreStudent;
}

void deleteStudentDetails(Student* students[],int &size,int id){
	for(int i=0;i<size;i++){
		if(students[i]->getID() == id){
			delete students[i];
			for(int j=i;j<size-1;j++){
				students[j]=students[j+1];
			}
			--size;
			cout<<"Student id "<<id<<"deleted"<<endl;
			return;
		}
	}
	cout<<"Student id "<<id<<"not found."<<endl;
}

float getStudentScore( Student* students[],int size,int id){
	for(int i=0;i<size;i++){
		if(students[i]->getID() == id){
			return students[i]->getGrade();
		}
	}
	cout<<"Student id "<<"not found."<<endl;
	return -1.0;
}
		


