#pragma once
#include "std_lib_facilities.h"

struct Food {
    string name;
    double price;
    string where;
};

Food operator<(set<Food> food);