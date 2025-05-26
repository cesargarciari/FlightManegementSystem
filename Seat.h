/*
 *  File Name: Seat.h  
 */

 #ifndef SEAT_H
 #define SEAT_H
 
 #include <string>

 using namespace std;

 class Seat
 {
 private:
    int row;
    int column;
    string seat;
    bool taken;
 public:
    Seat(int r, int c);
    Seat();
    ~Seat();

    int get_row() const;
    int get_column() const;
    string get_seat() const;
    bool get_status() const;

    void set_row(int r);
    void set_column(int c);
    void set_status(bool st);
 };

 #endif