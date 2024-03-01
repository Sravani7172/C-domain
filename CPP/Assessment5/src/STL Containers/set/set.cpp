#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> myset;
    int size;

    cout << "Enter the size of the set: ";
    cin >> size;

    for (int i = 0; i < size; ++i) {
        string elements;
        cout << "Enter the element " << i << ": ";
        cin >> elements;
        myset.insert(elements);
    }

    cout << endl;
    cout << "Display the elements: " << endl;

    for (const auto &elements : myset) {
        cout << elements << " ";
    }

    cout << endl;

    return 0;
}

		
