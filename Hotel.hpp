#ifndef Hotel_hpp
#define Hotel_hpp

#include<iostream>
#include<vector>
#include "Room.hpp"
#include "Client.hpp"
#include "Employee.hpp"
#include "ReservedRoom.hpp"
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
    vector <ReservedRoom> getReservedRooms();
    
    void setName(string name);
    void insertRoom(Room room);
    void insertEmployee(Employee employee);
    void insertClient(Client client);
    void insertReservedRoom(ReservedRoom reservedRoom);

private:
    int id;

    string name;
    vector <Room> rooms;
    vector <Employee> employees;
    vector <Client> clients;
    vector <ReservedRoom> reservedRooms;

    int static lastId;
    int generateId();
};

#endif