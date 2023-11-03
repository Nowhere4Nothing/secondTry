//
// Created by Will&Carm on 9/10/2023.
//

#import <iostream>
#import <string>

using namespace std;

template <typename T>
T funcExp (T list[], int size) {
    int j;
    T x = list[0];
    T y = list[size - 1];
    for (j = 1; j < (size - 1) /2; j++) {
        if (x < list[j]) {
            x = list[j];
        }
        if (y > list[size - 1 - j]) {
            y = list[size - 1 -j];
        }
    }
    return (x+y);
}

int main() {
    int list [8] = {1,2,3,4,5,6,7,8};
    string strList[] = {"one", "fish", "two", "fish", "red", "fish", "blue", "fish"};

    cout << funcExp(list, 8) << " :: " << funcExp(strList, 8) << endl;
}