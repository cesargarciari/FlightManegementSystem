#include "Seat.h"

Seat::Seat(int r, int c){
    row = r;
    column = c;
    seat = static_cast<char>('A' + column) + to_string(row + 1) ;
    taken = false;
}

Seat::Seat() {
    row = 0;
    column = 0;
    seat = "";
    taken = false;
}

Seat::~Seat() { }

int Seat::get_row() const{
    return row;
}

int Seat::get_column() const{
    return column;
}

bool Seat::get_status() const{
    return taken;
}

string Seat::get_seat() const{
    return seat;
}

void Seat::set_row(int r){
    row = r;
} 

void Seat::set_column(int c){
    column = c;
} 

void Seat::set_status(bool st){
    taken = st;
}


