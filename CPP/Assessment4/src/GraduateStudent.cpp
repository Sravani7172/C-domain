#include "GraduateStudent.h"
#include <iostream>
using namespace std;
GraduateStudent::GraduateStudent(int id, string name, float grade, int totalSubjects)
    : Student(id, name,grade), totalSubjects(totalSubjects),finalScore( 0.6 * grade * totalSubjects){}

int GraduateStudent::getTotalSubjects() const {
    return totalSubjects;
}
void GraduateStudent::setTotalSubjects(int subs){
    if(subs<=0){
        throw "Invalid input!";
    }
    totalSubjects=subs;
}
float GraduateStudent::getFinalScore()const {
    return finalScore;
}
void GraduateStudent::calculateFinalScore(){
    finalScore=0.6 * Student::getGrade() * totalSubjects;
}

void GraduateStudent::displayDetails() const {
    cout << "Graduate ";
    Student::displayDetails();
    cout << "Total Subjects: " << totalSubjects << endl;
}

