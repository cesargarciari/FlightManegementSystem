/*
 *  File Name: Flight.h  
 */

 #ifndef FLIGHT_H
 #define FLIGHT_H

 #include <string>
 #include <vector>
 #include <fstream>
 #include <iostream>
 #include "Seat.h"
 #include "Passenger.h"

 using namespace std;

class Flight
{
private:
    string flight_number;
    vector<vector<Seat>> seat_map;
    vector<Passenger> passenger_list;
    int rows;
    int columns;
    

public:
    Flight();
    Flight(string fn, int r, int c);  
    ~Flight();

    vector<vector<Seat>>& get_seat_map();  
    string get_flight_number() const;
    vector<Passenger> get_passenger_list() const;
    int get_row() const;
    int get_column() const;

    void build_map();
    void print_map();
    void print_passengers();
    void add_passenger();
    void remove_passenger();
    void quick_add_passenger(const Passenger& p);


    void createFile();
    
};

#endif