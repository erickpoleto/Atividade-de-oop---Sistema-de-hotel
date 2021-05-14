#ifndef ReservedRooms_hpp
#define ReservedRooms_hpp

#include<iostream>
#include<vector>
#include "ReservedRoom.hpp"

using namespace std;


class ReservedRooms
{
public:
    
    void static addReservedRoom(ReservedRoom ReservedRoom);

    vector <ReservedRoom> static getReservedRooms();
    bool static isReserved(int roomId);

private:

    vector <ReservedRoom> static reservedRooms;

};

#endif