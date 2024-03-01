  //Header file
  #ifndef STUDENT_RECORDS_H
  #define STUDENT_RECORDS_H
  #include<iostream>
  #include<string>
  using namespace std;
  struct studentname{
  	string firstname;
  	char lastname;
	  };
  struct student_record{
          int id;
          double CGPA;
          string DOB;
          string gender;
          studentname full_name;
  };
  
  void printRecord(struct student_record *rec);
  void addRecord(struct student_record &rec);
  void findStudentDetails(student_record arr[],int size,int ID);
  void findStudentDetails(student_record arr[],int size,string gender);
  double getOverAllCgpa(struct student_record arr[],int size,int index);
  #endif

