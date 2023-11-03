//
// Created by Will on 8/08/2023.
//
#include <iostream>

using namespace std;

void calculation(int mCalc, int nCalc) {

    for (int count = 1; count < nCalc; count++) {

        std::cout << count * mCalc << ", ";
        // get the numbers except for the last
    } //  end for loop

    std::cout << nCalc * mCalc << ".";
    // get the last number
} // end method

int input(int &m, int &n) {
    int nLow;

    cout << "Enter the first integer : ";
    cin >> m;

    while (true) {
        cout << "Enter the second integer : ";
        cin >> nLow;
        if (nLow > 1) {
            n = nLow;
            return n;
        } // end if statement
        else {
            cout << "sorry please input number again!" << endl;
            // while loop to ask for input greater than 1, if not then repeat
        } // end else
    } // end while loop
} // end method

int main() {
    int m, n;

    input(m, n);

    calculation(m, n);

    return 0;
} // end main





