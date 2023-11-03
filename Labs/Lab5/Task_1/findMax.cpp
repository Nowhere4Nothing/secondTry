// finMax.cpp
#include<iostream>
using namespace std;

template<typename T>
T& findMax(T &a, T &b){
    return (a>b) ? a : b;
}

int main(){
    int intA = 20, intB = 50;
    char charA = 'a', charB = 'b';
    float floatA = 3.12f, floatB = 3.13f;
    double doubleA = 1.11, doubleB = 2.22;

    cout << findMax<int>(intA, intB)<<endl;
    cout << findMax<char>(charA, charB)<<endl;
    cout << findMax<float>(floatA, floatB) << endl;
    cout << findMax(doubleA, doubleB)<<endl;
    return 0;
}