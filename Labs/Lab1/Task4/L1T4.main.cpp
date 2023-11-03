//
// Created by Will&Carm on 8/08/2023.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double r, v, s;

    cout << "input the radius" << endl;
    cin >> r;

    v = 2 * M_PI * r;

    s = M_PI * pow(r,2);

    cout << "the area of the circle is: " << endl;
    cout << s << endl;

    cout << "the circumference if this circle is:" << endl;
    cout << v << endl;

    return 0;
}