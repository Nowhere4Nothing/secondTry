//
// Created by Will&Carm on 6/09/2023.
//

#ifndef SECONDTRY_LIBRARY_H
#define SECONDTRY_LIBRARY_H

#endif //SECONDTRY_LIBRARY_H

#include <iostream>

using namespace std;

class Money {
private:
    string moneyName;
    double dollarUnits;
    double exchangeRate;

public:
    Money() {
        moneyName = " ";
        dollarUnits = 0;
        exchangeRate = 0;
    };

    Money(string mn, double du, double er) {
        moneyName = mn;
        dollarUnits = du;
        exchangeRate = er;
    }

    [[nodiscard]] const string &getMoneyName() const {
        return moneyName;
    }
};

class City {
private:
    string cityName;
    string countryLocatedIn;
    string latitude;
    string longitude;

public:
    City() {
        cityName = " ";
        countryLocatedIn = " ";
        latitude = " ";
        longitude = " ";
    };

    City(string cn, string cli, string lat, string l) {
        cityName = std::move(cn);
        countryLocatedIn = std::move(cli);
        latitude = std::move(lat);
        longitude = std::move(l);
    };

    [[nodiscard]] const string &getCountryLocatedIn() const {
        return countryLocatedIn;
    }
};

void friendFunction(const Money&, const City&, const City&);
void checkAssociation(const Money&, const City&);