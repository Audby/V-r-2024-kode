#include "DailyMenu.h"

const map<string, double> mainDishPrices {
    // Main dishes
    {"Burger", 55},
    {"Lasagna", 70},
    {"Chicken", 60},
    {"Porkchops", 65},
    {"Beef", 90},
    {"Soup", 50},
    {"Cinnamon bun", 25},
    {"Baguette", 54},
};

const map<string, double> sideDishPrices {
    {"Salad", 40},
    {"Fries", 30},
    {"Rice", 20},
    {"Mashed potatoes", 25},
    {"Pasta", 35},
    {"Caviar", 150},
    {"Couscous", 50},
    {"Root vegetables", 35}
};

const map<string, double> adjectivePriceModifiers {
    {"Vegan", 1.4},
    {"Vegetarian", 1.2},
    {"Gluten-free", 2.5},
    {"Lactose-free", 1.3},
    {"Sugar-free", 1.1},
    {"Whole grain", 1.2},
    {"Organic", 1.4},
    {"Local", 1.6}    

};

//------------------------------------------------------------------------------------------------

DailyMenu createDailyMenu(string adjective, string mainDish, string sideDish) {
    // BEGIN: 1a

    DailyMenu dummy;
    double mainDishPrice = mainDishPrices.at(mainDish);
    double sideDishPrice = sideDishPrices.at(sideDish);
    double adjectiveModifier = adjectivePriceModifiers.at(adjective);
    double price = adjectiveModifier * ((mainDishPrice + sideDishPrice));

    dummy.adjective = adjective;
    dummy.mainDish = mainDish;
    dummy.sideDish = sideDish;
    dummy.price = price;
    return dummy;

    // END: 1a
}
ostream& operator<<(ostream& os, DailyMenu d) {

    // BEGIN: 1b
    os << "Dagens meny: " << endl;
    os << "Hovedrett: " << d.mainDish << " - " << mainDishPrices.at(d.mainDish) << " kr" << endl;
    os << "Siderett: " << d.sideDish << " - " << sideDishPrices.at(d.sideDish) << " kr" << endl;
    os << "Totalpris med " << d.adjective << "-tillegg: " << d.price << " kr" << endl;
    return os;

    // END: 1b
}

string getDishFromNumber(map<string, double> m, int n) {
    int i = 0;
    for(const auto& dish : m) {
        if(i == n) {
            return dish.first;
        }
        i++;
    }
    
    return "";
}

DailyMenu getRandomMenu() {
    
    int mapSize = 8;
    // BEGIN: 2b
  
    DailyMenu dummy;
    return dummy;

    // END: 2b
}