#ifndef HotelService_hpp
#define HotelService_hpp

#include<iostream>
#include<vector>
#include "Hotel.hpp"
#include "Room.hpp"
#include "Employee.hpp"
#include "Client.hpp"
#include "ReservedRoom.hpp"
#include "RoomCategory.hpp"
using namespace std;


class HotelService
{
public:
    HotelService(Hotel hotel);
    
    void insertRoom(Room room);
    void insertEmployee(Employee employee);
    void insertClient(Client client);
    void reserveRoom(string clientCpf, int roomNumber, int employeeId);
    bool login(int id, string password);
    void showRooms();
    bool isReserved(int roomNumber);
    void showReservesRelatory();
    void showReservesPerClient(string clientCpf);
    void updateClient(Client client, string regisCpf);
    Employee getEmployee(int employeeId);
    Client getClient(string clientCpf);
    Room getRoom(int roomNumber);
    bool findClient(string cpf);

private:
    Hotel static hotel;

    bool findRoom(int roomNumber);
    bool findEmployee(int employeeId);
};

#endif