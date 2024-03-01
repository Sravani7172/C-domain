#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    // Add elements to the vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    
    // Accessing elements using operator[]
    cout<< "Using operator[]: ";
    for (int i = 0;i < vec.size();++i) {
        cout<<vec[i]<< " ";
    }
    cout<<endl;
    
    // Accessing elements using at()
    cout<< "Using at(): ";
    for (int i = 0; i < vec.size(); ++i) {
        cout<< vec.at(i)<< " ";
    }
    cout <<endl;

    // Accessing the first element using front()
    cout<< "First element: " << vec.front() << endl;

    // Accessing the last element using back()
    cout << "Last element: " << vec.back() << endl;
    return 0;
}

