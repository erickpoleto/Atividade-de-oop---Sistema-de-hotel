#include "HotelService.hpp"

Hotel HotelService::hotel;

HotelService::HotelService(Hotel hotel)
{
    HotelService::hotel = hotel;
}

void HotelService::showReservesPerClient(string clientCpf)
{
    int count;
    for(int i = 0; i < this->hotel.getReservedRooms().size(); i++)
    {
        if(this->hotel.getReservedRooms()[i].getClientCpf() == clientCpf)
        {
            cout << "client name: " << this->getClient(this->hotel.getReservedRooms()[i].getClientCpf()).getName() << " - "
                << "client last name: " << this->getClient(this->hotel.getReservedRooms()[i].getClientCpf()).getLastName() << " - "
                << "client cpf: " << clientCpf << " - "
                << "room number: " << this->hotel.getReservedRooms()[i].getRoomNumber() << " - "
                << "room category: " << this->getRoom(this->hotel.getReservedRooms()[i].getRoomNumber()).getCategory() << " - "
                << "room beds: " << this->getRoom(this->hotel.getReservedRooms()[i].getRoomNumber()).getBeds().size() << " - " << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "no reserves" << endl;
        return;
    }
    
    cout << "totals: " << count << endl; 
}

void HotelService::showReservesRelatory()
{
    int count;
    for(int i = 0; i < this->hotel.getReservedRooms().size(); i++)
    {
        cout << "client name: " << this->getClient(this->hotel.getReservedRooms()[i].getClientCpf()).getName() << " - "
            << "client last name: " << this->getClient(this->hotel.getReservedRooms()[i].getClientCpf()).getLastName() << " - "
            << "client cpf: " << this->hotel.getReservedRooms()[i].getClientCpf() << " - "
            << "room number: " << this->hotel.getReservedRooms()[i].getRoomNumber() << " - "
            << "room category: " << this->getRoom(this->hotel.getReservedRooms()[i].getRoomNumber()).getCategory() << " - "
            << "room beds: " << this->getRoom(this->hotel.getReservedRooms()[i].getRoomNumber()).getBeds().size() << " - ";
            for(int j = 0; j < this->getRoom(this->hotel.getReservedRooms()[i].getRoomNumber()).getBeds().size(); j ++)
            {
                cout << "bed[" << j << "] category: " << this->getRoom(this->hotel.getReservedRooms()[i].getRoomNumber()).getBeds()[j].getCategory() << " - ";
            }
            cout << "employee: " << this->getEmployee(this->hotel.getReservedRooms()[i].getEmployeeId()).getName() <<  " - " << endl;
            count ++;
    }
    if (count == 0)
    {
        cout << "no reserves" << endl;
        return;
    }

    cout << "totals: " << count << endl; 
}

Room HotelService::getRoom(int roomNumber)
{
    Room room(0, RoomCategory::SIMPLE);

    for(int i = 0; i < this->hotel.getRooms().size(); i++)
    {
        if(this->hotel.getRooms()[i].getNumber() == roomNumber)
        {
            room = this->hotel.getRooms()[i];
        }
    }
    return room;
}

Client HotelService::getClient(string clientCpf)
{
    Client client("", "", "");

    for(int i = 0; i < this->hotel.getClients().size(); i++)
    {
        if(this->hotel.getClients()[i].getCpf() == clientCpf)
        {
            client = this->hotel.getClients()[i];
        }
    }
    return client;
}

Employee HotelService::getEmployee(int employeeId)
{
    Employee employee("", "");

    for(int i = 0; i < this->hotel.getEmployees().size(); i++)
    {
        if(this->hotel.getEmployees()[i].getId() == employeeId)
        {
            employee = this->hotel.getEmployees()[i];
        }
    }
    return employee;
}

bool HotelService::isReserved(int roomNumber)
{   
    bool reserved = false;

    for(int i = 0; i < this->hotel.getReservedRooms().size(); i++)
    {
        if(this->hotel.getReservedRooms()[i].getRoomNumber() == roomNumber)
        {
            reserved = true;
        }
    }
    return reserved;
}


void HotelService::insertRoom(Room room)
{
    if(room.getCategory() == CategoryHelper::parseRoomCategoryEnumToString(RoomCategory::LUXURY))
    {
        Bed bed(BedCategory::DOUBLE);
        room.addBed(bed);
    } else {
        Bed bed(BedCategory::SINGLE);
        Bed bed1(BedCategory::SINGLE);
        Bed bed2(BedCategory::SINGLE);
        room.addBed(bed);
        room.addBed(bed1);
        room.addBed(bed2);
    }
    this->hotel.insertRoom(room);
}

void HotelService::insertEmployee(Employee employee)
{
    this->hotel.insertEmployee(employee);
}

void HotelService::updateClient(Client client, string regisCpf)
{
    for(int i = 0; i < this->hotel.getClients().size(); i++)
    {
        if(this->hotel.getClients()[i].getCpf() == client.getCpf())
        {
            this->hotel.getClients()[i].setName(client.getName());
            this->hotel.getClients()[i].setLastName(client.getLastName());
            this->hotel.getClients()[i].setCpf(client.getCpf());
            cout << "Client Updated!" << endl;
        } else {
            cout << "Client not found" << endl;
        }
    }
}

void HotelService::insertClient(Client client)
{
    if(this->hotel.getClients().size() == 0)
    {
        this->hotel.insertClient(client);
        cout << "Client registered" << endl;
        return;
    }

    for(int i = 0; i < this->hotel.getClients().size(); i++)
    {
        if(this->hotel.getClients()[i].getCpf() != client.getCpf())
        {
            
            this->hotel.insertClient(client);
            cout << "Client registered" << endl;
        } else {
            cout << "Client not registered: cpf already registered" << endl;
        }
    }
}

void HotelService::reserveRoom(string clientCpf, int roomNumber, int employeeId)
{
    bool err;

    bool clientFound, roomFound, employeeFound;

    clientFound = this->findClient(clientCpf);
    roomFound = this->findRoom(roomNumber);
    employeeFound = this->findEmployee(employeeId);

    if(clientFound && roomFound && employeeFound)
    {
        if(!this->isReserved(roomNumber))
        {
            this->hotel.insertReservedRoom(ReservedRoom(this->hotel.getId(), clientCpf, roomNumber, employeeId));
            cout << "Room reserved!" << endl;
        } else {
            cout << "Room already reserved" << endl;
        }
    } else {
        string err = !clientFound ? "Client Not Registered" :
            !roomFound ? "Room not Registered" : "Employee not found";
            
        cout << err << endl; 
    }

}

bool HotelService::findClient(string cpf)
{
    bool found = false;

    for(int i = 0; i < this->hotel.getClients().size(); i++)
    {
        if(this->hotel.getClients()[i].getCpf() == cpf)
        {
            found = true;
        }
    }

    return found;
}

bool HotelService::findRoom(int roomNumber)
{
    bool found = false;

    for(int i = 0; i < this->hotel.getRooms().size(); i++)
    {
        if(this->hotel.getRooms()[i].getNumber() == roomNumber)
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

bool HotelService::login(int id, string password)
{
    bool loggedId = false;
    for(int i = 0; i < this->hotel.getEmployees().size(); i++)
    {
        if(this->hotel.getEmployees()[i].getId() == id &&
            this->hotel.getEmployees()[i].getPassword() == password)
        {
            loggedId = true;
        }
    }
    return loggedId;
}

void HotelService::showRooms()
{
    for(int i = 0; i < this->hotel.getRooms().size(); i++)
    {
        cout << "id: " << this->hotel.getRooms()[i].getId() << " - " 
            << "number: " << this->hotel.getRooms()[i].getNumber() << " - "
            << "category: " << this->hotel.getRooms()[i].getCategory() << endl;
    }
}
