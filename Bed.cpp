#include "Bed.hpp"

int Bed::lastId = 0;

Bed::Bed(BedCategory category)
{
    this->id = generateId();
    this->category = CategoryHelper::parseBedCategoryEnumToString(category);
}

int Bed::generateId()
{
    lastId++;
    return lastId;
}