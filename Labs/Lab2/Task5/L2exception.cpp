//
// Created by Will on 15/08/2023.
//
#include <exception>
#include <iostream>

using namespace std;

class MyException : public std::exception {
public:
    // this function will be called to output a string when an exception arrises

    const char * what() const throw() {
        return "Attempted to divide by zero! \n";
        // what the exception will display
    } // end throw
};

int main() {

    int x, y, total;

    while (true) {
        // while loop to keep program going until the exception is thrown

        std::cout << "Enter the numbers of x and y" << endl;
        std::cout << "x:";
        std::cin >> x;
        std::cout << "y:";
        std::cin >> y;

        if (x == 0 || y == 0) {
            try {
                throw MyException();
                // try to throw the exception when 0 is entered
            } // end try
            catch (MyException &e) {
                std::cout << e.what() << std::endl;
                break;
                // displaying the exception in the Myexception class
                // then break the while loop
            } // end catch
        } // end if
        else {
            total = x + y;
            std::cout << "x/y: \t" << total << std::endl << std::endl;
        } // end else
    } // end else
    return 0;
} // end main