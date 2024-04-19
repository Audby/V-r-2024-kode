#include "Car.h"

bool Car::hasFreeSeats() const {
    return freeSeats > 0;
}

void Car::reserveFreeSeats() {
    freeSeats -= 1;
}

void Person::setEmail(const std::string& newEmail) {
    email = newEmail;
}

Person::Person(std::string& n, std::string& e, Car* c = nullptr) {
    name = n;
    email = e;

}