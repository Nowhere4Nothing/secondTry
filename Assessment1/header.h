//
// Created by Will on 18/08/2023.
//

#ifndef SECONDTRY_HEADER_H
#define SECONDTRY_HEADER_H

#endif //SECONDTRY_HEADER_H

#include <iostream>

using namespace std;

struct Workers {
    int workerID{};
    string wName;
    int variability;
    int ability{};

    void setWorker(int, string, int, int);
};

struct Tasks {
    int taskId{};
    string description;
    int uncertainty;
    int difficulty{};
    string id;

    void setTask(int, string, int, int, string);
};
// declaring the structures

void readInputWorkers();
void readTextInputTasks();
bool checkFunction(const Tasks& t);
void displayTasksAndOutput();
int performanceScore(const Tasks& iii, int s);
// declaring the methods