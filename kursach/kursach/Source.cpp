#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>
#include "Header.h"
//Максимальное значение веса = 10

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");
    int n;
    scanf_s("%d", &n);

    srand(time(NULL));

    int** matrix;
    matrix = (int**)malloc(sizeof(int) * n);
    
    
            for (int i = 0; i < n; i++) {
                matrix[i] = (int*)malloc(sizeof(int) * n);
            }


            for (int i = 0; i < n; i++)							//заполнение массива 
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        matrix[i][j] = 0;
                    }
                    
                    else
                    {
                        matrix[i][j] = rand() % 100;
                    }
                }
            }
            for (int i = 0; i < n; i++)							//отзеркаливание матрицы
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[j][i] = matrix[i][j];
                }
            } 
           
        

    cout << "Old matrix" << endl;
    printMatrix(matrix, n);

    originalFloydWarshall(matrix, n);

    cout << "New matrix" << endl;

    printMatrix(matrix, n);

    return 0;
}