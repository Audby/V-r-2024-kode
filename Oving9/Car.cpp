#include "Car.h"
#include <memory>

bool Car::hasFreeSeats() const {
    return freeSeats > 0;
}

void Car::reserveFreeSeats() {
    freeSeats -= 1;
}

std::string Person::getEmail() const {
    return email;
}

std::string Person::getName() const {
    return name;
}

void Person::setEmail(const std::string& newEmail) {
    email = newEmail;
}

bool Person::hasAvailableSeats() const {
    return car != nullptr && car->hasFreeSeats();
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "Navn: " << p.getName() << " , e-post: " << p.getEmail() << '\n';
    os << (p.car ? " - Har bil" : " - Har ikke bil");
    return os;
}