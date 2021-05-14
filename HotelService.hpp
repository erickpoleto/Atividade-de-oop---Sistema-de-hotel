#ifndef HotelService_hpp
#define HotelService_hpp

#include<iostream>
#include<vector>
#include "Hotel.hpp"
#include "Room.hpp"
#include "Employee.hpp"
#include "Client.hpp"
#include "ReservedRooms.hpp"
#include "ReservedRoom.hpp"
using namespace std;


class HotelService
{
public:
    HotelService(Hotel hotel);
    
    void insertRoom(Room room);
    void insertEmployee(Employee employee);
    void insertClient(Client client);
    void reserveRoom(int clientId, int roomId, int employeeId);
    void showRooms();

private:
    Hotel hotel;

    bool findRoom(int roomId);
    bool findEmployee(int employeeId);
    bool findClient(int clientId);
};

#endif