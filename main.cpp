#include "HotelService.hpp"
#include "Hotel.hpp"
#include "Room.hpp"
#include "RoomCategory.hpp"

void mockRooms(HotelService hotelService);
void mockEmployees(HotelService hotelService);
void verifyRoom(HotelService hotelService);
void registerClient(HotelService hotelService);
void updateClient(HotelService hotelService);
void reserveRoom(HotelService hotelService, int employeeId);
void verifyReservesPerClient(HotelService hotelService);
void showReservesPerClient(HotelService hotelService);

int main()
{
    Hotel hotel("hostel");

    HotelService hotelService(hotel);

    mockRooms(hotelService);
    mockEmployees(hotelService);
    
    int employeeId;

    while (true)
    {
        string pass;

        cout << "--login--" << endl;
        cout << "id: ";
        cin >> employeeId;
        cout << "Pass: ";
        cin >> pass;
        if(hotelService.login(employeeId, pass))
        {
            cout << "logged In" << endl;
            break;
        } else {
            cout << "id or pass invalid" << endl;
        }
    }

    while (true)
    {
        int option;
        cout << "" << endl;
        cout << "-- Hotel " << hotel.getName() << " --" << endl;
        cout << "Sys: v0.1-beta2" << endl;
        cout << "1 - list rooms" << endl;
        cout << "2 - verify room" << endl;
        cout << "3 - register client" << endl;
        cout << "4 - update client" << endl;
        cout << "5 - reserve room" << endl;
        cout << "6 - show reserves relatory" << endl;
        cout << "7 - show reserves per client" << endl;
        cout << "8 - exit" << endl;
        cout << "choose: ";
        cin >> option;
        
        switch (option)
        {
        case 1:
            hotelService.showRooms();
            break;
        case 2:
            verifyRoom(hotelService);
            break;
        case 3:
            registerClient(hotelService);
            break;
        case 4:
            updateClient(hotelService);
            break;
        case 5:
            reserveRoom(hotelService, employeeId);
            break;
        case 6:
            cout << "--Reserves relatory--" << endl;
            hotelService.showReservesRelatory();
            break;
        case 7:
            showReservesPerClient(hotelService);
            break;
        case 8: 
            exit(0);
            break;
        default:
            cout << "invalid option" << endl;
            break;
        }
    }
    
}
void showReservesPerClient(HotelService hotelService)
{
    string cpf;
    cout << "-- Reserves Per client --" << endl;
    cout << "Client cpf: ";
    cin >> cpf;

    hotelService.showReservesPerClient(cpf);
}


void reserveRoom(HotelService hotelService, int employeeId)
{
    string cpf;
    int roomNumber;

    cout << "-- Reserve Room --" << endl;
    cout << "Client cpf: ";
    cin >> cpf;
    cout << "Room number: ";
    cin >> roomNumber;
    
    hotelService.reserveRoom(cpf, roomNumber, employeeId);
}

void updateClient(HotelService hotelService)
{
    
    string regisCpf;
    string name;
    string lastName;
    string cpf;

    cout << "-- update client --" << endl;
    cout << "registered client cpf:";
    cin >> regisCpf;
    if (hotelService.findClient(regisCpf))
    {
        cout << "name: ";
        cin >> name;
        cout << "last name: ";
        cin >> lastName;
        cout << "cpf: ";
        cin >> cpf;
        
        hotelService.updateClient(Client(name, lastName, cpf), regisCpf);
        return;
    } 
    cout << "Client Not Found!" << endl;
}

void registerClient(HotelService hotelService)
{
    string name;
    string lastName;
    string cpf;

    cout << "-- Register client --" << endl;
    cout << "name: ";
    cin >> name;
    cout << "last name: ";
    cin >> lastName;
    cout << "cpf: ";
    cin >> cpf;
    
    hotelService.insertClient(Client(name, lastName, cpf));
}

void verifyRoom(HotelService hotelService)
{
    int roomNumber;
    cout << "-- Verify room --" << endl;
    cout << "roomId: ";
    cin >> roomNumber;
    bool reserved = hotelService.isReserved(roomNumber);
    if(reserved) 
    {
        cout << "Room already reserved" << endl;
    } else {
        cout << "Free Room" << endl;
    }
}

void mockEmployees(HotelService hotelService)
{
    hotelService.insertEmployee(Employee("carmack", "123"));
    hotelService.insertEmployee(Employee("jhon", "321654"));
    hotelService.insertEmployee(Employee("bowie", "abcde2"));
}

void mockRooms(HotelService hotelService)
{
    for (int i = 0; i < 20; i++)
    {
        if(i % 2 == 0)
        {
            hotelService.insertRoom(Room(i+100, RoomCategory::SIMPLE));
        } else {
            hotelService.insertRoom(Room(i+100,RoomCategory::LUXURY));
        }
    }
}