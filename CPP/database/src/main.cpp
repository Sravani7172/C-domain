#include <iostream>
#include "databaseoperations.h"
using namespace std;
int main() {
    string hostname, username, password, schema;
    cout << "Enter database hostname: ";
    cin >> hostname;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter database schema: ";
    cin >> schema;
    MysqlDataBase database(hostname, username, password, schema);
    int choice;
    while (true) {
        cout << "Select operation:\n";
        cout << "1. Insert\n";
        cout << "2. Update\n";
        cout << "3. Delete\n";
        cout << "4. Print\n";
        cout << "5. Call UpdateEmployeeAgeProcedure\n"; 
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                database.insertData();
                break;
            case 2:
                database.updateData();
                break;
            case 3:
                database.deleteData();
                break;
            case 4:
                database.printData();
                break;
            case 5:
                database.callUpdateEmployeeAgeProcedure();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    }
    return 0;
}
