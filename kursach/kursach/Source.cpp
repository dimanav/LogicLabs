#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>

//������������ �������� ���� = 100
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

int main(int argc, char** argv) {
    printf("Vvedity: >> ");
    int n;
    scanf_s("%d", &n);
    

    srand(time(NULL));

    int** matrix = (int**)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }


    for (int i = 0; i < n; i++)							//���������� ������� 
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
    for (int i = 0; i < n; i++)							//�������������� �������
    {
        for (int j = 0; j < n; j++)
        {
            matrix[j][i] = matrix[i][j];
        }
    }

    

    //��������� ������� ����� �����
 //   for (int i = 0; i < n; i++) {
 //       for (int j = 0; j < n; j++) {
    //        cin >> matrix[i][j];
 //       }
  //  }

 

    cout << "Old matrix" << endl;
    printMatrix(matrix, n);

    originalFloydWarshall(matrix, n);

    cout << "New matrix" << endl;

    printMatrix(matrix, n);

    return 0;
}