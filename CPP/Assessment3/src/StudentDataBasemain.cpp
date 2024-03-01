#include <iostream>
#include "StudentDatabase.h"
using namespace std;
int main()
{
    const int maxSize = 100;
    Student *students[maxSize];
    int currentSize = 0;

    int choice;
    while (true)
    {
	cout <<"--------------------------------"<< endl;
        cout << "1. Add Undergraduate Student" << endl;
        cout << "2. Add Graduate Student" << endl;
        cout << "3. Display Details and Calculate Final Grades" << endl;
        cout << "4. Display Details of a Specific Student" << endl;
        cout << "5. Find High Score Student" << endl;
        cout << "6. Find Low Score Student" << endl;
        cout << "7. Delete Student" << endl;
        cout << "8. Get Student Score" << endl;
        cout << "0. Exit" << endl;
	cout <<"--------------------------------"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            float grade;
            cout << "\nEnter Undergraduate Student details:" << endl;
            cout << "Student ID: ";
            cin >> id;
            cout << "Student Name: ";
            cin.ignore(); // Ignore newline character
            getline(cin, name);
            cout << "Student Grade: ";
            cin >> grade;

            students[currentSize++] = new UndergraduateStudent(id, name, grade);
        }
        break;
        case 2:
        {
            int id, totalSubjects;
            string name;
            float grade;
            cout << "\nEnter Graduate Student details:" << endl;
            cout << "Student ID: ";
            cin >> id;
            cout << "Student Name: ";
            cin.ignore(); // Ignore newline character
            getline(cin, name);
            cout << "Student Grade: ";
            cin >> grade;
            cout << "Total Subjects: ";
            cin >> totalSubjects;

            students[currentSize++] = new GraduateStudent(id, name, grade, totalSubjects);
        }
        break;
        case 3:
        {
            // Display details and calculate final grades for all students
            for (int i = 0; i < currentSize; ++i)
            {
		cout<<"\n";
                students[i]->displayDetails();
                cout<<"final Score: " <<students[i]->getGrade()<<endl;
            }
        }
        break;
        case 4:
        {
            int id;
            cout << "Enter Student ID to display details: ";
            cin >> id;
            displayDetails(students, currentSize, id);
        }
        break;
        case 5:
        {
            Student *highScoreStudent = findHighScoreStudent(students, currentSize);
            if (highScoreStudent)
            {
                cout << "High Score Student: "<<endl;
                highScoreStudent->displayDetails();
		cout<<"\n";
            }
            else
            {
                cout << "No students found." << endl;
            }
        }
        break;
        case 6:
        {
            Student *lowScoreStudent = findLowScoreStudent(students, currentSize);
            if (lowScoreStudent)
            {
                cout << "Low Score Student: ";
                lowScoreStudent->displayDetails();
            }
            else
            {
                cout << "No students found." << endl;
            }
        }
        break;
        case 7:
        {
            int id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            deleteStudentDetails(students, currentSize, id);
        }
        break;
        case 8:
        {
            int id;
            cout << "Enter Student ID to get score: ";
            cin >> id;
            float score = getStudentScore(students, currentSize, id);
            if (score != -1.0)
            {
                cout << "Student Score: " << score << endl;
            }
            else
            {
                cout << "No student found." << endl;
            }
        }
        break;
        case 0:
        {
            cout << "Exiting program." << endl;
            return 0;
        }
        break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    for (int i = 0; i < currentSize; ++i)
    {
        delete students[i];
    }

    return 0;
}


