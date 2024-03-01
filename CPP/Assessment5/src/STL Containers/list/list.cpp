#include<iostream>
#include<list>
using namespace std;
int main(){
	list<int>mylist;
	int size;
	cout<<"Enter the size of the list: ";
	cin>>size;
	int inputvalue;
	for(int i=0;i<size;i++){
		cout<<"Enter the "<<i<<" value: ";
		cin>>inputvalue;
		//using push_back() it adds new element at the end
		mylist.push_back(inputvalue);
	}
	cout<<"Elements in the list: "<<endl;
	for(auto& element:mylist){
		cout<<element<<" ";
	}
	cout<<endl;
	//pop_back() it removes a last element
	mylist.pop_back();
	cout<<"After removing the last element"<<endl;
	for(auto& element:mylist){
		cout<<element<<" ";
	}
	cout<<endl;
	
	cout<<"Enter the element to push_back: ";
	int pushback;
	cin>>pushback;
	mylist.push_back(pushback);
	cout<<"Modified list after push_back the element "<<endl;
	for(auto& element:mylist){
		cout<<element<<" ";
	}
	cout<<endl;
	
	//using push_front() to push element at the front list
	int front;
	cout<<"Enter the element to push_front: ";
	cin>>front;
	mylist.push_front(front);
	for(list<int>::iterator it=mylist.begin(); it!=mylist.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	
	return 0;
}
	
