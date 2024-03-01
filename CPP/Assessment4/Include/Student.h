#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    int id;
    string name;
    float grade;
public:
    Student();
    Student(int id, string name, float grade);
    virtual ~Student();
    //getters and setters  
    int getID() const;
    string getName() const;
    float getGrade() const;
    
    void setID(int ID);
    void setName(const string& Name);
    void setGrade(float Grade);

    virtual void displayDetails() const = 0;
    virtual float getFinalScore()const;
    virtual void calculateFinalScore();
    
    static bool isValidID(int ID);
    static bool isValidName(const string& Name);
    static bool isValidGrade(float Grade);
};

ostream& operator<<(ostream& os, const Student& student);
istream& operator>>(istream& is, Student& student);

#endif
