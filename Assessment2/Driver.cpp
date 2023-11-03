//
// Created by Will on 15/09/2023.
//
#include <iostream>
#include "header.h"

using namespace std;

int main(int argle, char* argv[]) {

    if ( argle != 3 )
    {
        cerr << "can only enter 2 ints. First being between 1-10, and the second being between 1-30!" << endl;
        cerr << "First is amount of electorates. Second is the amount of campaign days!" << endl;
        return 1;
    }

    int n = stoi(argv[1]);
    int m = stoi(argv[2]);

    if (n < 1 || n > 10 ) {
        cerr << "first int must be between 1 - 10!! " << endl;
        return 1;
    }

    if (m < 1 || m > 30) {
        cerr << "second int must be between 1 and 30!!" << endl;
        return 1;
    }

//int main() {
//    int n = 2;
//    int m = 15;

    cout << "---------------------------Program Initiated -----------------------------" << endl << endl;

    Election ee = Election();

    ee.generateIssues();
    ee.generatePoliticalParties();
    ee.generatePoliticalLeader();
    int numCan = ee.generatePoliticalCandidate(n);
    ee.generateCampaignTeam();
    ee.generateElectorate(n);
    ee.displayAllGeneratedInformation(numCan, n);
    ee.generateCampaignEvents(m, n);
    ee.decideWinner(m, n);

    cout << endl << "---------------------------Program Terminated -----------------------------" << endl;

    ee.deletePoliticalParties();
    ee.deleteCandidates(numCan);
    ee.deleteTeam();
    ee.deleteIssues();
    ee.deleteElectoralDivions();

    /*
     This program will run by calling these methods from top to bottom in that order.
     the variables n and m will be provided by the user when running the file from the argument line
     The final methods delete the array of pointers and calls the de-constructor.
     Some methods may have methods inside them. All the methods and their details are in the file header.cpp
     This method uses the file header.h to store objects, see the #include
     */

    return 0;
}