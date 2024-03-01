#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    sql::Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;

    try {
        // Create a MySQL driver instance
        driver = get_driver_instance();

        // Establish a connection to the MySQL database
        cout << "Enter MySQL host (default is localhost): ";
        string host;
        getline(cin, host);

        cout << "Enter MySQL port (default is 3306): ";
        string port;
        getline(cin, port);

        cout << "Enter MySQL username: ";
        string username;
        getline(cin, username);

        cout << "Enter MySQL password: ";
        string password;
        getline(cin, password);

        conn = driver->connect("tcp://" + host + ":" + port, username, password);

        // Take database, table, and columns dynamically from the user
        cout << "Enter database name: ";
        string databaseName;
        getline(cin, databaseName);

        cout << "Enter table name: ";
        string tableName;
        getline(cin, tableName);

        cout << "Enter columns (comma-separated): ";
        string columns;
        getline(cin, columns);

        // Check if the database exists, if not create it
        stmt = conn->createStatement();
        stmt->executeUpdate("CREATE DATABASE IF NOT EXISTS " + databaseName);
        conn->setSchema(databaseName);

        // Create table if not exists
        string createTableQuery = "CREATE TABLE IF NOT EXISTS " + tableName + " (" + columns + ")";
        stmt->executeUpdate(createTableQuery);

        // Take number of rows to insert from the user
        int numRows;
        cout << "Enter number of rows to insert: ";
        cin >> numRows;
        cin.ignore(); // Ignore newline character

        // Insert data in a loop
        for (int i = 0; i < numRows; ++i) {
            cout << "Enter data for row " << (i + 1) << " (comma-separated values for columns): ";
            string rowData;
            getline(cin, rowData);
            string insertQuery = "INSERT INTO " + tableName + " VALUES (" + rowData + ")";
            stmt->executeUpdate(insertQuery);
        }

        // Print data
        res = stmt->executeQuery("SELECT * FROM " + tableName);

        while (res->next()) {
            cout << res->getInt(1) << " " << res->getString(2) << " " << res->getInt(3) << endl;
        }

        delete res;
        delete stmt;
        delete conn;
    } catch (sql::SQLException &e) {
        cerr << "SQLException: " << e.what() << endl;
    } catch (std::exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

