#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H
#include"Student.h"
#include"UndergraduateStudent.h"
#include"GraduateStudent.h"
void displayDetails(Student* students[], int size, int id);
Student* findHighScoreStudent(Student* students[], int size);
Student* findLowScoreStudent(Student* students[], int size);
void deleteStudentDetails(Student* students[], int &size, int id);
float getStudentScore(Student* students[], int size, int id);
void modifyGrade(Student* students[], int size, int id);
#endif

