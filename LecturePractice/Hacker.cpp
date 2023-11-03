//
// Created by Will&Carm on 1/11/2023.
//
#include <iostream>
#include <string>

class Hacker {
protected:
    std::string name;
    int id;

public:
    Hacker() : name(), id() {}
    Hacker(std::string n, int i) : name(std::move(n)), id(i) {}
    void scan();
    virtual void display();
    void setHackerName(std::string n);
    virtual ~Hacker();
};

class Gray_Hacker : public Hacker {
protected:
    std::string target;

public:
    Gray_Hacker(): Hacker(), target() {}
    Gray_Hacker(std::string n, int i, std::string t) : Hacker(std::move(n), i), target(std::move(t)) {}
    void purpose();
    void display() override;
    ~Gray_Hacker() override;
};

class Child_hacker : public Gray_Hacker {
private:
    std::string language;

public:
    Child_hacker(): Gray_Hacker(), language() {}
    Child_hacker(std::string n, int i, std::string t, std::string l):
    Gray_Hacker(std::move(n), i, std::move(t)), language(std::move(l)) {}
    void display() override;
    void whoAmI();
};

using namespace std;

int main() {

    Gray_Hacker grayHacker ("John", 125, "Walmart");

    grayHacker.display();
    grayHacker.scan();
    grayHacker.purpose();

    Hacker *hacker = new Gray_Hacker("Max", 222, "Coles");
    hacker->scan();
    hacker->display();
    delete hacker;

    Child_hacker child("Bob", 999, "Target", "C++, java");
    child.display();
    child.whoAmI();

    return 0;
}

void Hacker::scan() {
    cout << "Scanning for enemies!!" << endl;
}

void Hacker::display() {
        cout << "Name: " << name << endl;
        cout << "id: " << id << endl;
}

void Hacker::setHackerName(string n) {
    name = n;
}

Hacker::~Hacker() {
    cout << "Hacker has been destroyed!" << endl << endl;
}
void Gray_Hacker::purpose() {
    cout << "--For your words--" << endl << endl;
}

void Gray_Hacker::display() {
    cout << "Name: " << name << endl;
    cout << "id: " << id << endl;
    cout << "Target: " << target <<endl;
}

Gray_Hacker::~Gray_Hacker() {
cout << "Gray hacker has been destroyed" << endl;
}

void Child_hacker::display() {
    cout << "Name: " << name << endl;
    cout << "id: " << id << endl;
    cout << "Target: " << target <<endl;
    cout << "Languages learnt: " << language << endl;
}

void Child_hacker::whoAmI() {
cout << "I am a child of Gray Hacker" << endl << endl;
}
