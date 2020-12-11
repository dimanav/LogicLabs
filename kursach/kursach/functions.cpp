#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>


#define INF 51

using namespace std;

void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF) {
                cout << "INF" << " ";
            }
            else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

//matrix - матрица смежности
void originalFloydWarshall(int** matrix, int n) {
    //Пробегаемся по всем вершинам и ищем более короткий путь
    //через вершину k
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //Новое значение ребра равно минимальному между старым
                //и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    return;
}

