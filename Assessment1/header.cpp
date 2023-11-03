//
// Created by Will on 18/08/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <random>
#include "header.h"

using namespace std;

const int MAXTASKS = 20;
Tasks tList[MAXTASKS];
int numTasks = 0;

const int MAXWORKERS = 20;
Workers wList[MAXWORKERS];
int numWorkers = 0;
// setting the arrays with a maximum of 20 spots

void Workers::setWorker(int id, string des, int var, int ab) {
    workerID = id;
    wName = std::move(des);
    variability = var;
    ability = ab;
    // setter method to set the workers variables
} // end method

void readInputWorkers() {
    fstream inDataW;
    inDataW.open("Workers.txt");

    if (!inDataW) {
        cout << "Error opening : " << "Workers" << endl;
        // check if opened successfully
        return; // exit with an error code
    } // end if
    else if (inDataW.bad()) {
        cout << "Workers has hardware issues" << endl;
        return;
    } // end else
    else if (inDataW.fail()) {
        cout << "Workers data is invalid" << endl;
        return;
    } // end else
    // if statement to catch any errors while opening file

    int wIdInt, wVInt, wAInt;
    string wIdString, wNString, wVString, wAString;
    // declaring local variables that will be used from reading the data from the txt file

    while (!inDataW.eof()) {
        if (!inDataW.fail()) {
            getline(inDataW, wIdString, ',');
            getline(inDataW, wNString, ',');
            getline(inDataW, wVString, ',');
            getline(inDataW, wAString, '\n');
            // getting the line information from the text file line by line, using the delimiter ','
        } // end if
        else {
            inDataW.clear();
            cout << "Wrong input in: Workers.txt";
            inDataW.ignore(100, '\n');
            // using an if else statement for fail, so if teh data fails at any point it can ignore the next 100 new lines
        } // end else
        // I do not know if this statement will be useful as I have the try catch, but if it works and is useful... Yay

        try {
            // this is because there is a newline in the text file. The parse throws an error if it runs again
            // as stoi is only a char it cant read any more than one character, any more than that, and it will throw this error
            wIdInt = stoi(wIdString);
            wVInt = stoi(wVString);
            wAInt = stoi(wAString);
        } // end try
        catch (const invalid_argument &e) {
            cout << e.what() << " has an invalid input in read input workers!! " << endl;
        } // end catch
        catch (const out_of_range &e) {
            cout << e.what() << "Workers.text file is out of range!!" << endl;
        } // end catch

        Workers w;
        w.setWorker(wIdInt, wNString, wVInt, wAInt);
        // setting the workers with the text from the file

        if (numWorkers < MAXWORKERS) {
            wList[numWorkers] = w;
            numWorkers++;
            // statement to check if array has not reached max if not adds it to the array then adds one to numWorkers
        } // end if
        else {
            cout << "No more space for workers in the array." << endl;
            // error message if you add more than 20 workers to the array
        } // ends else
    } // end while loop
    inDataW.close();
} // end method

void readTextInputTasks() {
    fstream inData;
    inData.open("Tasks.txt");

    if (!inData) {
        // check if opened successfully
        cout << "Error opening : Tasks.text " << endl;
        return; // exit with an error code
    } // end if
    else if (inData.bad()) {
        cout << "Tasks has hardware issues" << endl;
        return;
    } // end else
    else if (inData.fail()) {
        cout << "Tasks data is invalid" << endl;
        return;
    } // end else
    // if statement to catch any errors while opening file

    int taskNoInt, taskUnInt, taskDiffInt;
    string taskNoString, taskNameString, taskUncertString, taskDiffString, listOfWorkersEnd;
    // declaring local variables that will be used from reading the data from the txt file

    while (!inData.eof()) {
        if (!inData.fail()) {
            getline(inData, taskNoString, ',');
            getline(inData, taskNameString, ',');
            getline(inData, taskUncertString, ',');
            getline(inData, taskDiffString, ',');
            inData.ignore(8, ':');
            getline(inData, listOfWorkersEnd, '\n');
            // getting the info from the text file line by line and part by part using the delimiter of ','
        } // end if
        else {
            inData.clear();
            cout << "Wrong input in the file: Tasks.txt";
            inData.ignore(100, '\n');
            // using an if else statement for fail, so if teh data fails at any point it can ignore the next 100 new lines
        } // end else
        // I do not know if this if statement will be useful as I have the try catch. but if it works and is useful... Yay

        try {
            taskNoInt = stoi(taskNoString);
            taskUnInt = stoi(taskUncertString);
            taskDiffInt = stoi(taskDiffString);
            // this is because there is a newline in the text file. The parse throws an error if it runs again
        } // end try
        catch (const invalid_argument &e) {
            cout << e.what() << " has an invalid input in read task input!" << endl;
        } // end catch
        catch (const out_of_range &e) {
            cout << e.what() << "tasks.text is out of range!" << endl;
        } // end catch

        Tasks t;
        t.setTask(taskNoInt, taskNameString, taskUnInt, taskDiffInt, listOfWorkersEnd);

        if (numTasks < MAXTASKS) {
            if (!checkFunction(t)) {
                //this bool method is put in because it kept adding Task 10 multiple times
                tList[numTasks] = t;
                numTasks++;
                //statement to check if new tasks has not reached maximum tasks in array if not it adds it to the array then adds one to numTasks
            } // end if statement
        } // end if
        else {
            cout << "No more space for tasks in the array." << endl;
            // error message if you add more than 20 workers to the array
        } // ends else
    } // end while loop
    inData.close();
} // end method

bool checkFunction(const Tasks &t) {
    for (const Tasks &tasks: tList) {
        if (t.taskId == tasks.taskId) {
            // checks if the new tasks id matches any of the ids currently in the list
            return true;
        } // end if
    } //end for
    return false;
} // end method

void Tasks::setTask(int idd, string des, int uncer, int diff, string fi) {
    taskId = idd;
    description = std::move(des);
    uncertainty = uncer;
    difficulty = diff;
    id = std::move(fi);
    // setter method to set the variables for tasks
} // end method

void displayTasksAndOutput() {

    string stringOfWorkers;

    ofstream outFile("output.txt");

    if (outFile.is_open()) {
        for (int i = 0; i < numTasks; i++) {
            // I have done it, so it writes to the terminal and the file so if there is any errors I do not need to keep checking the text file
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Processing Task id: \t" << tList[i].taskId << endl
                 << "Description \t: \t" << tList[i].description << endl
                 << "uncertainty \t: \t" << tList[i].uncertainty << endl
                 << "difficulty\t: \t" << tList[i].difficulty << endl
                 << "workers \t: \t" << tList[i].id << endl << endl;

            outFile << "------------------------------------------------------------------------" << endl;
            outFile << "Processing Task id: \t" << tList[i].taskId << endl
                    << "Description \t: \t" << tList[i].description << endl
                    << "uncertainty \t: \t" << tList[i].uncertainty << endl
                    << "difficulty\t: \t" << tList[i].difficulty << endl
                    << "workers \t: \t" << tList[i].id << endl << endl;
            //c out to terminal, out file to output.txt

            istringstream iss(tList[i].id);

            while (getline(iss, stringOfWorkers, ',')) {
                // using istringstream with a while loop to read across the line and turn the string into the in with the delimiter ','

                int findWorker;

                try {
                    findWorker = stoi(stringOfWorkers);
                } // end try
                catch (const invalid_argument &e) {
                    cout << e.what() << " has an invalid input in print to terminal!" << endl;
                } // end catch
                catch (const out_of_range &e) {
                    cout << e.what() << "out of range!" << endl;
                } // end catch

                if (performanceScore(tList[i], findWorker) <= 50) {
                    cout << "----------------------------------------------------------------------" << endl;
                    cout << "the average performance is " << performanceScore(tList[i], findWorker) << endl;
                    cout << "Assignment of task " << tList[i].taskId << " to worker " << stringOfWorkers << " failed!! "
                         << endl;
                    cout << "----------------------------------------------------------------------" << endl << endl;

                    outFile << "----------------------------------------------------------------------" << endl;
                    outFile << "the average performance is " << performanceScore(tList[i], findWorker) << endl;
                    outFile << "Assignment of task " << tList[i].taskId << " to worker " << stringOfWorkers
                            << " failed!! "
                            << endl;
                    outFile << "----------------------------------------------------------------------" << endl << endl;
                    // will keep running in the while loop if the workers score is less than 50
                } // end if
                else if (performanceScore(tList[i], findWorker) > 50) {
                    cout << "----------------------------------------------------------------------" << endl;
                    cout << "the average performance is " << performanceScore(tList[i], findWorker) << endl;
                    cout << "Assignment of task " << tList[i].taskId << " to worker " << stringOfWorkers
                         << " succeeds!! "
                         << endl;
                    cout << "----------------------------------------------------------------------" << endl << endl;

                    outFile << "----------------------------------------------------------------------" << endl;
                    outFile << "the average performance is " << performanceScore(tList[i], findWorker) << endl;
                    outFile << "Assignment of task " << tList[i].taskId << " to worker " << stringOfWorkers
                            << " succeeds!! "
                            << endl;
                    outFile << "----------------------------------------------------------------------" << endl << endl;
                    break;
                    // when the returned performance score is over 50 it will break the while loop and continue onto the next task
                } // end else if
            } // end while loop
        } // end for loop

        outFile.close();
        cout << "Data successfully writen to file output.txt" << endl;
    } // end is_open
    else {
        cout << "Data unsuccessfully written to output.txt" << endl;
    } // end else
    // if statement to inform the user if written to file successfully
}// end method

int performanceScore(const Tasks &tasksVar, int findWorker) {
    double mean1, sDev;
    default_random_engine(gen);
    //creating the random number generator

    for (int j = 0; j < numTasks; j++) {
        if (findWorker == wList[j].workerID) {
            // used to find the worker id and use that worker ability and variability
            mean1 = wList[j].ability - tasksVar.difficulty;
            sDev = tasksVar.uncertainty + wList[j].variability;
        } // end if
    } // end for

    normal_distribution<double> distribution(mean1, sDev);
    // getting the normal distribution

    return distribution(gen);
} // end method
