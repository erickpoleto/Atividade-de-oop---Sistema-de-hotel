#include "Room.hpp"

int Room::lastId = 0;

Room::Room(int number, RoomCategory category, vector <Bed> beds)
{
    this->id = generateId();
    this->number = number;
    this->category = CategoryHelper::parseRoomCategoryEnumToString(category);
}

int Room::getId()
{
    return this->id;
}

int Room::getNumber()
{
    return this->number;
}

void Room::addBed(Bed bed)
{
    this->beds.push_back(bed);
}

int Room::generateId()
{
    lastId++;
    return lastId;
}