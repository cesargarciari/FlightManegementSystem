#include "Flight.h"


Flight::Flight(string fn, int r, int c) {
    flight_number = fn;
    rows = r;
    columns = c;
    build_map();
}

Flight::Flight(){
    
}

Flight::~Flight() { }

#pragma region GETTERS
string Flight::get_flight_number() const{
    return flight_number;
}

vector<vector<Seat>>& Flight::get_seat_map() {
    return seat_map;
}

vector<Passenger> Flight::get_passenger_list() const{
    return passenger_list;
}

int Flight::get_row() const{
    return rows;
}

int Flight::get_column() const{
    return columns;
}

#pragma endregion

#pragma region MAP FUNCTIONS

void Flight::build_map(){
    seat_map.resize(rows, vector<Seat>(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            seat_map[i][j] = Seat(i, j);
        }   
    }
}

void Flight::print_map(){
    
    printf("   ");
    for (int i = 0; i < columns; i++)
    {
     printf(" %c ", 'A'+ i);
     if ((i + 1) % 3 == 0 && i != columns - 1) {
                printf("  ");  
            }
    }
    printf("\n");

     for (int i = 0; i < rows; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < columns; j++) {
            if (seat_map[i][j].get_status()) {
                cout <<"[X]";
            } else {
               cout << "[ ]";
            }

            if ((j + 1) % 3 == 0 && j != columns - 1) {
                printf("  ");  
            }
        }
        printf("\n");
    }

    
}
#pragma endregion

#pragma region PASSENGER FUNCTIONS
void Flight::print_passengers(){
    cout << left    << setw(20) << "First Name" 
                    << setw(20) << "Last Name" 
                    << setw(20) << "Phone Number" 
                    << setw(8) << "Seat"
                    << setw(8) << "Id"
                    << "\n\n";
    
    for(Passenger passenger: passenger_list){
        cout << passenger << "\n";
    }  

    cout << '\n';
    }

void Flight::add_passenger() {
    string first, last, phone;
    string seat_input;

    cin.ignore();  

    cout << "Enter first name: ";
    getline(cin, first);
    toupper(first.at(0));

    cout << "Enter last name: ";
    getline(cin, last);
    toupper(last.at(0));

    cout << "Enter phone number (0123456789): ";
    cin >> phone;

    string valid_phone;
    for(char c: phone){
        if(isdigit(c)){
            valid_phone += c;
        }
    }

    while (valid_phone.length() != 10) {
        cout << "Invalid input. Please enter exactly 10 digits: ";
        cin >> phone;

        valid_phone.clear();
        for (char c : phone) {
            if (isdigit(c)) {
                valid_phone += c;
            }
        }
    }
    string formatted_phone = valid_phone.substr(0, 3) + "-" +
                         valid_phone.substr(3, 3) + "-" +
                         valid_phone.substr(6, 4);

    Seat* selected_seat = nullptr;

while (true) {
    cout << "Enter seat (e.g., A4): ";
    cin >> seat_input;

    if (seat_input.length() < 2) {
        cout << "Invalid seat format.\n";
        continue;
    }

    char col_char = toupper(seat_input[0]);
    int col = col_char - 'A';

    int row;
    try {
        row = stoi(seat_input.substr(1)) - 1;
    } catch (...) {
        cout << "Invalid row number.\n";
        continue;
    }

    if (row < 0 || row >= rows || col < 0 || col >= columns) {
        cout << "Invalid seat position.\n";
        continue;
    }

    Seat& seat = seat_map[row][col];
    if (seat.get_status()) {
        cout << "Seat is already taken.\n";
        continue;
    }

    selected_seat = &seat;
    break;
}

    selected_seat->set_status(true);
    Passenger p(first, last, formatted_phone, *selected_seat);
    passenger_list.push_back(p);

    cout << "Passenger added successfully to seat " << selected_seat->get_seat() << ".\n";
}

void Flight::remove_passenger(){
    int passenger_id;
    bool found = false;
    print_passengers();
    cout << "Enter the ID of the passenger you wish to remove:";
    cin >> passenger_id;

    for(int i = 0; i < passenger_list.size(); i++){
        if (passenger_list[i].get_id() == passenger_id)
        {
            int row = passenger_list[i].get_Seat().get_row();
            int column = passenger_list[i].get_Seat().get_column();
            seat_map[row][column].set_status(false);                    //Free the seat

            passenger_list.erase(passenger_list.begin()+ i);
            cout << "Passenger removed successfully. \n";

            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Passenger not found.\n";
    }
}

void Flight::quick_add_passenger(const Passenger& p){
    passenger_list.push_back(p);
}

#pragma endregion

#pragma region FILE HANDLING
void Flight::createFile(){
    ofstream outputFile("Flight.txt");

    if (outputFile.is_open()) {
        //Write logic
        outputFile << left << setw(10) << get_flight_number() << setw(3) << get_row() << setw(2) << get_column() << "\n";
        for(Passenger p: passenger_list){
            outputFile << p << '\n';
        }
        outputFile.close();
    } else {
        cout << "Could not open file for writing." << endl;
    }
}



#pragma endregion