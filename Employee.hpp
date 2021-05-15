#ifndef Employee_hpp
#define Employee_hpp

#include<iostream>
using namespace std;


class Employee
{
public:
    Employee(string name, string password);
    
    int getId();
    
    string getName();
    string getPassword();
    bool isActive();

    void setActive();
    void setName(string name);

private:
    int id;
    string name;
    string password;

    bool active;
    
    int static lastId;
    int generateId();

};

#endif