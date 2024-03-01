#include "Student.h"
using namespace std;
Student::Student() : id(0), name(""), grade(0.0) {}

Student::Student(int id, std::string name, float grade) : id(id), name(name), grade(grade) {
    if (!isValidID(id) || !isValidName(name) || !isValidGrade(grade)) {
        throw "Invalid input. Exiting program.";
    }
}

Student::~Student() {}

int Student::getID() const {
    return id;
}

string Student::getName() const {
    return name;
}
float Student::getFinalScore()const {
    return grade;
}

float Student::getGrade() const {
    return grade;
}

void Student::setID(int ID) {
    if (!isValidID(ID)) {
        throw "Invalid ID. Exiting program.";
    }
    id = ID;
}

void Student::setName(const std::string& Name) {
    if (!isValidName(Name)) {
        throw "Invalid name. Exiting program.";
    }
    name = Name;
}

void Student::setGrade(float Grade) {
    if (!isValidGrade(Grade)) {
        throw "Invalid grade. Exiting program.";
    }
    grade = Grade;
}

void Student::displayDetails() const {
    cout << "\nStudent ID: " << id << endl;
    cout << "Student Name: " << name << endl;
    cout << "Student Grade: " << grade << endl;
}

void Student::calculateFinalScore(){
    return;
}

bool Student::isValidID(int ID) {
    return ID > 0;
}

bool Student::isValidName(const std::string& Name) {
    return !Name.empty();
}

bool Student::isValidGrade(float Grade) {
    return Grade >= 0.0 && Grade <= 10.0;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Student ID: " << student.getID() << "\n";
    os << "Student Name: " << student.getName() << "\n";
    os << "Student Grade: " << student.getGrade()<< "\n";
    return os;
}

istream& operator>>(istream& is, Student& student) {
    int ID;
    string name;
    float grade;
    cout << "Enter Student ID: ";
    is >> ID;
    cout << "Enter Student Name: ";
    is.ignore();
    getline(is, name);
    cout << "Enter Student Grade: ";
    is >> grade;

    if (Student::isValidID(ID) && Student::isValidName(name) && Student::isValidGrade(grade)) {
        student.setID(ID);
        student.setName(name);
        student.setGrade(grade);
    } else {
        throw "Invalid input. Exiting program.";
    }
    return is;
}

