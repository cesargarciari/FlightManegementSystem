#include "Passenger.h"

int Passenger::next_id = 4000;

Passenger::Passenger(){

}

Passenger::Passenger(string fname, string lname, string phone, Seat& st, int id)
    : first_name(fname), last_name(lname), phone_number(phone), seat(st), id(id){
    id = next_id++;
}

Passenger::Passenger(string fname, string lname,string phone, Seat& st)
: first_name(fname), last_name(lname), phone_number(phone), seat(st){
    id = next_id++;
}

Passenger::~Passenger() { }

#pragma region SETTERS
void Passenger::set_first(string f){
    first_name = f;
}

void Passenger::set_last(string l){
    last_name = l;
}

void Passenger::set_phone(string ph){
    phone_number = ph;
}

void Passenger::set_Seat(Seat st){
    seat = st;
}

#pragma endregion

#pragma region GETTERS
string Passenger::get_first() const{
    return first_name;
}

string Passenger::get_last() const{
    return last_name;
}

string Passenger::get_phone() const{
    return phone_number;
}
Seat Passenger:: get_Seat() const{
    return seat;
}

int Passenger::get_id() const{
    return id;
}

#pragma endregion

ostream& operator<<(ostream& os, const Passenger& p) {
    os << left  << setw(20) << p.first_name 
                << setw(20) << p.last_name
                << setw(20) << p.phone_number
                << setw(8) << p.seat.get_seat()
                << setw(8) << p.get_id();
    return os;
}
