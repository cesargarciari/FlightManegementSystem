/*
 *  File Name: Passenger.h  
 */

 #ifndef PASSENGER_H
 #define PASSENGER_H
 
 #include <string>
 #include <iostream>
 #include <iomanip>
 #include "Seat.h"

 using namespace std;
 
 class Passenger
 {
 private:
    static int next_id; //To know what id to assign next
    int id;
    string first_name;
    string last_name;
    string phone_number;
    Seat seat;
    
 public:
    Passenger(string first, string last,string phone, Seat& st, int id);
    Passenger(string first, string last,string phone, Seat& st);
    Passenger();
    ~Passenger();

    void set_first(string f);
    void set_last(string l);
    void set_phone(string ph);
    void set_Seat(Seat s);

    string get_first() const;
    string get_last() const;
    string get_phone() const;
    Seat get_Seat() const;
    int get_id() const;
    friend ostream& operator<<(ostream& os, const Passenger& p);

 };
  

 #endif
