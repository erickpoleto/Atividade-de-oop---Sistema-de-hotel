#include "ReservedRoom.hpp"

int ReservedRoom::lastId = 0;

ReservedRoom::ReservedRoom(int hotelId, int clientId, int roomId, int employeeId)
{
    this->id = generateId();
    this->hotelId = hotelId;
    this->clientId = clientId;
    this->roomId = roomId;
    this->employeeId = employeeId;
}

int ReservedRoom::getId()
{
    return this->id;
}

int ReservedRoom::getHotelId()
{
    return this->hotelId;
}

int ReservedRoom::getClientId()
{
    return this->clientId;
}

int ReservedRoom::getRoomId()
{
    return this->roomId;
}

int ReservedRoom::getEmployeeId()
{
    return this->employeeId;
}

int ReservedRoom::generateId()
{
    lastId++;
    return lastId;
}