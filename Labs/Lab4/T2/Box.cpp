//
// Created by Will on 14/09/2023.
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>


using namespace std;

class SmallBox {
    int id;
    int length;
    int height;
    int volume;
    string material;


public:
    SmallBox() : id(), length(), height(), volume(), material() {}
    SmallBox(int i, int w, int h, int v, string m) : id(i), length(w), height(h), volume(v), material(std::move(m)) {}

    [[nodiscard]] int getVolume() const  {
        return volume;
    }

    [[nodiscard]] int getId() const {
        return id;
    }

    void displaySmallInsideBig() const {
        cout << "SmallBox: " << endl;
        cout << "Box id: " << id << endl;
        cout << "Length: " << length << endl;
        cout << "Height: " << height << endl;
        cout << "Volume: " << volume << endl;
        cout << "Material made of: " << material << endl << endl;
    }

    ~SmallBox();
};

class BigBox {
private:
    int id;
    int length;
    int height;
    int volume;
    string material;
    vector<SmallBox*> smallBoxes;

    public:
    BigBox() : id(), length(), height(), volume(), material() {}
    BigBox(int i, int w, int h, int v, string m) : id(i), length(w), height(h), volume(v), material(std::move(m)) {}

    bool addSmallBox(SmallBox *small) {
        volume -= small->getVolume();
        if (volume <= small->getVolume()) {
            cout << "BigBox is already full as Big Box '" << id << "s' volume '" << volume <<"' is smaller than Small Box id '"  <<
            small->getId() << "s' volume "<< small->getVolume() << endl << endl;
            return false;
        }

        smallBoxes.push_back(small);

        cout << "SmallBox " << small->getId() << " added to BigBox " << id << "." << endl;
        return true;
    }

    void displayBox() {
        cout << "BigBox '" << id << "' contains the following Small boxes: " << endl;

        for (const SmallBox* smallBoxInside : smallBoxes) {
            smallBoxInside->displaySmallInsideBig();
        }
    }

    void displayBig() {
        cout << "Big box: " << endl;
        cout << "Box id: " << id << endl;
        cout << "Length: " << length << endl;
        cout << "Height: " << height << endl;
        cout << "Volume: " << volume << endl;
        cout << "Material made of: " << material << endl << endl;
    }

    ~BigBox();
};

int main() {
    cout << "---------------------------Program initiated -----------------------------" << endl;

    int height, length, volume, id;
    string exit, material;

        cout << "Id of the box: ";
        cin >> id;
        cout << "Add the dimensions of the big box: " << endl;
        cout << "Height: ";
        cin >> height;
        cout << "Length: ";
        cin >> length;
        volume = height * length;
        getline(cin, material);
        BigBox big (id,height,length, volume, material);
        big.displayBig();

        while (true) {
        cout << "Add the dimensions of the small box: " << endl;
        cout << "Height: ";
        cin >> height;
        cout << "Length: ";
        cin >> length;
        volume = height * length;
        getline(cin, material);
        SmallBox small (1,height,length, volume, material);

        big.addSmallBox(&small);
        big.displayBox();

        cout << "Type 'EXIT' or 'exit' to exit loop!" << endl;
        cin >> exit;
        if (exit == "exit" || exit == "EXIT") {
            cout << "Loop exited" << endl;
            break;
        }
    }

    cout << "---------------------------Program Terminated -----------------------------" << endl;
}

BigBox::~BigBox() {
    cout << "BigBox has been deleted" << endl;
}

SmallBox::~SmallBox() {
    cout << "SmallBox has been deleted" << endl;
}

// template