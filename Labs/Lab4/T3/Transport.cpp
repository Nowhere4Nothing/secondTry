//
// Created by Will on 12/09/2023.
//
#include <string>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Transport {
protected:
     string name;

    public:
    Transport() : name() {}
    explicit Transport(string n) : name(std::move(n)) {}

    virtual void displayTransport() const =0;

//        void displayTransport() {
//
//    }
    ~Transport();
};

Transport::~Transport() {
cout << "Transport '" << name << "' has been deleted!" << endl;
}

class SeaTransport : public Transport {
protected:
    string typeUsedOn;


public:
    SeaTransport() : Transport(), typeUsedOn() {};
    SeaTransport(string tName, string sType) :
    Transport(std::move(tName)), typeUsedOn(std::move(sType)) {};

    void displayTransport() const override {
        cout << "Type of transport: " << name << endl;
        cout << "Where is it typically used: " << typeUsedOn << endl;
    }
};

class cruiseShip : public SeaTransport {
    string shipName;
    int weight;
    int length;
    string captainName;

public:
    cruiseShip() : SeaTransport(), shipName(), weight(), length(), captainName() {};

    cruiseShip(string tName, string tuo, string sName, int sWeight, int sLength, string cName) :
            SeaTransport(std::move(tName), std::move(tuo)), shipName(std::move(sName)), weight(sWeight),
            length(sLength),
            captainName(std::move(cName)) {};

    void displayTransport() const override {
        cout << "Type of transport: " << name << endl;
        cout << "Where is it typically used: " << typeUsedOn << endl;
        cout << "Name of the ship: " << shipName << endl;
        cout << "Weight: " << weight << " tons" << endl;
        cout << "Length: " << length << " metres " << endl;
        cout << "Captains name: " << captainName << endl << endl;
    }
};

class Canoe : public SeaTransport {
private:
    int weight;
    int length;
    int maxPeople;
    string colour;

public:
    Canoe() : SeaTransport(), weight(), length(), maxPeople(), colour() {}

    Canoe(string tName, string sUsedOn, int w, int l, int mPeople, string c) :
    SeaTransport(std::move(tName), std::move(sUsedOn)), weight(w), length(l), maxPeople(mPeople), colour(std::move(c)) {}

    void displayTransport() const override {
        cout << "Type of transport: " << name << endl;
        cout << "Where is it typically used: " << typeUsedOn << endl;
        cout << "Weight: " << weight << " kilos" << endl;
        cout << "Length: " << length << " metres " << endl;
        cout << "max people: " << maxPeople << endl << endl;
    }
};

class LandTransport : public Transport {
protected:
    string typeUsedOn;

public:
    LandTransport() : Transport(), typeUsedOn() {}
    LandTransport(string tName, string lUsedOn) : Transport(std::move(tName)), typeUsedOn(std::move(lUsedOn)) {}

    void displayTransport() const override {
        cout << "Type of transport: " << name << endl;
        cout << "Where is it typically used: " << typeUsedOn << endl;
    }

};

class Car : public LandTransport {
private:
    string model;
    string colour;
    int maxPeople;
    int maxWheels;
    int weight;
    int length;

public:
    Car() : LandTransport(), model(), colour(), maxPeople(), maxWheels(), weight(), length() {}
    Car(string tName, string lUsedOn, string m, string c, int mP, int mW, int w, int l) :
    LandTransport(std::move(tName), std::move(lUsedOn)), model(std::move(m)), colour(std::move(c)), maxPeople(mP), maxWheels(mW),
    weight(w), length(l) {}

    void displayTransport() const override {
        cout << "Type of transport: " << name << endl;
        cout << "Where is it typically used: " << typeUsedOn << endl;
        cout << "Model of car: " << model << endl;
        cout << "Colour: " << colour << endl;
        cout << "Weight: " << weight << " kilos" << endl;
        cout << "Length: " << length << " metres " << endl;
        cout << "Max wheels: " << maxWheels << endl;
        cout << "max people: " << maxPeople << endl << endl;
    }
};

class AirTransport : public Transport {
protected:
    string typeUsedOn;
    int amountOfWings;

public:
    AirTransport() : Transport(), typeUsedOn(), amountOfWings() {}
    AirTransport(string tName, string lUsedOn, int amountOfWings) : Transport(std::move(tName)), typeUsedOn(std::move(lUsedOn)),
    amountOfWings(amountOfWings) {}

    void displayTransport() const override {
        cout << "Type of transport: " << name << endl;
        cout << "Where is it typically used: " << typeUsedOn << endl;
        cout << "Amount of wings: " << amountOfWings << endl << endl;
    }
};

class Hovercraft : public LandTransport, AirTransport {
private:
    string sizeFan;
    string colour;
    int maxPeople;
    int weight;
    int length;

public:
    Hovercraft() : LandTransport(), AirTransport(), sizeFan(), colour(), maxPeople(), weight(), length() {}
    Hovercraft(const string& tName, const string& typeUsedOn, int amountOfWings, string sF, string c, int mP, int w, int l) :
    LandTransport(tName, typeUsedOn), AirTransport(tName, typeUsedOn, amountOfWings),
    sizeFan(std::move(sF)), colour(std::move(c)), maxPeople(mP), weight(w), length(l) {}

    void displayTransport() const override {
        cout << "Type of transport: " << LandTransport::name << endl;
        cout << "Where is it typically used: " << LandTransport::typeUsedOn << endl;
        cout << "Size of the fan: " << sizeFan << endl;
        cout << "Colour: " << colour << endl;
        cout << "Weight: " << weight << " kilos" << endl;
        cout << "Length: " << length << " metres " << endl;
        cout << "max people: " << maxPeople << endl << endl;
    }
};

int main() {
    cout << "---------------------------Program initiated -----------------------------" << endl;

    cout << "Display using an abstract method!" << endl << endl;
    cruiseShip ship("Ship", "sea", "Diamond of the sea", 5000, 400, "John");
    ship.displayTransport();

    Canoe canoe("Canoe", "water", 40, 4, 2, "red");
    canoe.displayTransport();

    Car car ("Car", "Land", "Toyota", "White", 5, 4,2,2);
    car.displayTransport();

    Hovercraft hovercraft ("Hovercraft", "Land and water", 0, "3 metres", "Red", 5,5,3);
    hovercraft.displayTransport();

    cout << endl << "Display Using a vector!" << endl << endl;

    vector<Transport*> transport;
    transport.push_back(&ship);
    transport.push_back(&canoe);
    transport.push_back(&car);
    transport.push_back(static_cast<LandTransport*>(&hovercraft));

    for (const Transport* transPtr : transport) {
        transPtr->displayTransport();
        cout << endl;
    }

    cout << "---------------------------Program terminated -----------------------------" << endl;

    return 0;
}
