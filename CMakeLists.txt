cmake_minimum_required(VERSION 3.26)
project(secondTry)

set(CMAKE_CXX_STANDARD 20)

add_executable(secondTry main.cpp
        sayHi.cpp
)

add_executable(lab1Task1 s/work.cpp)


add_executable(Debug-B.cpp Labs/Lab1/Debug-B/main.cpp
        Labs/Lab1/Debug-B/mylibrary.cpp
        Labs/Lab2/Debug-C.cpp)
add_executable(mainT2 Labs/Lab1/task2/task2main.cpp)
add_executable(L1T3main Labs/Lab1/Task3/L1T3main.cpp
        Labs/Lab1/Task3/header.L1T3.h
        Labs/Lab1/Task3/L1T3implementation.cpp)
add_executable(L1T4.main Labs/Lab1/Task4/L1T4.main.cpp)
add_executable(L1T5main Labs/Lab1/task5/L1T5main.cpp)

add_executable(L2T1Debug-A Labs/Lab2/Debug-A.cpp
        Labs/Lab2/Debug-A.cpp)
add_executable(L2T1DBug2 Labs/Lab2/Debug-B.cpp)
add_executable(L2T1DB3 Labs/Lab2/Debug-C.cpp)
add_executable(L2Read-Words Labs/Lab2/Task2/Read-Words.cpp
        Labs/Lab2/Task2/Words)

add_executable(L2cat Labs/Lab2/Task3/cat.cpp)
add_executable(L2exception Labs/Lab2/Task5/L2exception.cpp)

add_executable(L2matrix Labs/Lab2/Task4/Matrix.cpp)

add_executable(Ass1 Assessment1/Driver.cpp
        Assessment1/header.h
        Assessment1/header.cpp
       )
add_executable(L3DB1 Labs/Lab3/Task1/Debug-A.cpp)
add_executable(L3DB2 Labs/Lab3/Task1/Debug-B.cpp)
add_executable(L3T2Cat Labs/Lab3/Task2/Cat.cpp)
add_executable(L3T3Bonus Labs/Lab3/Task3/Bonus.cpp)
add_executable(L3T4 Labs/Lab3/Task4/four.cpp
        Labs/Lab3/Task4/Library.cpp
        Labs/Lab3/Task4/library.h)
add_executable(L3T5Comp Labs/Lab3/Task5/five.cpp
        Labs/Lab3/Task5/Library.cpp)
add_executable(L4T1 Labs/Lab4/T1/Debug-A.cpp)
add_executable(L4T2 Labs/Lab4/T2/A-Class.cpp)
add_executable(L4T3 Labs/Lab4/T3/Cat.cpp)


add_executable(L4T4 Labs/Lab4/T4/driver.cpp
        Labs/Lab4/T4/mylibrary.cpp)
add_executable(L4T5 Labs/Lab4/T5/ThreeLittlePigs.cpp)
add_executable(L4T3P2 Labs/Lab4/T3/Transport.cpp)
add_executable(L4T2P2Box Labs/Lab4/T2/Box.cpp)
add_executable(A2Driver Assessment2/Driver.cpp
        Assessment2/header.h
        Assessment2/header.cpp)
add_executable(L5T1Debug Labs/Lab5/Task_1/Debug-A.cpp)
add_executable(L5T1P2 Labs/Lab5/Task_1/findMax.cpp)
add_executable(L5T2 Labs/Lab5/Task_2/Symbolic.cpp)
add_executable(L5T3P1 Labs/Lab5/Task_3/Debug-B.cpp)
add_executable(L5T3Part2Fit Labs/Lab5/Task_3/fibT.cpp)
add_executable(L5T4Double Labs/Lab5/Task_4/doubled.cpp)
add_executable(L5T4Hold Labs/Lab5/Task_4/doubledHold.cpp)
add_executable(L3T5 Labs/Lab5/Task_5/Task5.cpp)
add_executable(Ass3 Assessment_3/Solution.cpp
        Assessment_3/collect.h)
add_executable(L1T1Debug Labs/Lab1/task1/Debug-A.cpp)
add_executable(LecPrac1 LecturePractice/Hacker.cpp)
