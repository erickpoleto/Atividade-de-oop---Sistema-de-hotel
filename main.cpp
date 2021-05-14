#include "HotelService.hpp"
#include "Hotel.hpp"
#include "Room.hpp"
#include "RoomCategory.hpp"

int main()
{
    HotelService hotelService(Hotel("hostel"));

    vector <Bed> beds;
    beds.push_back(Bed(BedCategory::SINGLE));

    hotelService.insertRoom(Room(200, RoomCategory::LUXURY, beds));
    hotelService.insertEmployee(Employee("jhonsonn"));
    hotelService.insertClient(Client("Erick", "Poleto", "55544455574"));
    hotelService.reserveRoom(1, 1, 1);

}