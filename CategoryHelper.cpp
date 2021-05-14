#include "CategoryHelper.hpp"

string CategoryHelper::parseRoomCategoryEnumToString(RoomCategory category)
{
    switch (category)
    {
    case RoomCategory::LUXURY :
        return "Luxury";
    case RoomCategory::SIMPLE :
        return "Simple";
    default:
        return "Simple";
    }
}

string CategoryHelper::parseBedCategoryEnumToString(BedCategory category)
{
    switch (category)
    {
    case BedCategory::DOUBLE :
        return "double";
    case BedCategory::SINGLE :
        return "single";
    default:
        return "single";
    }
}


