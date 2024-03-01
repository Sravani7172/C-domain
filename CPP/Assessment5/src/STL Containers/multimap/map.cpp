#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	map<int,string>mymap;
	int size;
	cout<<"Enter the size of the key value pairs: ";
	cin>>size;
	for(int i=0;i<size;i++){
		int key;
		cout<<"Enter the key: ";
		cin>>key;
		string value;
		cout<<"Enter the value: ";
		cin>>value;
		mymap[key]=value;
	}
	cout<<endl;
	cout<<"list of map contents: "<<endl;
	for(auto& pair:mymap){
		cout<<" Key : "<<pair.first<<" value : "<<pair.second<<endl;
	}
	
	for(auto& pair:mymap){
		cout<<" Key: "<<pair.first<<" value : "<<pair.second<<endl;
	}
	
	return 0;
}
