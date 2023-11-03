//
// Created by Will on 9/08/2023.
//

#include <iostream>

using namespace std;

void userInput(int &one, int &two, int &three, int &four, int &five);
void swap (int *ptr1, int *ptr2);

int main() {

    int arr[5] = {};

    int one, two, three, four, five, *ptr1, *ptr2;

    userInput(one, two, three, four, five);

    arr[0] = one;
    arr[1] = two;
    arr[2] = three;
    ptr1 = &arr[3];
    arr[3] = four;
    ptr2 = &arr[4];
    arr[4] = five;

    cout << "Original array: ";
    for (int j = 0; j < 5; j++) {
        if (j < 4) {
            cout << arr[j] << ", ";
        } // end if statement
        else {
            cout << arr[j] << ". " << endl;
        } // end else statement

    } // end for loop

    swap(ptr1, ptr2);

    cout << "After array swap: ";

    for (int i = 0; i < 5; i++) {
        if (i < 4) {
            cout << arr[i] << ", ";
        } // end if statement
        else {
            cout << arr[i] << ". ";
        } // end else statement

    } // end for loop

    return 0;

} // end main

void userInput(int &one, int &two, int &three, int &four, int &five) {

    std::cout << "Please input 5 numbers" << endl;
    std::cout << "Number 1:  ";
    std::cin >> one;

    std::cout << "Number 2:  ";
    std::cin >> two;

    std::cout << "Number 3:  ";
    std::cin >> three;

    std::cout << "Number 4:  ";
    std::cin >> four;

    std::cout << "Number 5:  ";
    std::cin >> five;

} // end method

void swap(int *ptr1, int *ptr2) {
    int ptr3;

    ptr3 = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = ptr3;

} // end method