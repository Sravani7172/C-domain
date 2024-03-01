#include "studentrecordsystem.h"
void addRecord(struct student_record &rec){
	cout<<"Student Id: ";
	cin>>rec.id;
	cout<<"CGPA: ";
	cin>>rec.CGPA;
	cout<<"DOB(dd/mm/yyyy): ";
	cin>>rec.DOB;
	cout<<"Gender: ";
	cin>>rec.gender;
	cout<<"First name: ";
	cin>>rec.full_name.firstname;
	cout<<"Last name: ";
	cin>>rec.full_name.lastname;
}
void printRecord(struct student_record *rec){
	cout<<"Id: "<<rec->id<<"\n";
	cout<<"CGPA: "<<rec->CGPA<<"\n";
	cout<<"DOB: "<<rec->DOB<<"\n";
	cout<<"Gender: "<<rec->gender<<"\n";
	cout<<"First name: "<<rec->full_name.firstname<<"\n";
	cout<<"Last name: "<<rec->full_name.lastname<<"\n\n";
}
void findStudentDetails(student_record arr[],int size,int ID){
	for(int i=0;i<size;i++){
		if(arr[i].id==ID){
			cout<<"Student idfound: "<<endl;
			printRecord(&arr[i]);
			return;
		}
	}		   
	cout<<"Student id not found"<<endl;
}
void findStudentDetails(student_record arr[],int size,string Gender){
	for(int i=0;i<size;i++){
		if(arr[i].gender==Gender){
			cout<<"Student gender found: "<<endl;
			printRecord(&arr[i]);
			return;
		}
	}
	cout<<"Student gender not found"<<endl;	
}
double getOverAllCgpa(struct student_record arr[],int size,int index){
	if(index==size){
            return 0.0;
	}//using recursion to calculate overall cpga
	return (arr[index].CGPA + getOverAllCgpa(arr,size,index+1));
}

int main(){
	int choice;
	int numStudents=0;
	student_record students[20];//Declared structure variable
	while(true){
		 cout << "\nChoose an option:\n";
		 cout << "1. Add student records\n";
        	 cout << "2. Print/Display student Records\n";
       		 cout << "3. Search by student id\n";
       		 cout << "4. Search by student gender\n";
       		 cout << "5. Calculate overall CGPA\n";
       		 cout << "6. Exit\n";
       		 cout << "Enter your choice: ";
       		 std::cin >> choice;
       		 switch(choice){
       	 		case 1:{
               			 cout << "\nAdd a student Record:\n";	
               		    	 addRecord(students[numStudents]);
				 numStudents+=1;
               			}break;
            		case 2:{
               			 cout << "\nPrint/Display student Records:\n";
               			 for (int i = 0; i < numStudents; i++) {
               		    		 printRecord(&students[i]);
               			 }
               			}break;
            		case 3:{
               			 int searchId;
               			 cout << "Search student id: ";
               			 cin >> searchId;
               			 findStudentDetails(students, numStudents, searchId);
               			}break;
            		case 4:{string searchGender;
               			 cout << "Search student gender: ";
               			 cin >> searchGender;
               			 findStudentDetails(students, numStudents, searchGender);
               			 }break;
            		case 5:{
               			 double overallCgpa = getOverAllCgpa(students, numStudents, 0);
               			 cout << "Overall CGPA: " << overallCgpa << endl;
               			}break;
            		case 6:{
               			 cout << "Exiting program.\n";
               			 return 1;
				}break;

            		default:
               		 	cout << "Invalid choice. Please enter a valid option.\n";
			 	break;
        	}
	}
	return 0;
}

