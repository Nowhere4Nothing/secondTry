//
// Created by Will&Carm on 9/10/2023.
//
#include <iostream>
#include <string>
#include <utility>

using namespace std;

template <typename T>
class Hold {
private:
    T data;
public:
    explicit Hold(T variable) : data (std::move(variable)) {}

    [[nodiscard]] T doubleStuff() const {
        return data + data;
    }
};

int main() {
    Hold<int> holdTheInt(15);
    Hold<float> holdTheFloat (12.654);
    Hold<char> holdTheChar('h');
    Hold<string> holdTheString("Metal for life");

    cout << "Doubled int: " << holdTheInt.doubleStuff() << endl;
    cout << "Doubled float: " << holdTheFloat.doubleStuff() << endl;
    cout << "Doubled char: " << holdTheChar.doubleStuff() << endl;
    cout << "Doubled string: " << holdTheString.doubleStuff() << endl;
}