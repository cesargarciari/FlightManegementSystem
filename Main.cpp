#include "Displays.h"

int main() {
    Flight temp;
    temp = populate_flight("flight_info.txt");


    while (true)
    {
        switch (menu())
        {
        case 1:
            temp.print_map();
            break;
        case 2:
            temp.print_passengers();
            break;
        case 3:
            temp.add_passenger();
            break;
        case 4:
            temp.remove_passenger();
            break;
        case 5:
            temp.createFile();
            break;
        case 6:
            cout << "Thank you! \n";
            exit(1);
        default:
            cout << "Invalid Option, not within bounds \n";
            break;
        }
    }
    
    return 0;
}
