#include "Linkedlist.h"
#include <iostream>

using namespace std;

int main() {
    Node* List1=nullptr;
    Node* List2=nullptr; 
    int List1Size;
    int List2Size;
    int choice;

    do {
        cout << "\n----------------------------\n";
        cout << "Linked List Operations: \n";
        cout << "1. UserInput\n";
        cout << "2. InsertNth\n";
        cout << "3. Display list\n";
        cout << "4. GetNth\n";
        cout << "5. DeleteList\n";
        cout << "6. Pop\n";
        cout << "7. Count\n";
        cout << "8. SortedInsert\n";
        cout << "9. InsertSort\n";
        cout << "10. RemoveDuplicates\n";
        cout << "11. Append\n";
        cout << "12. FrontBackSplit\n";
        cout << "13. MoveNode\n";
        cout << "14. AlternatingSplit\n";
        cout << "15. ShuffleMerge\n";
        cout << "16. SortedMerge\n";
        cout << "17. MergeSort\n";
        cout << "18. SortedIntersect\n";
        cout << "19. Reverse\n";
        cout << "20. RecursiveReverse\n";
        cout << "0. Exit\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the size of list1: ";
                cin >> List1Size;
                UserInput(List1, List1Size);
                cout << "\n";
                cout << "Enter the size of list2: ";
                cin >> List2Size; 
                UserInput(List2, List2Size);
                cout << "\n";
                cout << "Display list1: ";
                DisplayList(List1);
                cout << "\n";
                cout << "Display list2: ";
                DisplayList(List2);
                break;
            }
            case 2: {
                int index, data;
                cout << "Enter the list1 index to insert at: ";
                cin >> index;
                cout << "Enter the data to insert: ";
                cin >> data;
                InsertNth(List1, index, data);
                cout << "After inserting elements in list1:\n";
                DisplayList(List1);
                break;
            }
            case 3: {
            	 cout << "Display list1: ";
                DisplayList(List1);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the list1 index to get the value: ";
                cin >> index;
                int value = GetNth(List1, index);
                cout << "Value at index " << index << ": " << value << endl;
                break;
            }
            case 5: {
                DeleteList(List1);
                cout << "List deleted successfully.\n";
                break;
            }
            case 6: {
                int poppedValue = Pop(List1);
                cout << "Popped value: " << poppedValue << endl;
                cout << "After popping the value of list1: \n";
                DisplayList(List1);
                break;
            }
            case 7: {
                int search;
                cout << "Enter the list1 value to count: ";
                cin >> search;
                int count = Count(List1, search);
                cout << "Count: " << count << endl;
                break;
            }
            case 8: {
                int data;
                cout << "Enter the list1 data to insert: ";
                cin >> data;
                SortedInsert(List1, new Node(data));
                cout << "Element inserted at the correct position.\n";
                DisplayList(List1);
                break;
            }
            case 9: {
                cout << "Before sorting the list1: "<<endl;
                DisplayList(List1);
                InsertSort(List1);
                cout << "After sorting the list1: " << endl;
                DisplayList(List1);
                cout << "List sorted successfully.\n";
                break;
            }
            case 10: {
            	 cout << "Before removing duplicates the list1: ";
            	 DisplayList(List1);
                RemoveDuplicates(List1);
                cout << "Duplicates removed successfully.\n";
                cout << "After removing duplicates the list: \n";
                DisplayList(List1);
                break;
            }
            case 11: {
                Append(List1, List2);
                cout << "Lists appended successfully.\n";
                cout << "Display list: ";
                DisplayList(List1);
                break;
            }
            case 12: {
                Node* front = nullptr;
                Node* back = nullptr;
                FrontBackSplit(List1, front, back);
                cout << "Front List: ";
                while (front != nullptr) {
                    cout << front->getData() << " ";
                    front = front->getNext();
                }
                cout << "\nBack List: ";
                while (back != nullptr) {
                    cout << back->getData() << " ";
                    back = back->getNext();
                }
                cout << endl;
                break;
            }
            case 13: {
                MoveNode(List2, List1);  // Move from list1 to list2
                cout << "Node moved from list1 to list2.\n";
                cout << "Display list1: ";
                DisplayList(List1);
                cout << "Display list2: ";
                DisplayList(List2);
                break;
            }
            case 14: {
                Node* list1Alt = nullptr;
    		Node* list2Alt = nullptr;
    		AlternatingSplit(List1, list1Alt, list2Alt);
    		cout << "Split list1 into sublists";
    		cout << "List1 a : ";
    		DisplayList(list1Alt); 
    		cout << "List1 b : ";
    		DisplayList(list2Alt); 
    		cout << endl;
    		break;
            }
            case 15: {
                Node* shuffledList = ShuffleMerge(List1, List2);
                cout << "Shuffled merged list: ";
                while (shuffledList != nullptr) {
                    cout << shuffledList->getData() << " ";
                    shuffledList = shuffledList->getNext();
                }
                cout << endl;
                break;
            }
            case 16: {
            	
                Node* sortedMergedList = SortedMerge(List1, List2);
                cout << "Sorted merged list: ";
                while (sortedMergedList != nullptr) {
                    cout << sortedMergedList->getData() << " ";
                    sortedMergedList = sortedMergedList->getNext();
                }
                cout << endl;
                break;
            }
            case 17: {
                MergeSort(List1);
                cout << "List sorted using merge sort.\n";
                break;
            }
            case 18: {
                Node* intersectedList = SortedIntersect(List1, List2);
                cout << "Sorted intersection list: ";
                while (intersectedList != nullptr) {
                    cout << intersectedList->getData() << " ";
                    intersectedList = intersectedList->getNext();
                }
                cout << endl;
                break;
            }
            case 19: {
                Reverse(List1);
                cout << "List reversed successfully.\n";
                break;
            }
            case 20: {
                RecursiveReverse(List1);
                cout << "List recursively reversed successfully.\n";
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 0);

    return 0;
}

