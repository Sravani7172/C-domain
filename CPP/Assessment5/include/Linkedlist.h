#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node {
private:
    int data;
    Node* next;
public:
    Node(int value);
    // Getters
    int getData();
    Node* getNext();
    // Setters
    void setData(int value);
    void setNext(Node* nextNode);
};
void UserInput(Node*& head, int size);
void DisplayList(Node *&head);
int Count(Node* head, int searchFor);
int GetNth(Node* head, int index);
void DeleteList(Node*& head);
int Pop(Node*& head);
void InsertNth(Node*& head, int index, int data);
void SortedInsert(Node*& head, Node* newNode);
void InsertSort(Node*& head);
void RemoveDuplicates(Node* head);
void Append(Node*& list1, Node*& list2);
void FrontBackSplit(Node* source, Node*& front, Node*& back);
void MoveNode(Node*& dest, Node*& source);
void AlternatingSplit(Node* source, Node*& list1, Node*& list2);
Node* ShuffleMerge(Node* list1, Node* list2);
Node* SortedMerge(Node* list1, Node* list2);
void MergeSort(Node*& head);
Node* SortedIntersect(Node* list1, Node* list2);
void insertAtFirst(Node* & head,int value);
void Reverse(Node* &head);
void RecursiveReverse(Node*& head);
#endif

