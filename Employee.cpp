#include "Employee.hpp"

int Employee::lastId = 0;

Employee::Employee(string name, string password)
{
    this->id = generateId();
    this->name = name;
    this->password = password;
}

int Employee::getId()
{
    return this->id;
}

string Employee::getName()
{
    return this->name;
}

string Employee::getPassword()
{
    return this->password;
}

void Employee::setName(string name)
{
    this->name = name;
}

int Employee::generateId()
{
    lastId++;
    return lastId;
}