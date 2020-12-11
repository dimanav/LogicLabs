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

//matrix - ������� ���������
void originalFloydWarshall(int** matrix, int n) {
    //����������� �� ���� �������� � ���� ����� �������� ����
    //����� ������� k
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //����� �������� ����� ����� ������������ ����� ������
                //� ������ ����� i <-> k + k <-> j (���� ����� k ������ �������)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    return;
}

