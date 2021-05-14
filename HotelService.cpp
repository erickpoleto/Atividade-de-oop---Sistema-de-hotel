#include "HotelService.hpp"


HotelService::HotelService(Hotel hotel)
{
    this->hotel = hotel;
}

void HotelService::insertRoom(Room room)
{
    this->hotel.insertRoom(room);
}

void HotelService::insertEmployee(Employee employee)
{
    this->hotel.insertEmployee(employee);
}

void HotelService::insertClient(Client client)
{
    this->hotel.insertClient(client);
}

void HotelService::reserveRoom(int clientId, int roomId, int employeeId)
{
    bool err;

    bool clientFound, roomFound, employeeFound;

    clientFound = this->findClient(clientId);
    roomFound = this->findRoom(roomId);
    employeeFound = this->findEmployee(employeeId);

    if(clientFound && roomFound && employeeFound)
    {
        if(!ReservedRooms::isReserved(roomId))
        {
            ReservedRooms::addReservedRoom(ReservedRoom(this->hotel.getId(), clientId, roomId, employeeId));
        } else {
            cout << "Room already reserved" << endl;
        }
    } else {
        string err = !clientId ? "Client Not Registered" :
            !roomId ? "Room not Registered" : "Employee not found";
            
        cout << err << endl; 
    }

}

bool HotelService::findClient(int clientId)
{
    bool found = false;

    for(int i = 0; i < this->hotel.getClients().size(); i++)
    {
        if(this->hotel.getClients()[i].getId() == clientId)
        {
            found = true;
        }
    }

    return found;
}

bool HotelService::findRoom(int roomId)
{
    bool found = false;

    for(int i = 0; i < this->hotel.getRooms().size(); i++)
    {
        if(this->hotel.getRooms()[i].getId() == roomId)
        {
            found = true;
        }
    }

    return found;
}

bool HotelService::findEmployee(int employeeId)
{
    bool found = false;

    for(int i = 0; i < this->hotel.getEmployees().size(); i++)
    {
        if(this->hotel.getEmployees()[i].getId() == employeeId)
        {
            found = true;
        }
    }

    return found;
}

void HotelService::showRooms()
{
    for(int i = 0; i < this->hotel.getRooms().size(); i++)
    {
        cout << this->hotel.getRooms()[i].getNumber() << endl;
    }
}
