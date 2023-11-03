//
// Created by Will&Carm on 15/08/2023.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int lineNumber = 0;

    ifstream inFile;
    ofstream outFile;

    inFile.open("Words");
    outFile.open("output.txt");

    if (!inFile.is_open()) {
        cout << "Words could not be opened" << endl;
        return 1;
    }
    else if (inFile.bad()) {
        cout << "Words has hardware issues" << endl;
        return 1;
    }
    else if (inFile.fail()) {
        cout << "Words data is invalid" << endl;
        return 1;
    }
    // validation to read the file

    std::string wordIWant;

    while (std::getline(inFile, wordIWant)) {
        lineNumber++;
        cout << lineNumber << ": " << wordIWant << endl;
        // printing the file contents out on the terminal

        outFile << lineNumber << ": " << wordIWant << endl;
        // writing the new contents to file output.txt
    }

    inFile.close();
    outFile.close();

    return 0;
}