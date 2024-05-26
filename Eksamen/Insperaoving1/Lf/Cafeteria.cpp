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
    return getWeeklyMenu().at(static_cast<unsigned long long>(w));
    // END: 1c
}

bool Cafeteria::isInStock(DailyMenu menu) {
    // BEGIN: 1d
    return (getStock(menu.mainDish) && getStock(menu.sideDish));
    // END: 1d
}

void Cafeteria::saveToFile(string fileName) {
    // BEGIN: 1e
    filesystem::path filePath(fileName);
    ofstream ofs{filePath};

    for(const auto& menu : weeklyMenu) {
        ofs << menu << endl;
    }

    ofs.close();
    // END: 1e
}


void Cafeteria::importStock(string fileName) {
    // BEGIN: 2a
    filesystem::path filePath(fileName);
    ifstream ifs{filePath};
    string dish, amount;

    while (getline(ifs, dish, ',')) {
        getline(ifs, amount);
        stock.at(dish) = stoi(amount);
    }

    ifs.close();
    // END: 2a
}


vector<DailyMenu> generateWeeklyMenu() {
    // BEGIN: 2c
    vector<DailyMenu> weeklyMenu;

    for(int i = 0; i < 7; i++) {
        weeklyMenu.push_back(getRandomMenu());
    }
    
    return weeklyMenu;
    // END: 2c
}