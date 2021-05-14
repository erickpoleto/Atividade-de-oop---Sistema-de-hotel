#ifndef Room_hpp
#define Room_hpp

#include<iostream>
#include<vector>
#include "RoomCategory.hpp"
#include "Bed.hpp"
#include "CategoryHelper.hpp"
using namespace std;


class Room
{
public:
    Room(int number, RoomCategory category, vector <Bed> beds);

    int getId();

    int getNumber();
    string getCategory();

    void addBed(Bed bed);
    void removeBed(int bedId);

private:
    int id;

    int number;
    string category;
    vector <Bed> beds;
    
    int static lastId;
    int generateId();
};

#endif