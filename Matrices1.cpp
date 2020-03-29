// PointersAndFunctions_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
double** makeMatrix(int numRows, int numCols);
void deleteMatrix(int numRows, double** matrix2delete);

void main2(int argc, char* argv[])
{
    int rows = 10; int cols = 3;
    double** A;
   // double** V;
    /*A = new double* [rows];
    V = new double[rows];
    for (int i=0; i < rows; i++)
    {
        A[i] = new double[cols];        
    }
    */
    A = makeMatrix(rows, cols);

    for (int j = 0; j < rows; j++)
    {
     //   V[j] = j;
        for (int i = 0; i < cols; i++)
        {
            A[j][i] = i + j;
        }
    }

    for (int j = 0; j < rows; j++)
    {
        // std::cout << V[j] << ":" << A[j][0] <<" " << A[j][1] << " " << A[j][2] << std::endl;
        std::cout << A[j][0] << " " << A[j][1] << " " << A[j][2] << std::endl;
    }
    deleteMatrix(rows, A);

    /*
    for (int i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] V;
    */
}

// std::vector<std::vector<double>>

double** makeMatrix(int numRows, int numCols)
// allocates memory for a matrix
{
    double** matrix;
    matrix = new double* [numRows];
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = new double[numCols];
    }
    return matrix;
}

void deleteMatrix(int numRows, double** matrix2delete)
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] matrix2delete[i];
    }
    delete[] matrix2delete;
}





