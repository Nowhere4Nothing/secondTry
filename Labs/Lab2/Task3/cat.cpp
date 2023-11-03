//
// Created by Will on 15/08/2023.
//
#include <iostream>

using namespace std;

struct Cat {
    string name;
    string type;
    int age;
    double cost;

    void setCat(string, string, int);

    void calculatePrice();

    void showCat();
    //creating the structure and calling the methods
};

const static double insurance = 99.9;

void Cat::setCat(std::string catName, std::string catType, int catAge) {
    name = catName;
    type = catType;
    age = catAge;
    // method that sets the value entered for the object
}

void Cat::calculatePrice( ) {
   double catCost = age * 1.5 + insurance;
    cost = catCost;
    // method used to calculate the price of the object and insurance
}

void Cat::showCat() {
    cout << name << " is a " << type << ", " << endl;
    cout << "Its age is " << age << "," << endl;
    cout << "Insurance fee is: $" << insurance << "," << endl;
    cout << "Owing cost is: $" << cost << endl;
    //displaying the values of the object
}

int main() {
    Cat myCat;
    myCat.setCat("Tiger", "British Short hair", 1);
    myCat.calculatePrice();
    myCat.showCat();
}

