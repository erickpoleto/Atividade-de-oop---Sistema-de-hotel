#ifndef ReservedRoom_hpp
#define ReservedRoom_hpp

#include<iostream>
using namespace std;


class ReservedRoom
{
public:
    ReservedRoom(int hotelId, string clientCpf, int roomNumber, int employeeId);

    int getId();
    int getHotelId();
    string getClientCpf();
    int getRoomNumber();
    int getEmployeeId();

private:
    int id;
    
    int hotelId;
    string clientCpf;
    int roomNumber;
    int employeeId;
    
    int static lastId;
    
    int generateId();

};

#endif