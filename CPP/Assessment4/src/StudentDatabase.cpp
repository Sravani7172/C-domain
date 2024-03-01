#include "StudentDatabase.h"
#include <iostream>
using namespace std;
void displayDetails(Student* students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i]->getID() == id) {
            students[i]->displayDetails();
            return;
        }
    }
    cout << "Student id " << id << " not found" << endl;
}

void modifyGrade(Student* students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i]->getID() == id) {
            float newGrade;
            cout<<"Enter the new grade to modify the student grade: ";
            cin>>newGrade;
            students[i]->setGrade(newGrade);
            students[i]->calculateFinalScore();
            cout<<"Details of the student after modification"<<endl;
            students[i]->displayDetails();
            return;
        }
    }
    cout << "Student id " << id << " not found" << endl;
}

Student* findHighScoreStudent(Student* students[], int size) {
    if (size == 0) {
        return nullptr;
    }
    Student* highScoreStudent = students[0];
    for (int i = 0; i < size; i++) {
        if (students[i]->getGrade() > highScoreStudent->getGrade()) {
            highScoreStudent = students[i];
        }
    }
    return highScoreStudent;
}

Student* findLowScoreStudent(Student* students[], int size) {
    if (size == 0) {
        return nullptr;
    }
    Student* lowScoreStudent = students[0];
    for (int i = 0; i < size; i++) {
        if (students[i]->getGrade() < lowScoreStudent->getGrade()) {
            lowScoreStudent = students[i];
        }
    }
    return lowScoreStudent;
}

void deleteStudentDetails(Student* students[], int& size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i]->getID() == id) {
            delete students[i];
            for (int j = i; j < size - 1; j++) {
                students[j] = students[j + 1];
            }
            --size;
            cout << "Student id " << id << " deleted" << endl;
            return;
        }
    }
    cout << "Student id " << id << " not found." << endl;
}

float getStudentScore(Student* students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i]->getID() == id) {
            return students[i]->getGrade();
        }
    }
    cout << "Student id " << id << " not found." << endl;
    return -1.0;
}
