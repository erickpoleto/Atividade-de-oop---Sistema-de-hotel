#ifndef Hotel_hpp
#define Hotel_hpp

#include<iostream>
#include<vector>
#include "Room.hpp"
#include "Client.hpp"
#include "Employee.hpp"
using namespace std;

class Hotel
{
public:
    Hotel();
    Hotel(string name);
    
    int getId();
    string getName();
    vector <Room> getRooms();
    vector <Employee> getEmployees();
    vector <Client> getClients();
    
    void setName(string name);
    void insertRoom(Room room);
    void insertEmployee(Employee employee);
    void insertClient(Client client);

private:
    int id;

    string name;
    vector <Room> rooms;
    vector <Employee> employees;
    vector <Client> clients;
    
    int static lastId;
    int generateId();
};

#endif