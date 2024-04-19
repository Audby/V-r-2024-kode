#include <string>
#include <memory>
#include <iostream>

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
    std::string name;
    std::string email;
    std::unique_ptr<Car> car;
public:
    Person(const std::string& n, const std::string& e, Car* c = nullptr) :
    name(n), email(e), car(std::unique_ptr<Car>(c)) {}
    std::string getEmail() const;
    std::string getName() const;
    void setEmail(const std::string& newEmail);
    bool hasAvailableSeats() const;
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};