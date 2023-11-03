
#include <iostream>
using namespace std;

/*
 * This code is calculating the fibonacci sequence using recursion, when you input a number it will tell you what the fibonacci value is
 * It is not very efficient as it repeats a lot of numbers
 * It goes by taking the input, then getting the two variables t_zero and T_one. If x is equal to 0 then it returns t_zero, if not it returns T_one
 * if it is greater than 1 it calculates the number for x using recursion then returns y
 */
template <typename T>
T fib( T x ){
	T t_zero(0);
	T t_one(1);
	if ( x <= 0)
		return t_zero;
	if ( x <= 1)
		return t_one;
	T y = fib (x-1) + fib (x-2);

    cout <<"Y = " << y << " " << endl;


    return y;
}

int main()

{

	unsigned int x;
	x = 9;

    double y;
    y = 9.5;

//	cout << fib(x) << endl;

cout << fib(y) << endl;

	return 0;
}
