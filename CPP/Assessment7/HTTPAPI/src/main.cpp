#include <iostream>
#include "MyHttpMethods.h"
using namespace std;
int main() {
    MyHttpMethods http;
    int choice;
    string url, postData;
    while (true) {
        cout << "Choose an HTTP method:\n";
        cout << "1. GET\n";
        cout << "2. POST\n";
        cout << "3. PUT\n";
        cout << "4. DELETE\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: // GET request
                cout << "Enter the URL for the GET request: ";
                cin >> url;
                cout << "GET Response:\n" << http.get(url) << endl;
                break;

            case 2: // POST request
                cout << "Enter the URL for the POST request: ";
                cin >> url;
                cout << "Enter the POST data in JSON format: ";
                
                cin >> postData;
                cout << "POST Response:\n" << http.post(url, postData) << endl;
                break;

            case 3: // PUT request
                cout << "Enter the URL for the PUT request: ";
                cin >> url;
                cout << "Enter the PUT data in JSON format: ";
                cin >> postData;
                cout << "PUT Response:\n" << http.put(url, postData) << endl;
                break;

            case 4: // DELETE request
                cout << "Enter the URL for the DELETE request: ";
                cin >> url;
                cout << "DELETE Response:\n" << http.del(url) << endl;
                break;

            case 5: // Exit
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    }

    return 0;
}

