#include <iostream>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>





using namespace std;

void printMatrix(int** matrix, int n, ofstream &fout) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
                fout << matrix[i][j] << " ";
        }
        cout << endl;
        fout << endl;
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
    ofstream fout("newMatrix.txt");
    setlocale(LC_ALL, "Rus");
    int n, numberEnter, numberVec;
    bool proverka = false;
    cout << "�������� ��� �� ������ ������ ������� ���������: " << endl << "1. �������� �������������" << endl << "2. ������ �������" << endl << "3. ������ �� �����" << endl;
    while (!proverka) {
        scanf_s("%d", &numberEnter);
        cout << endl;
        if (numberEnter == 1 || numberEnter == 2 || numberEnter == 3) proverka = true;
        else printf("������� ������� ������� ��� � �� ����������. ���������� ��� ���.\n");
    }

    if (numberEnter == 1) {
        cout << "������� ���������� ������ � �������: ";
        scanf_s("%d", &n);
        cout << endl;
        cout << "�������� ��� �����: " << endl << "1. ������������" << endl << "2. ��������������" << endl;
        
        int** matrix;
        matrix = (int**)malloc(sizeof(int) * n);
        srand(time(NULL));

        for (int i = 0; i < n; i++) {
            matrix[i] = (int*)malloc(sizeof(int) * n);
        }

        proverka = false;
        while (!proverka)
        {
            cin >> numberVec;
            if (numberVec == 1 || numberVec == 2) {
                proverka = true;
            }
            else
            {
                printf("������� ������� ������� ��� � �� ����������. ���������� ��� ���.\n");
            }
        }
            
        if (numberEnter == 1 || numberEnter == 2) {
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
                            matrix[i][j] = rand() % 101;
                        }
                    }
                }

                if (numberVec == 2) {
                    for (int i = 0; i < n; i++)							//�������������� �������
                    {
                        for (int j = 0; j < n; j++)
                        {
                            matrix[j][i] = matrix[i][j];
                        }
                    }

                }
            }
            
        

        cout << "�������� �������: " << endl;
        fout << "�������� �������: " << endl;
        fout << "���������� ������: " << n << endl;
        printMatrix(matrix, n, fout);
        originalFloydWarshall(matrix, n);
        cout << endl;
        fout << endl;
        cout << "���������� �������: " << endl;
        fout << "���������� �������: " << endl;
        fout << "���������� ������: " << n << endl;
        printMatrix(matrix, n, fout);
        cout << endl << "��������� ������� � ���� newMatrix.txt" << endl;
    }

    if (numberEnter == 2) {
        cout << "������� ���������� ������ � �������: ";
        scanf_s("%d", &n);
        cout << endl;
        int** matrix;
        int numb;
        matrix = (int**)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            matrix[i] = (int*)malloc(sizeof(int) * n);
        }
        for (int i = 0; i < n; i++) {
            cout << "���� " << i + 1 << "-� ������" << endl <<endl;
            for (int j = 0; j < n; j++) {
                if (i == j)
                {
                    cout << j + 1 << "-� ������� ������� �� ��������� 0" << endl;
                    matrix[i][j] = 0;
                }

                else
                {
                    proverka = false;
                    while (!proverka) {
                        cout << "������� " << j + 1 << "-� ������� �������: ";
                        cin >> numb;
                        cout << endl;
                        if (numb >= 0) {
                            matrix[i][j] = numb;
                            proverka = true;
                        }

                        else
                        {
                            cout << "���������� ������ ������������� �������. ��������� �������" << endl;
                            proverka = false;
                        }
                    }
                }
            }
        }

        cout << "�������� �������: " << endl;
        fout << "�������� �������: " << endl;
        fout << "���������� ������: " << n << endl;
        printMatrix(matrix, n, fout);
        originalFloydWarshall(matrix, n);
        cout << endl;
        fout << endl;
        cout << "���������� �������: " << endl;
        fout << "���������� �������: " << endl;
        fout << "���������� ������: " << n << endl;
        printMatrix(matrix, n, fout);
        cout << endl << "��������� ������� � ���� newMatrix.txt" << endl;
    }

    if (numberEnter == 3) {
        ifstream file("matrix.txt");
        if (!file.is_open()) { // ���� ���� �� ������
            cout << "���� �� ����� ���� ������!\n";
            system("pause");
            return 1;
        }
        file >> n;
        cout << "���������� ������ � ������� �����: " << n << endl;

        int** matrix = (int**)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            matrix[i] = (int*)malloc(sizeof(int) * n);
        }

        //��������� ������� 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> matrix[i][j];
                if (matrix[i][j] < 0) {
                    cout << "� ������� ��������� ������������� �������. ��������� �������." << endl;
                    system("pause");
                    return 1;
                }
                if (i == j) {
                    if (matrix[i][j] != 0) {
                        cout << "� ������� �� ��� �������� ������� ��������� ����. ��������� �������." << endl;
                        system("pause");
                        return 1;
                    }
                }
            }
        }

        file.close();

        cout << "�������� �������: " << endl;
        fout << "�������� �������: " << endl;
        fout << "���������� ������: " << n << endl;
        printMatrix(matrix, n, fout);
        originalFloydWarshall(matrix, n);
        cout << endl;
        fout << endl;
        cout << "���������� �������: " << endl;
        fout << "���������� �������: " << endl;
        fout << "���������� ������: " << n << endl;
        printMatrix(matrix, n, fout);
        cout << endl << "��������� ������� � ���� newMatrix.txt" << endl;
    }
    system("pause");
    return 0;
}