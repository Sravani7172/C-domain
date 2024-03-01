#ifndef UNDERGRADUATE_STUDENT_H
#define UNDERGRADUATE_STUDENT_H
#include "Student.h"
using namespace std;
// derived class1
class UndergraduateStudent : public Student {
public:
    UndergraduateStudent(int id, string name, float grade);

    void displayDetails() const override;
};

#endif
