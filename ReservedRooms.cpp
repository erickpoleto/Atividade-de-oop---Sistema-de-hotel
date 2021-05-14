#include "ReservedRooms.hpp"

vector <ReservedRoom> ReservedRooms::reservedRooms;


void ReservedRooms::addReservedRoom(ReservedRoom reservedRoom)
{
    ReservedRooms::reservedRooms.push_back(reservedRoom);
    cout << "Reserved!" << endl;
}

vector <ReservedRoom> ReservedRooms::getReservedRooms()
{
    return ReservedRooms::reservedRooms;
}

bool ReservedRooms::isReserved(int roomId)
{   
    bool reserved = false;

    for(int i = 0; i < ReservedRooms::getReservedRooms().size(); i++)
    {
        if(ReservedRooms::getReservedRooms()[i].getId() == roomId)
        {
            reserved = true;
        }
    }
    return reserved;
}