//
// Created by Will&Carm on 8/08/2023.
//
#include <iostream>

using namespace std;

void inputFunctionType(int &wood, int &concrete, int &brick) {
    string choice;
    std::cout << "This is to chose material type for retaining wall." << endl;
    std::cout << "Can chose either wood(w) or concrete(c) or brick(b). " << endl;

    while (true) {
        // while loop to get the right input if not repeats till true
        std::cout << "Input type of material desired: " << endl;
        cin >> choice;

        if (choice == "w" || choice == "W") {
            wood = 75;
            std::cout << "you have chosen wood." << endl;
            break;
        } // end first if
        else if (choice == "c" || choice == "C") {
            concrete = 150;
            std::cout << "you have chosen concrete." << endl;
            break;
        } // end second if
        else if (choice == "b" || choice == "B") {
            brick = 175;
            std::cout << "you have chosen brick" << endl;
            break;
        } // end third if
        else {
            std::cout << "you have inputted the wrong option" << endl << "please input again!" << endl;
        } // end else statement
    } // end while loop
} // end function

void inputFunctionSize(int &width, int &height, int &depth) {
    std::cout << "Please input the width of the wall." << endl;
    std::cin >> width;

    std::cout << "Please input the height of the wall." << endl;
    std::cin >> height;

    std::cout << "Please input the depth of the wall" << endl;
    std::cin >> depth;
    // gets the details of the walls size
} // end method

int functionCalc(int wood, int concrete, int brick, int width, int height, int depth) {

    return (wood + concrete + brick) * (width * height * depth) + 200;
    // does the math
} // end method

void displayCost(int cost) {

    std::cout << endl << "Total cost of the call will be: $" << cost << "." << endl;
}

