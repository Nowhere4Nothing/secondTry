//
// Created by Will&Carm on 6/09/2023.
//



#ifndef SECONDTRY_LIBRARY_H
#define SECONDTRY_LIBRARY_H

#endif //SECONDTRY_LIBRARY_H

#include <iostream>
#include <utility>

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

    Money(string mn, double du, double er) :
            moneyName  (std::move(mn)),
            dollarUnits (du),
            exchangeRate (er)
    {};

    [[nodiscard]] const string &getMoneyName() const {
        return moneyName;
    };

    void displayMoney(){
        cout << "Currency:  " << moneyName << endl;
        cout << "Amount of money: " << dollarUnits << endl;
        cout << "Current exchange rate with US dollar: " << exchangeRate << endl << endl;
    };

    ~Money();
};

class City {
private:
    string cityName;
    string countryLocatedIn;
    string latitude;
    string longitude;

public:
    Money myMoney;

    City() {
        cityName = " ";
        countryLocatedIn = " ";
        latitude = " ";
        longitude = " ";
    };

    City(string cn, string cli, string lat, string l, string mn, double du, double er) :
            cityName(std::move(cn)), countryLocatedIn(std::move(cli)), latitude(std::move(lat)),longitude(std::move(l)),
            myMoney(std::move(mn), du, er) {};

    [[nodiscard]] const string &getCountryLocatedIn() const {
        return countryLocatedIn;
    };

    void displayCity() {
        cout << "City Name: " << cityName << endl;
        cout << "City located in: " << countryLocatedIn << endl;
        cout << "Latitude: " << latitude << " and Longitude: " << longitude << endl << endl;
    }
    ~City();
};

void friendFunction(const Money&, const City&, const City&);
void checkAssociation(const Money&, const City&);