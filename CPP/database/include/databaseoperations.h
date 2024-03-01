#ifndef DATABASE_OPERATIONS_H
#define DATABASE_OPERATIONS_H
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
class MysqlDataBase {
public:
    MysqlDataBase(const std::string& hostname, const std::string& username, const std::string& password, const std::string& schema);
    ~MysqlDataBase();
    int insertData();
    int updateData();
    int deleteData();
    int printData();
    int callUpdateEmployeeAgeProcedure();
private:
    sql::Connection* establishConnection();
    sql::Connection *conn;
    std::string hostname;
    std::string username;
    std::string password;
    std::string schema;
};
#endif


