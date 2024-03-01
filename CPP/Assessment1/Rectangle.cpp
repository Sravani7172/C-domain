#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double length,breadth;
	cout<<"length(l) = ";
	cin>>length;
	cout<<"breadth(b) = ";
	cin>>breadth;
	//output with 0.2 precision
	cout<<fixed<< setprecision(2);
	//Calculating area of a rectangle
	double area = length*breadth;
	cout<<"Area of a rectangle = "<<area<<endl;
	//Calculating perimeter of a rectangle
	double perimeter = 2 * (length+breadth);
	cout<<"Perimeter of a rectangle = "<<perimeter<<endl;
	return 0;
}
	
