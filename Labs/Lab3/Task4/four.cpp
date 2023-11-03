//
// Created by Will&Carm on 6/09/2023.
//


#include <iostream>
#include "library.h"

using namespace std;

int main() {

    Money dollar("Australia", 15.40, 0.64);
    City Sydney ("Sydney", "Australia", "33°52′11.44 South", "151°12′29.83 East");
    City London ("London","England","51.5072° North","0.1276° West");
    friendFunction(dollar, Sydney, London);


    return 0;
}