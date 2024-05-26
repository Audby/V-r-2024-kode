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
    DailyMenu menu;
    menu.adjective = adjective;
    menu.mainDish = mainDish;
    menu.sideDish = sideDish;
    menu.price = adjectivePriceModifiers.at(adjective) * (mainDishPrices.at(mainDish) + sideDishPrices.at(sideDish));

    return menu;
    // END: 1a
}
ostream& operator<<(ostream& os, DailyMenu d) {

    // BEGIN: 1b
    os << "Dish: " << d.adjective << " " << d.mainDish << " with " << d.sideDish << endl
       << "Price: " << d.price << endl;
       
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
    string adj, main, side;

    random_device rd;
    default_random_engine seed(rd());
    uniform_int_distribution dist(0, mapSize - 1);

    adj = getDishFromNumber(adjectivePriceModifiers, dist(seed));
    main = getDishFromNumber(mainDishPrices, dist(seed));
    side = getDishFromNumber(sideDishPrices, dist(seed));

    DailyMenu menu = createDailyMenu(adj, main, side);
    return menu;
    // END: 2b
}