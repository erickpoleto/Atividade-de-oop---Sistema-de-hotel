#ifndef Employee_hpp
#define Employee_hpp

#include<iostream>
using namespace std;


class Employee
{
public:
    Employee(string name);
    
    int getId();
    
    string getName();
    bool isActive();

    void setActive();
    void setName(string name);

private:
    int id;
    string name;

    bool active;
    
    int static lastId;
    int generateId();

};

#endif