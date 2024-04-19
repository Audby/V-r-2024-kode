#include <string>

class Car 
{
private:
    int freeSeats;
public:
    Car(int seats) : freeSeats(seats) {}
    bool hasFreeSeats() const;
    void reserveFreeSeats();
};

class Person
{
private:
    string name;
    string email;

};