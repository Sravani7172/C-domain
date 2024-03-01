#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int>vectorobj;
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	int element;
	cout<<"Enter the array elements: "<<endl;
	for(int i=0;i<size;i++){
		cin>>element;
		vectorobj.push_back(element);		
	}
	cout<<"Vector elements are: "<<endl;
	for(auto& element:vectorobj){
		cout<<element<<" ";
	}
	cout<<endl;
	int vectorSize=vectorobj.size();
	cout<<"vector size: "<<vectorSize<<endl;
	int newElement;
	cout<<"Enter the newelement to vector: ";
	
	//adding element by using push_back
	cin>>newElement;
	vectorobj.push_back(newElement);
	cout<<"After adding the newelement to vector: "<<endl;
	for(auto& element:vectorobj){
		cout<<element<<" ";
	}
	cout<<endl;
	//deleting last element by using pop_back
	if(!vectorobj.empty()){
		vectorobj.pop_back();
	}
	cout<<"After deleting the element the vector: "<<endl;
	for(auto& element:vectorobj){
		cout<<element<<" ";
	}
	cout<<endl;
	//using clear() to remove all elements 
	vectorobj.clear();
	cout<<"After clearing the vector: "<<endl;
	for(auto& element:vectorobj){
		cout<<element<<" ";
		cout<<"Empty"<<endl;
		
	}
	cout<<endl;
	return 0;
}

