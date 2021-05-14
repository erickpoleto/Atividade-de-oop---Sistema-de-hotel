#ifndef CategoryHelper_hpp
#define CategoryHelper_hpp

#include "RoomCategory.hpp"
#include "BedCategory.hpp"
#include<iostream>
using namespace std;

class CategoryHelper
{
public:
    static string parseRoomCategoryEnumToString(RoomCategory category);
    static string parseBedCategoryEnumToString(BedCategory category);
};

#endif