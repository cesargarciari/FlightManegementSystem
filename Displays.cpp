#include "Displays.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

int menu(){
    int choice = 0;
    cout << "What would you like to do?" << endl;
    cout << "  1. Display Flight Seat Map" << endl;
    cout << "  2. Display Passenger Information" << endl;
    cout << "  3. Add a New Passenger" << endl;
    cout << "  4. Remove an Existing Passenger" << endl;
    cout << "  5. Save data to a file" << endl;
    cout << "  6. Quit" << "\n" <<endl;
    cout << "  Enter your choice (1, 2, 3, 4, 5, or 6): ";

    while(!(cin >> choice)){
        cerr << "\n Invalid input Try again\n";
        cin.clear();
        cin.ignore(100, '\n');
        cout << "  Enter your choice (1, 2, 3, 4, 5, or 6): ";
    }
    cout << endl;
    return choice;
}

Flight populate_flight(const string filename) {
    ifstream inputfile(filename);

    if (inputfile.fail()) {
        cout << "File could not be opened" << endl;
        exit(1);
    }

    string flight_name;
    int rows, cols;

    inputfile >> flight_name >> rows >> cols;
    inputfile.ignore(); 

    Flight flight(flight_name, rows, cols); 

    string line;
    while (getline(inputfile, line)) {
        if (line.length() < 70) {
            cerr << "Skipping incomplete line: " << line << '\n';
            continue;
        }


        string fname = line.substr(0, 20);
        string lname = line.substr(20, 20);
        string phone = line.substr(40, 20);
        string seatStr = line.substr(60, 4);
        string idStr = line.substr(64, 5);


        fname.erase(fname.find_last_not_of(" ") + 1);
        lname.erase(lname.find_last_not_of(" ") + 1);
        phone.erase(phone.find_last_not_of(" ") + 1);
        seatStr.erase(remove_if(seatStr.begin(), seatStr.end(), ::isspace), seatStr.end());  // remove whitespace

        if (seatStr.length() < 2) {
            cerr << "Invalid seat string (too short): [" << seatStr << "]\n";
            continue;
        }

        char colChar = toupper(seatStr.back());
        int col = colChar - 'A';
        string rowStr = seatStr.substr(0, seatStr.length() - 1);

        int row;
        try {
            row = stoi(rowStr) - 1;  
        } catch (...) {
            cerr << "Invalid seat row in: [" << seatStr << "]\n";
            continue;
        }

        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cerr << "Seat out of bounds: " << seatStr << "\n";
            continue;
        }


        int id;
        try {
            id = stoi(idStr);
        } catch (...) {
            cerr << "Invalid ID: [" << idStr << "]\n";
            continue;
        }

   
        Seat& seat_ref = flight.get_seat_map()[row][col];
        seat_ref.set_status(true);
        Passenger p(fname, lname, phone, seat_ref, id);
        flight.quick_add_passenger(p);
    }

    inputfile.close();
    return flight;
}
