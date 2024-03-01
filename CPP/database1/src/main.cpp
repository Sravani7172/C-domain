#include "databaseoperations.h"
#include <iostream>

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

    sql::Connection *conn = establishConnection(hostname, username, password, schema);

    if (!conn) {
        cerr << "Failed to establish connection." << endl;
        return 1;
    }

    int choice;
    while (true) {
        cout << "Select operation:\n";
        cout << "1. Insert\n";
        cout << "2. Update\n";
        cout << "3. Delete\n";
        cout << "4. Print\n";
        cout << "5. Call UpdateEmployeeAgeProcedure\n"; 
        cout << "6. Call Event\n"; 
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertData(conn);
                break;
            case 2:
                updateData(conn);
                break;
            case 3:
                deleteData(conn);
                break;
            case 4:
                printData(conn);
                break;
            case 5:
                callUpdateEmployeeAgeProcedure(conn);
                break;
            case 6:
                delete conn;            
                break;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    }

    return 0;
}

