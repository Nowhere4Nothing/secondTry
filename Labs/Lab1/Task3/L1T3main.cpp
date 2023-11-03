//
// Created by Will&Carm on 8/08/2023.
//
#include <iostream>
#include "header.L1T3.h"

using namespace std;

int main () {

    int wood = 0, concrete = 0, brick = 0;
    int width, height, depth, cost;

    inputFunctionType(wood, concrete, brick);
    // calls first function

    inputFunctionSize(width, height, depth);
    // calls second function

    cost = functionCalc(wood, concrete, brick, width, height, depth);
    // calculates the cost

    displayCost(cost);

    return 0;
}