#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H
using namespace std;
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

sql::Connection* establishConnection(const string& hostname, const string& username, const string& password, const string& schema);
int insertData(sql::Connection *conn);
int updateData(sql::Connection *conn);
int deleteData(sql::Connection *conn);
int printData(sql::Connection *conn);
int callUpdateEmployeeAgeProcedure(sql::Connection *conn);

#endif 

