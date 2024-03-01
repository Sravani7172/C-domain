#include "Linkedlist.h"
#include <iostream>
using namespace std;
Node::Node(int value) : data(value), next(nullptr) {}
// Getter
int Node::getData(){
    return data;
}
Node* Node::getNext(){
    return next;
}
// Setter
void Node::setData(int value) {
    data = value;
}
void Node::setNext(Node* nextNode) {
    next = nextNode;
}

// Function to take userinput 
void UserInput(Node*& head, int size) {
    for (int i = 0; i < size; ++i) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        InsertNth(head, i, value);
    }
}

// Function to insert a new node at a given index in the list
void InsertNth(Node*& head, int index, int data) {
    Node* newNode = new Node(data);
    if(index == 0) {
        newNode->setNext(head);
        head = newNode;
        return;
    }
    Node* current = head;
    for(int i = 0; i < index - 1; i++) {
        if(current == nullptr) {
            cout << "Invalid index\n";
            delete newNode;
            return;
        }
        current = current->getNext();
    }
    newNode->setNext(current->getNext());
    current->setNext(newNode);
}
//Function to displayList
void DisplayList(Node *&head){
    if(!head){
        cout<<"The List is Empty!!!"<<endl;
        return;
    }
    Node* currentNode = head;
    while(currentNode)
    {
        cout << currentNode->getData() << " ";
        currentNode = currentNode->getNext();
    }
    cout << endl;
}
// Function to get the data value 
int GetNth(Node* head, int index){
    Node* current = head;
    for(int i = 0; i < index; i++){
        if(current == nullptr){
            return -1;
        }
        current = current->getNext();
    }
    return current->getData();
}
// Function to count occurrences of a given in the list
int Count(Node* head, int search){
    int count = 0;
    Node* current = head;
    while(current != nullptr){
        if(current->getData() == search){
            count++;
        }
        current = current->getNext();
    }
    return count;
}
// Function to delete all nodes of the list 
void DeleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}
// Function to pop the head node 
int Pop(Node*& head) {
    if (head == nullptr) {
        cerr << "List is empty\n";
        return -1;
    }
    int data = head->getData();
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return data;
} 
// Function to insert a new node into a sorted list at the correct position
void SortedInsert(Node*& head, Node* newNode) {
    if (head == nullptr || head->getData() >= newNode->getData()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->getNext() != nullptr && current->getNext()->getData() < newNode->getData()) {
        current = current->getNext();
    }
    newNode->setNext(current->getNext());
    current->setNext(newNode);
}

// Function to perform insertion sort on a list
void InsertSort(Node*& head) {
    Node* sortedList = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        SortedInsert(sortedList, current);
        current = nextNode;
    }
    head = sortedList;
}
// Function to remove duplicates from a sorted list
void RemoveDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->getNext() != nullptr) {
        if (current->getData() == current->getNext()->getData()) {
            Node* nextNode = current->getNext()->getNext();
            delete current->getNext();
            current->setNext(nextNode);
        } else {
            current = current->getNext();
        }
    }
}
// Function to append list2 onto the end of list1 
void Append(Node*& list1, Node*& list2) {
    if (list1 == nullptr){
        list1=list2;
    } else {
        Node*current = list1;
        while(current->getNext()!= nullptr){
            current = current->getNext();
        }
        current->setNext(list2);
    }
    list2 = nullptr;
}
// Function to split a list into front and back halves
void FrontBackSplit(Node* source, Node*& front, Node*& back) {
    if (source == nullptr) {
        front = back = nullptr;
        return;
    }
    Node* slow = source;
    Node* fast = source->getNext();
    while (fast != nullptr) {
        fast = fast->getNext();
        if (fast != nullptr) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }
    front = source;
    back = slow->getNext();
    slow->setNext(nullptr);
}
// Function to move the front node from the source list to the front of the destination list
void MoveNode(Node*& dest, Node*& source) {
    if (source == nullptr) {
        cerr << "Source list is empty\n";
        return;
    }
    Node* newNode = source;
    source = source->getNext();
    newNode->setNext(dest);
    dest = newNode;
}
// Function to alternate nodes between two lists
void AlternatingSplit(Node* source, Node*& list1, Node*& list2) {
    list1 = list2 = nullptr;
    Node* current = source;
    Node* tail1 = nullptr;
    Node* tail2 = nullptr;
    bool addToA = true;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        current->setNext(nullptr);
        if (addToA) {
            if (list1 == nullptr) {
                list1 = tail1 = current;
            } else {
                tail1->setNext(current);
                tail1 = current;
            }
        } else {
            if (list2 == nullptr) {
                list2 = tail2 = current;
            } else {
                tail2->setNext(current);
                tail2 = current;
            }
        }
        addToA = !addToA;
        current = nextNode;
    }
}
// Function to merge nodes alternately between two lists
Node* ShuffleMerge(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* currentList1 = list1;
    Node* currentList2 = list2;
    while (currentList1 != nullptr || currentList2 != nullptr) {
        if (currentList1 != nullptr) {
            MoveNode(result, currentList1);
        }
        if (currentList2 != nullptr) {
            MoveNode(result, currentList2);
        }
    }
    return result;
}
// Function to merge two sorted lists into one sorted list
Node* SortedMerge(Node* list1, Node* list2) {
    Node* result = nullptr;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->getData() <= list2->getData()) {
            MoveNode(result, list1);
        } else {
            MoveNode(result, list2);
        }
    }
    while (list1 != nullptr) {
        MoveNode(result, list1);
    }
    while (list2 != nullptr) {
        MoveNode(result, list2);
    }
    return result;
}
// Function to recursively merge sort a list
void MergeSort(Node*& head) {
    if (head == nullptr || head->getNext() == nullptr) {
        return;
    }
    Node* front = nullptr;
    Node* back = nullptr;
    FrontBackSplit(head, front, back);
    MergeSort(front);
    MergeSort(back);
    head = SortedMerge(front, back);
}
// Function to compute a new sorted list that represents the intersection of two given sorted lists
Node* SortedIntersect(Node* list1, Node* list2) {
    Node* result = nullptr;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->getData() < list2->getData()) {
            list1 = list1->getNext();
        } else if (list1->getData() > list2->getData()) {
            list2 = list2->getNext();
        } else {
            // Data values are equal, add to the result list
            Node* newNode = new Node(list1->getData());
            SortedInsert(result, newNode);
            list1 = list1->getNext();
            list2 = list2->getNext();
        }
    }
    return result;
}
//Function to insertAtFirst 
void insertAtFirst(Node* & head,int value){
    Node* node=new Node(value);
    if(!head){
        head=node;
    }
    else{
        node->setNext(head);
    }
}
//Function to reverse the list
void Reverse(Node* &head){
    Node* rev=nullptr;
    Node* currentNode=head;
    while(currentNode){
        insertAtFirst(rev,currentNode->getData());
        currentNode=currentNode->getNext();
    }
    while(rev){
        cout<<rev->getData()<<" ";
        rev = rev->getNext();
    }
}
// Function to reverse a linked list recursively
void RecursiveReverse(Node*& head) {
    if (head == nullptr || head->getNext() == nullptr) {
        return;
    }
    Node* rest = head->getNext();
    RecursiveReverse(rest);
    head->getNext()->setNext(head);
    head->setNext(nullptr);
    head = rest;
}


