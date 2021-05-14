#ifndef Bed_hpp
#define Bed_hpp

#include<iostream>
#include "BedCategory.hpp"
#include "CategoryHelper.hpp"
using namespace std;


class Bed
{
public:
    Bed(BedCategory category);
    string getCategory();

private:
    int id;

    string number;
    string category;

    int static lastId;
    int generateId();
};

#endif