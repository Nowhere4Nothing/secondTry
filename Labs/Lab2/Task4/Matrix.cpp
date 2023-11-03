//
// Created by Will on 15/08/2023.
//
#include <iostream>
using namespace std;

void multiplyMatrix(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols);

int main () {

    /* the example input */
//    float M1[10][10] = {{0.1067, 0.7749},{0.9619, 0.8173},{0.0046, 0.8687}};
//    float M2[10][10] = {{0.0844, 0.2599},{0.3998, 0.8001}};
//    {1, 2},{3, 4},{5, 6}
    float M1[10][10] = {{1, 2},{3, 4},{5, 6}};
    float M2[10][10] = {{1, 2},{3, 4}};

    multiplyMatrix(M1,M2,3,2,2,2);

    return 0;
/* end of example input */
}

void multiplyMatrix(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols) {
    float M3 [10][10];
    int i,j,k;

    if (M1_rows < 0 || M1_cols < 0 || M2_rows < 0 || M2_cols < 0) {
        cout << "there is no data in one of the arrays";
        return;
    }

    for (i = 0; i <= M1_rows; i++) {
        for (j = 0; j <= M2_cols; j++) {
            M3[i] [j] = 0;
            // this is initializing the M3 array to 0;
        }
    }

    for (i = 0; i < M1_rows; ++i) {
        // this reads across the rows of matrices one
        for (j = 0; j < M2_cols; j++) {
            //this reads down the column of the matrices two
            for (k = 0; k < M1_cols; k++) {
                // this reads the M1 columns, in this for loop we copy the information to M3

                if (M1_cols != M2_rows ) {
                   // in if statement to make sure the matrixs are correct, and it's possible to add
                    cout << "The dimensions of the matrix are not valid" << endl;
                    return;
                }


                M3[i][j] += M1[i][k] * M2[k][j];
                // this is calculating m3 by using the above formula.
            }
        }
    }

    cout << endl << "Output: " << endl;
    for (i = 0; i < M1_rows; i++) {
        for (j = 0; j < M2_cols; j++) {
            cout << "| " << M3[i] [j] << " |";
        }
        cout << endl;
    }
}
