#ifndef MY_HTTP_METHODS_H
#define MY_HTTP_METHODS_H
#include <string>
#include <iostream>
using namespace std;
class MyHttpMethods {
public:
    MyHttpMethods();
    ~MyHttpMethods();
    string get(const string& url);  
    string post(const string& url, const string& data);  
    string put(const string& url, const string& data); 
    string del(const string& url);  
};
#endif
