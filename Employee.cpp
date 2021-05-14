#include "Employee.hpp"

int Employee::lastId = 0;

Employee::Employee(string name)
{
    this->id = generateId();
    this->name = name;
}

int Employee::getId()
{
    return this->id;
}

string Employee::getName()
{
    return this->name;
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