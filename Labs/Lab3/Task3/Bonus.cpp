//
// Created by Will&Carm on 4/09/2023.
//

#include <iostream>
#include <utility>

using namespace std;

void static displayTable();

const static int number_range = 3;
const static int number_Classes = 3;
// using a global const variable, so you do not need to change the rows and the columns more than once. they are always set at 3

const static string amountOfSales[number_range][1] = {
        // read as 3 rows and one column
        {"0 - 20"},
        {"21 - 50"},
        {"51+"}
};

const static double classes[number_Classes][number_range] = {
        // read as 3 rows and 3 columns
        {0.03,  0.05,  0.075},
        {0.02,  0.035, 0.055},
        {0.005, 0.015, 0.04}
        // stored in a 2d array like the matrix lab
};


class Staff {
private:
    int staffNumber{};
    string firstName;
    string lastName;
    double baseSalary{};
    int salesMade{};
    double bonus{};
    char staffGrade{};

public:
    void setFields(int, string, string, double, int, char);

    void calculate();

    void display();
};

void Staff::setFields(int sn, string fn, string ln, double bs, int sm, char sg) {
    staffNumber = sn;
    firstName = std::move(fn);
    lastName = std::move(ln);
    baseSalary = bs;
    salesMade = sm;
    staffGrade = sg;
}

void Staff::calculate() {


    if ((staffGrade == 'A') && (salesMade < 20)) {
        double percent = classes[0][0];
        bonus = baseSalary * salesMade * percent;
    }
    else if ((staffGrade == 'A') && (salesMade > 20 && salesMade <= 50)) {
        double percent = classes[0][1];
        bonus = baseSalary * salesMade * percent;
    }
    else if ((staffGrade == 'A') && (salesMade > 51)) {
        double percent = classes[0][2];
        bonus = baseSalary * salesMade * percent;
    }

    if ((staffGrade == 'B' || staffGrade == 'b') && (salesMade < 20)) {
        double percent = classes[1][0];
        bonus = baseSalary * salesMade * percent;
    }
    else if ((staffGrade == 'B' || staffGrade == 'b') && (salesMade > 20 && salesMade <= 50)) {
        double percent = classes[1][1];
        bonus = baseSalary * salesMade * percent;
    }
    else if ((staffGrade == 'B' || staffGrade == 'b') && (salesMade > 51)) {
        double percent = classes[1][2];
        bonus =  baseSalary * salesMade * percent;
    }

    if ((staffGrade == 'C' || staffGrade == 'c') && (salesMade < 20)) {
        double percent = classes[2][0];
        bonus = baseSalary * salesMade * percent;
    }
    else if ((staffGrade == 'C' || staffGrade == 'c') && (salesMade > 20 && salesMade <= 50)) {
        double percent = classes[2][1];
        bonus = baseSalary * salesMade * percent;
    }
    else if ((staffGrade == 'C' || staffGrade == 'c') && (salesMade > 51)) {
        double percent = classes[2][2];
        bonus = baseSalary * salesMade * percent;
    }
}

int main() {

    displayTable();
    // displaying the table

    Staff staff1;
    staff1.setFields(1001, "Thomas", "the Tank Engine", 10000.00, 21, 'A');
    staff1.calculate();
    staff1.display();

    Staff staff2;
    staff2.setFields(1002, "Bob", "the Builder", 5000.00, 56, 'C');
    staff2.calculate();
    staff2.display();
    // creating the objects and setting the fields then calculating it and displaying it

    return 0;
}

void static displayTable() {

    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Sales \t \t Class A \t Class B \t Class C" << endl;
    for (int i = 0; i < number_range; i++) {

        cout << amountOfSales[i][0] << "\t";
        // reading down the first column

        for (int j = 0; j < number_Classes; j++) {
            // this nested for loop goes down the columns of array classes and prints them out
            cout << " \t " << classes[i][j] << "\t";
            // this prints out the rates for the classes and uses a tab to make the table neat
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl << endl;
}

void Staff::display() {

    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Grade: " << staffGrade << "\t \t" << "Staff Number: #" << staffNumber << endl;
    cout << "Salary: " << baseSalary << "\t \t" << "Sales Made: " << salesMade << endl;
    cout << "Bonus: " << bonus << endl << endl;
    // displaying the output
}