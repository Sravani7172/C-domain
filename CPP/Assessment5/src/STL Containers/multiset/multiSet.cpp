#include <iostream>
#include <set>
using namespace std;
int main() {
    // Declare a multiset 
    multiset<int> ms;

    // Insert elements into the multiset
    ms.insert(10);
    ms.insert(20);
    ms.insert(10); 
    
    cout << "Multiset elements:";
    for (const auto& elem : ms) {
        cout << " " << elem;
    }
    cout << endl;

    // Count the occurrences of a particular element
    int count_of = ms.count(10);
    cout << "Count of 10: " << count_of << endl;
    // Erase an element from the multiset
    ms.erase(20);
    cout << "After erasing 20:";
    for(const auto& elem : ms) {
        cout << " " << elem;
    }
    cout << endl;

    return 0;
}

