//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "vector"

//------------------------------------------------------------------------------'

//Oppgave 1a)
/*
Private: Navnet kan kun brukes av medlemmer i klassen det er deklarert. 
Public: Navnet kan brukes av alle funksjoner.
Protected: Navnet kan kun brueks av medlemmer i klassen der det er deklarert og medlemmer fra klasser
som kommer derifra.
*/ 

//Oppgave 1b)
class Animal {
protected:
    string name;
    int age;
public:
    Animal(string name, int age) : name(name), age(age) {}
    virtual ~Animal() {}
    virtual string toString() = 0;
};

//Oppgave 1c)
class Cat : public Animal {
public:
    Cat(string name, int age) : Animal(name, age) {}
    virtual string toString() override {
        return "Cat: name, " + name + "; age, " + toString();
    }
};

class Dog : public Animal {
public:
    Dog(string name, int age) : Animal(name, age) {}
    virtual string toString() override {
        return "Dog: name, " + name + "; age, " + toString();
    }
};

//Oppgave 1d)
void testAnimal() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(make_unique<Cat>("Pus", 3));
    animals.emplace_back(make_unique<Dog> ("Hund", 2));

    for (const auto& animal : animals) {
        cout << animal->toString() << endl;
    }
}; 

//Oppgave 1e) Hvis vi nå prøver å lage et animal objekt vil det ikke klare å kompilere, siden
//vi nå er avhengig av at toString-funksjonen overstyres av en ikke-abstrakt klasse.

/*int main() {
    testAnimal();


    return 0;
}*/

//------------------------------------------------------------------------------
