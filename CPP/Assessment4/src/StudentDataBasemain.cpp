#include <iostream>
#include "StudentDatabase.h"
#include "UndergraduateStudent.h"
#include "GraduateStudent.h"
#include<exception>
using namespace std;
int main() {
    int max;
    cout << "Enter the maximum number of students: ";
    cin >> max;
    Student** students = (Student**)(malloc(max * sizeof(Student*))); 
    int currentSize = 0;
    int choice;
    try {
        while (true) {
            cout << "--------------------------------" << endl;
            cout << "1. Add Undergraduate Student" << endl;
            cout << "2. Add Graduate Student" << endl;
            cout << "3. Display Details and Calculate Final Grades" << endl;
            cout << "4. Display Details of a Specific Student" << endl;
            cout << "5. Modify the grade by specific student id"<< endl; 
            cout << "6. Find High Score Student" << endl;
            cout << "7. Find Low Score Student" << endl;
            cout << "8. Delete Student" << endl;
            cout << "9. Get Student Score" << endl;
            cout << "0. Exit" << endl;
            cout << "--------------------------------" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
     switch (choice) {
                case 1: {
                    int id;
                    string name;
                    float grade;
                    cout << "\nEnter Undergraduate Student details:" << endl;
                    cout << "Student ID: ";
                    cin >> id;
                    cout << "Student Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Student Grade: ";
                    cin >> grade;

                    students[currentSize++] = (Student*)(malloc(sizeof(UndergraduateStudent)));
                    new(students[currentSize - 1]) UndergraduateStudent(id, name, grade);  // Call placement new
                } break;
                case 2: {
                    int id, totalSubjects;
                    string name;
                    float grade;
                    cout << "\nEnter Graduate Student details:" << endl;
                    cout << "Student ID: ";
                    cin >> id;
                    cout << "Student Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Student Grade: ";
                    cin >> grade;
                    cout << "Total Subjects: ";
                    cin >> totalSubjects;

                    students[currentSize++] = (Student*)(malloc(sizeof(GraduateStudent)));
                    new(students[currentSize - 1]) GraduateStudent(id, name, grade, totalSubjects);  // Call placement new
                } break;
                case 3: {
                    cout << "Display Student details "<< endl;
                    for (int i = 0; i < currentSize; ++i) {
                        cout << "\n";
                        students[i]->displayDetails();
                        cout << "Final Score: " << students[i]->getFinalScore() << endl;
                    }
                } break;
                case 4: {
                    int id;
                    cout << "Enter Student ID to display details: ";
                    cin >> id;
                    displayDetails(students, currentSize, id);
                } break;
                case 5:{
                    cout << "Enter student id to modify grade: ";
                    int id;
                    cin >> id;
                    modifyGrade(students, currentSize, id);
                } break;     
                case 6: {
                    Student* highScoreStudent = findHighScoreStudent(students, currentSize);
                    if (highScoreStudent) {
                        cout << "High Score Student: " << endl;
                        highScoreStudent->displayDetails();
                        cout << "\n";
                    } else {
                        cout << "No students found." << endl;
                    }
                } break;
                case 7: {
                    Student* lowScoreStudent = findLowScoreStudent(students, currentSize);
                    if (lowScoreStudent) {
                        cout << "Low Score Student: ";
                        lowScoreStudent->displayDetails();
                    } else {
                        cout << "No students found." << endl;
                    }
                } break;
                case 8: {
                    int id;
                    cout << "Enter Student ID to delete: ";
                    cin >> id;
                    deleteStudentDetails(students, currentSize, id);
                } break;
                case 9: {
                    int id;
                    cout << "Enter Student ID to get score: ";
                    cin >> id;
                    float score = getStudentScore(students, currentSize, id);
                    if (score != -1.0) {
                        cout << "Student Score: " << score << endl;
                    } else {
                        cout << "No student found." << endl;
                    }
                } break;
                case 0: {
                    cout << "Exiting program." << endl;
                    // Clean up allocated memory
                    for (int i = 0; i < currentSize; ++i) {
                        delete students[i];
                    }
                    delete[] students;
                    return 0;
                } break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    } 
    catch (const char* st) {
        cerr << st<< endl;
    }

    // Clean up allocated memory
 for (int i = 0; i < currentSize; ++i) {
        students[i]->~Student();  // Call the destructor explicitly
        free(students[i]);
    }
    free(students);
    return 0;
}

