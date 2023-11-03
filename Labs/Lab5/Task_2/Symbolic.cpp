//
// Created by Will&Carm on 5/10/2023.
//
#include <iostream>
#include <string>

using namespace std;

template<typename T>
        void displayTheSymbolic(const T& value, int n, char symbol) {
            int i,j;
            for (i = 0; i < n; i++) {
                cout << symbol;
            }

            cout << " " << value << " ";

            for (j =0; j <n; j++) {
                cout << symbol;
            }
            cout << endl;
        }


int main() {
int firstNumber = 47;
double secondNumber = 39.25;
string thirdLine = "Bob";

    displayTheSymbolic(firstNumber, 3, '*');
    displayTheSymbolic(secondNumber, 3, '0');
    displayTheSymbolic(thirdLine, 4, 'a');
}
