//
// Created by Will&Carm on 6/09/2023.
//

#include "library.h"
#include <iostream>

using namespace std;



void friendFunction(const Money& ausDollar,const City& sydney, const City& london) {

    checkAssociation(ausDollar, sydney);
    checkAssociation(ausDollar, london);

}

void checkAssociation(const Money& currency, const City& location){
    if (currency.getMoneyName() == location.getCountryLocatedIn()) {
        cout << "The currency of " << currency.getMoneyName() << " is associated with "
        << location.getCountryLocatedIn() << "!!" << endl << endl;
    }
    else {
        cout << "The currency of " << currency.getMoneyName() << " is not associated with "
             << location.getCountryLocatedIn() << "!!" << endl << endl;
    }
}

City::~City() {
cout << "City '" << cityName << "' has been destroyed!!" << endl;
}

Money::~Money() {
cout << "Money '" << moneyName << "' has been destroyed!!" << endl;
}
