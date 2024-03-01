#include "databaseoperations.h"

using namespace std;
//establish connection
sql::Connection* establishConnection(const string& hostname, const string& username, const string& password, const string& schema) {
    sql::Driver *driver;
    sql::Connection *conn;
    try {
        driver = get_driver_instance(); 
        conn = driver->connect("tcp://" + hostname + ":3306", username, password); //establish a connection to MySQL database
        conn->setSchema(schema);
        return conn;
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        return nullptr;
    } 
}

//insert data
int insertData(sql::Connection *conn) {
    int e_id, e_age;
    string e_name;
    try {
        cout << "Enter employee ID: ";
        cin >> e_id;
        cout << "Enter employee name: ";
        cin >> e_name;
        cout << "Enter employee age: ";
        cin >> e_age;
        sql::Statement *stmt = conn->createStatement();
        int result = stmt->executeUpdate("INSERT INTO Employee_details(e_id, e_name, e_age) VALUES (" + to_string(e_id) + ", '" + e_name + "', " + to_string(e_age) + ")");
        delete stmt;
        if (result == 1) {
            cout << "Insert successful." << endl;
            return 0; 
        } else {
            cerr << "Failed to insert data." << endl;
            return -1; 
        }
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        return -1; 
    }
}

//update data
int updateData(sql::Connection *conn) {
    int e_id, new_age;

    try {
        cout << "Enter employee ID to update: ";
        cin >> e_id;
        cout << "Enter new age: ";
        cin >> new_age;

        sql::Statement *stmt = conn->createStatement();
        int result = stmt->executeUpdate("UPDATE Employee_details SET e_age = " + to_string(new_age) + " WHERE e_id = " + to_string(e_id));
        delete stmt;

        if (result == 1) {
            cout << "Update successful." << endl;
            return 0; 
        } else {
            cerr << "Failed to update data. Employee ID not found." << endl;
            return -1; 
        }
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        return -1; 
    } 
}

//delete data
int deleteData(sql::Connection *conn) {
    int e_id;
    try {
        cout << "Enter employee ID to delete: ";
        cin >> e_id;
        sql::Statement *stmt = conn->createStatement();
        int result = stmt->executeUpdate("DELETE FROM Employee_details WHERE e_id = " + to_string(e_id));
        delete stmt;
        if(result==1){
        	cout << "Deleted successfully."<<endl;
        	return 0;
        }else{
        	cout<< "Failed to delete"<<endl;
        	return -1;
        }		
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        return -1; // Failure
    } 
}

//print data
int printData(sql::Connection *conn) {
    try {
        sql::Statement *stmt = conn->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM Employee_details");
        while (res->next()) {	
            cout << res->getInt(1) << " " << res->getString(2) << " " << res->getInt(3) << endl;
        }
        delete res;
        delete stmt;
        return 0; 
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        return -1; 
    } 
}

//callprocedures
int callUpdateEmployeeAgeProcedure(sql::Connection *conn) {
    int employeeId, newEmployeeAge;
    try {
        cout << "Enter employee ID: ";
        cin >> employeeId;
        cout << "Enter new employee age: ";
        cin >> newEmployeeAge;
        string query = "CALL UpdateEmployeeAge(" + to_string(employeeId) + ", " + to_string(newEmployeeAge) + ")";
        sql::Statement *stmt = conn->createStatement();
        int result = stmt->executeUpdate(query);
        delete stmt;
        if (result == 1) {
            cout << "UpdateEmployeeAge procedure called successfully." << endl;
            return 0;
        } else {
            cerr << "Failed to call UpdateEmployeeAge procedure." << endl;
            return -1;
        }
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
        return -1;
    }
}

