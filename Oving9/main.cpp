#include "Meeting.h"
#include <iostream>

int main() {

    Person Audun("Audun", "Audun.ystgaard@gmail.com", 0);

    std::cout << Audun <<std::endl;

    Campus myCampus = Campus::Trondheim;

    return 0;
}
