#ifndef ReservedRoom_hpp
#define ReservedRoom_hpp

#include<iostream>
using namespace std;


class ReservedRoom
{
public:
    ReservedRoom(int hotelId, int clientId, int roomId, int employeeId);

    int getId();
    int getHotelId();
    int getClientId();
    int getRoomId();
    int getEmployeeId();

private:
    int id;
    
    int hotelId;
    int clientId;
    int roomId;
    int employeeId;
    
    int static lastId;
    
    int generateId();

};

#endif