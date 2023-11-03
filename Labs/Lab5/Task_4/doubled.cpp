//
// Created by Will&Carm on 9/10/2023.
//

#import <iostream>
#import <string>

using namespace std;

// do could be in the exam

template <typename T>
T doubleStuff(T x) {

    return x + x;
}

int main() {
    int x  = 5;
    string y = "Double me";
    float c = 5.6;
    char p = '!';

    doubleStuff(x);
    cout << doubleStuff(x) << endl;

    doubleStuff(y);
    cout << doubleStuff(y) << endl;

    doubleStuff(c);
    cout << doubleStuff(c) << endl;

    doubleStuff(p);
    cout << doubleStuff(p) << endl;

}