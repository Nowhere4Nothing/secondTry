//
// Created by Will on 16/10/2023.
//

#include "collect.h"
#include <iostream>
#include <random>
#include <map>

using namespace std;

char randomKnapItem();

class Knapsack {
private:
    int knapsackCapacity;
    int knapsackEmpty;
    int knapDuro;
    int totalDuro;
    string addObjectName;

    map<char, pair<pair<char, int >, int>> fillingTheKnapsack;
    // using a map to store and sort it alphabetically

public:
    Knapsack() : knapsackCapacity(), knapsackEmpty(), knapDuro(), totalDuro(), addObjectName() {}

    Knapsack(int ks, int kd) : knapsackCapacity(ks), knapsackEmpty(1), knapDuro(kd), totalDuro(0), addObjectName("") {}

    void setDuro() {
        totalDuro += 1;
        // used to set the durability up if it reaches max it closes
    }

    void setKnapEmpty() {
        knapsackEmpty = 0;
        // every time the program hits an R this resets the knapsack
    }

    void setKnapMore(int size) {
        knapsackEmpty += size;
        // every time the program gets any class other than  R || S it will add the sizeof to the knapsack
    }

    template<typename J>
        void setAddObjectName (const J aon) {
            addObjectName += aon;
            // this is only used for the summary line 3 where the classes are displayed
    };

    void setObjectNameToEmpty() {
        addObjectName = "";
        // when the class R is selected this resets line 3 where the classes are displayed
    }

    template<typename T>
    int doMath( T &&objectTransferred, int k) {
        int sizes = sizeof(objectTransferred);

        if (knapsackEmpty + sizes >= knapsackCapacity) {
            // will only trigger if the next object is over the given knapsack size at the start
            cout << "Condition 1 is triggered when the size of the next object is too large: "
                 << sizeof(objectTransferred) << endl;
            k = 1;
            displaySummary();
            return k;
            // writes to the terminal and flips the kill switch to 1
        }
        else if ((objectTransferred.getName() != 'R') && (objectTransferred.getName() != 'S')) {
            // only runs if the classes are not R or S


            setKnapMore(sizes);

            setDisplayResult(objectTransferred.getName(), sizes);
            // adds the size of to the variable size and then adds the size and name to the vector
        } // end else

        if (objectTransferred.getName() == 'R') {
            setDuro();
            // adding one more to the durability
            if (knapDuro != totalDuro) {
                cout << "Condition 2: Attempt to add an R object which triggers a reset. The number of resets: " <<
                     totalDuro << "/" << knapDuro << endl;
                displaySummary();
                setObjectNameToEmpty();
                setKnapEmpty();
                return k;
                // displays to the terminal, displays results, sets the line 3 to "", and the knapsack to 0
                // before returning the kill switch which is still 0
            }
            else {
                cout << "Condition 2: All resets Used: " << totalDuro << "/" << knapDuro << endl;
                displaySummary();
                k = 1;
                return k;
                // only flips when the durability is used up, then it will display the summary and flip the kill switch to 1
            } // end else
        } // end if

        if (objectTransferred.getName() == 'S') {
            cout << "Condition 3: Attempt to add an S object which triggers an early termination";
            k = 1;
            displaySummary();
            return k;
            // only runs if the class is S, this will flip the ill switch to 1 and display the summary
        } // end if
        return k;
    } // end method

    void setDisplayResult(char objectTransferred, int sizes) {
        int count = 1;
        for (auto &knapCheck: fillingTheKnapsack) {
            if (knapCheck.first == objectTransferred) {
                knapCheck.second.first.second = sizes;
                knapCheck.second.second += 1;
                return;
                /*
                 Making the pairs in the map, it will run through the map and if it has an object of the same name
                 it will replace it and add another to the count
                */
            } // end if
        } // end for

        fillingTheKnapsack[objectTransferred] = make_pair(pair(objectTransferred, sizes), count);
        // if there is no object in the map found then it will place a  new one
    }

    void displaySummary() {
        cout << endl << "=====================================================" << endl;
        cout << "Knapsack Size: " << knapsackCapacity << endl;
        cout << "Added object size: " << knapsackEmpty << endl;
        cout << addObjectName << endl;
        cout << "=====================================================" << endl;

            for (auto& display : fillingTheKnapsack) {
               cout <<  display.first << " : " << display.second.first.second << ", " << display.second.second << endl;
            }

            fillingTheKnapsack.clear();
            // this is to display the summary and clear the knapsack

        cout << "=====================================================" << endl;
    }
}; // end class


//int main (int argle, char* argv[]) {
//    if ( argle != 4 )
//    {
//        cerr << "can only enter 3 ints.  All 3 have to be positive integers" << endl;
//        return 1;
//    } // end if
//
//    int size = stoi(argv[1]);
//    int seed = stoi(argv[2]);
//    int durability = stoi(argv[3]);
//
//    if (size < 0 || seed < 0 || durability < 0) {
//        cerr << "All integers that are entered must be a positive number!" << endl;
//        return 1;
//    } // end if
        // used for getting the right amount from the terminal

int main() {
    int size = 800;
    int seed = 273;
    int durability = 3;


    int killSwitch = 0;

    cout << "---------------------------Program Initiated -----------------------------" << endl << endl;

    int count = 0;

//    mt19937 generator(seed);
//    uniform_int_distribution<int> distribution(0, seed);

    Knapsack bigBag(size, durability);

    char closeTheLoop;

    do {
//         closeTheLoop = generate(seed);

        closeTheLoop = randomKnapItem();
//        cout << closeTheLoop << endl;

        if (closeTheLoop == 'A') {
            A a;
            killSwitch = bigBag.doMath(a, killSwitch);
            bigBag.setAddObjectName(a.getName());
        } else if (closeTheLoop == 'B') {
            B b;
            killSwitch = bigBag.doMath(b, killSwitch);
            bigBag.setAddObjectName(b.getName());
        } else if (closeTheLoop == 'C') {
            C c;
            killSwitch = bigBag.doMath(c, killSwitch);
            bigBag.setAddObjectName(c.getName());
        } else if (closeTheLoop == 'D') {
            D d;
            killSwitch = bigBag.doMath(d, killSwitch);
            bigBag.setAddObjectName(d.getName());
        } else if (closeTheLoop == 'E') {
            E e;
            killSwitch = bigBag.doMath(e, killSwitch);
            bigBag.setAddObjectName(e.getName());

        } else if (closeTheLoop == 'F') {
            F f;
            killSwitch = bigBag.doMath(f, killSwitch);
            bigBag.setAddObjectName(f.getName());
        } else if (closeTheLoop == 'G') {
            G g;
            killSwitch = bigBag.doMath(g, killSwitch);
            bigBag.setAddObjectName(g.getName());
        } else if (closeTheLoop == 'R') {
            R r;
            killSwitch = bigBag.doMath(r, killSwitch);
        } else if (closeTheLoop == 'S') {
            S s;
            killSwitch = bigBag.doMath(s, killSwitch);
        }
        /*
         * The if else statement that generates the desired object when the seed decides which one it will be,
        it will send it of the template and bring back the kill switch, could be 0 or 1.
        */

        count++;
    }
    while (!(killSwitch == 1 || count > 150));
    /*
     * writing some conditions to close the loop, when a condition is hit it will flick the kill switch which will break the loop
     * I also added another failsafe condition as I do not want to have a bug that causes an infinite loop so this loop will also
     * only run to 150 max. I hope that is enough
     */

    cout << endl << "---------------------------Program Terminated -----------------------------" << endl;

    return 0;
}

char randomKnapItem() {
    random_device rd;
    default_random_engine randomEngine(rd());

    char classesToPick[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'R', 'S'};

    normal_distribution<double> distribution(4.0, 2.0);

    double indexDouble = distribution(randomEngine);

// Convert the double value to an integer index
    int index = static_cast<int>(round(indexDouble));

// Ensure the index is within the valid range
    if (index < 0) {
        index = 0;
    } else if (index >= sizeof(classesToPick) / sizeof(classesToPick[0])) {
        index = sizeof(classesToPick) / sizeof(classesToPick[0]) - 1;
    }

    return classesToPick[index];
}

