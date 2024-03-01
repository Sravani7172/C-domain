#include <iostream>
#include <cstring>
using namespace std;

// Function to reverse each word in an array of words
void ReverseWords(char words[][10], int number) {
    for (int i = 0; i < number; i++) {
        char reversedWord[10]; // Create a temporary array to store the reversed word
        int length = strlen(words[i]);
        for (int j = 0; j < length; j++) {
            reversedWord[j] = words[i][length - j - 1];
        }
        reversedWord[length] = '\0'; // Null-terminate the reversed word
        cout << reversedWord << endl;
    }
}

// Function to sort an array of words in ascending order
void Ascending(char words[][10], int number) {
    char sortedWords[20][10]; // Create a temporary array to store the sorted words
    for (int i = 0; i < number; i++) {
        strcpy(sortedWords[i], words[i]);
    }

    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (strcmp(sortedWords[j], sortedWords[j + 1]) > 0) {
                swap(sortedWords[j], sortedWords[j + 1]);
            }
        }
    }

    for (int i = 0; i < number; i++) {
        cout << sortedWords[i] << endl;
    }
}

// Function to sort an array of words in descending order
void Descending(char words[][10], int number) {
    char sortedWords[20][10]; // Create a temporary array to store the sorted words
    for (int i = 0; i < number; i++) {
        strcpy(sortedWords[i], words[i]);
    }

    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (strcmp(sortedWords[j], sortedWords[j + 1]) < 0) {
                swap(sortedWords[j], sortedWords[j + 1]);
            }
        }
    }

    for (int i = 0; i < number; i++) {
        cout << sortedWords[i] << endl;
    }
}

int main() {
    int number, choice;
    cout << "Enter the number of words:";
    cin >> number;

    if (number <= 0 || number > 20) {
        cout << "Invalid number of words. Exiting." << endl;
        return 1; // Indicate an error
    }

    char words[20][10];
    cout << "Enter the words:" << endl;
    for (int i = 0; i < number; i++) {
        cin >> words[i];
    }

    while (true) {
        cout << "Choose an option:\n 1. Reverse\n 2. Sort in ascending\n 3. Sort in descending\n 4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Reversed words:" << endl;
                ReverseWords(words, number);
                break;
            case 2:
                cout << "Words sorted in ascending:" << endl;
                Ascending(words, number);
                break;
            case 3:
                cout << "Words sorted in descending:" << endl;
                Descending(words, number);
                break;
            case 4:
                cout << "Exit the program:" << endl;
                return 0;
            default:
                cout << "Invalid choice:" << endl;
        }
    }

    return 0;
}

