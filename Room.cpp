#include "Room.hpp"

int Room::lastId = 0;

Room::Room(int number, RoomCategory category)
{
    this->id = generateId();
    this->number = number;
    this->category = CategoryHelper::parseRoomCategoryEnumToString(category);
}

int Room::getId()
{
    return this->id;
}

vector <Bed> Room::getBeds()
{
    return this->beds;
}

int Room::getNumber()
{
    return this->number;
}

string Room::getCategory()
{
    return this->category;
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