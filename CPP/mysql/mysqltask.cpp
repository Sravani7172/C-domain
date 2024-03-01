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
    conn = driver->connect("tcp://localhost:3306", "sravani", "Sravs@7172");
    conn->setSchema("Employee");

    // Insert data
    stmt = conn->createStatement();
    stmt->executeUpdate("INSERT INTO Employee_details(e_id, e_name, e_age) VALUES (77, 'kittu', 26)");

    // Update data
    stmt->executeUpdate("UPDATE Employee_details SET e_age = 25 WHERE e_id = 73");
    
    // Delete data
    stmt->executeUpdate("DELETE FROM Employee_details WHERE e_id = 75");

    // Print data
    res = stmt->executeQuery("SELECT * FROM Employee_details");

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

