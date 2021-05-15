#include "ReservedRoom.hpp"

int ReservedRoom::lastId = 0;

ReservedRoom::ReservedRoom(int hotelId, string clientCpf, int roomNumber, int employeeId)
{
    this->id = generateId();
    this->hotelId = hotelId;
    this->clientCpf = clientCpf;
    this->roomNumber = roomNumber;
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

string ReservedRoom::getClientCpf()
{
    return this->clientCpf;
}

int ReservedRoom::getRoomNumber()
{
    return this->roomNumber;
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