#include "Cafeteria.h"

Cafeteria::Cafeteria(string n, Location l) : name{n}, location{l} {
    for(auto p : mainDishPrices) {
        stock.insert({p.first, 0});
    }
    for(auto p : sideDishPrices) {
        stock.insert({p.first, 0});
    }
}

vector<DailyMenu> Cafeteria::getWeeklyMenu() {
    return weeklyMenu;
}

void Cafeteria::setWeeklyMenu(vector<DailyMenu> menu) {
    weeklyMenu = menu;
}

int Cafeteria::getStock (string item) {
    return stock.at(item);
}

void Cafeteria::setStock(string item, int amount) {
    stock.at(item) = amount;
}

void Cafeteria::removeStock(string item) {
    stock.at(item)--;
}

//------------------------------------------------------------------------------------------------

DailyMenu Cafeteria::getDailyMenu(Weekday w) {
    // BEGIN: 1c
    
    DailyMenu dummy;
    return dummy;

    // END: 1c
}

bool Cafeteria::isInStock(DailyMenu menu) {
    // BEGIN: 1d

    return false;

    // END: 1d
}

void Cafeteria::saveToFile(string fileName) {
    // BEGIN: 1e
    


    // END: 1e
}


void Cafeteria::importStock(string fileName) {
    // BEGIN: 2a



    // END: 2a
}


vector<DailyMenu> generateWeeklyMenu() {
    // BEGIN: 2c

    vector<DailyMenu> dummy;
    return dummy;

    // END: 2c
}