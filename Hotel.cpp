#include "Hotel.hpp"

int Hotel::lastId = 0;

Hotel::Hotel()
{

};

Hotel::Hotel(string name)
{
    this->id = generateId();
    this->name = name;
}

void Hotel::insertRoom(Room room)
{
    this->rooms.push_back(room);
}

void Hotel::insertEmployee(Employee employee)
{
    this->employees.push_back(employee);
}

void Hotel::insertClient(Client client)
{
    this->clients.push_back(client);
}

int Hotel::getId()
{
    return this->id;
}

string Hotel::getName()
{
    return this->name;
}

void Hotel::setName(string name)
{
    this->name = name;
}

vector <Room> Hotel::getRooms()
{
    return this->rooms;
}


vector <Client> Hotel::getClients()
{
    return this->clients;
}


vector <Employee> Hotel::getEmployees()
{
    return this->employees;
}

int Hotel::generateId()
{
    lastId++;
    return lastId;
}