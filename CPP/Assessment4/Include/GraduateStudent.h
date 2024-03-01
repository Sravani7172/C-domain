#ifndef GRADUATE_STUDENT_H
#define GRADUATE_STUDENT_H
#include "Student.h"
using namespace std;
// derived class2
class GraduateStudent : public Student {
private:
    int totalSubjects;
    float finalScore;
public:
    GraduateStudent(int id,string name,float grade,int totalSubjects);
    int getTotalSubjects() const;  
    void setTotalSubjects(int subs);
    float getFinalScore() const override;
    void displayDetails() const override;
    void calculateFinalScore()override;

};

#endif
