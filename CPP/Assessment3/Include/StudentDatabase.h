#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H
#include <iostream>
#include<string>
using namespace std;
//Abstract class
class Student{
	protected:
		int id;
		string name;
		float grade;
	public:
		Student();//constructor
		Student(int id,string name,float grade);
	        ~Student();
		virtual void displayDetails() const;
		int getID();
		string getName();
		float getGrade();
};
//derived class1
class UndergraduateStudent : public Student{
	public:
		UndergraduateStudent(int id,string name,float grade);
};
//derived class2
class GraduateStudent : public Student{
	private:
		int totalSubjects;
	public:
		GraduateStudent(int id,string name,float grade,int totalSubjects);
		int getTotalSubjects() const;
};

void displayDetails(Student* students[], int size, int id);
Student* findHighScoreStudent(Student* students[], int size);
Student* findLowScoreStudent(Student* students[], int size);
void deleteStudentDetails(Student* students[], int &size, int id);
float getStudentScore(Student* students[], int size, int id);

#endif
	

