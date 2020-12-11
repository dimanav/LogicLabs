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
int main(int argc, char** argv) {
    ofstream fout("newMatrix.txt");
    setlocale(LC_ALL, "Rus");
    int n, numberEnter, numberVec;
    bool proverka = false;
    cout << "Выберите как вы хотите задать матрицу смежности: " << endl << "1. Случайно сгенерировать" << endl << "2. Ввести вручную" << endl << "3. Ввести из файла" << endl;
    while (!proverka) {
        scanf_s("%d", &numberEnter);
        cout << endl;
        if (numberEnter == 1 || numberEnter == 2 || numberEnter == 3) proverka = true;
        else printf("Команда введена неверно или её не существует. Попробуйте ещё раз.\n");
    }

    if (numberEnter == 1) {
        cout << "Введите количество вершин в матрице: ";
        scanf_s("%d", &n);
        cout << endl;
        cout << "Выберите вид графа: " << endl << "1. Направленный" << endl << "2. Ненаправленный" << endl;
        
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
                printf("Команда введена неверно или её не существует. Попробуйте ещё раз.\n");
            }
        }
            
        if (numberEnter == 1 || numberEnter == 2) {
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
                            matrix[i][j] = rand() % 101;
                        }
                    }
                }

                if (numberVec == 2) {
                    for (int i = 0; i < n; i++)							//отзеркаливание матрицы
                    {
                        for (int j = 0; j < n; j++)
                        {
                            matrix[j][i] = matrix[i][j];
                        }
                    }

                }
            }
            
        

        cout << "Исходная матрица: " << endl;
        fout << "Исходная матрица: " << endl;
        fout << "Количество вершин: " << n << endl;
        printMatrix(matrix, n, fout);
        originalFloydWarshall(matrix, n);
        cout << endl;
        fout << endl;
        cout << "Полученная матрица: " << endl;
        fout << "Полученная матрица: " << endl;
        fout << "Количество вершин: " << n << endl;
        printMatrix(matrix, n, fout);
        cout << endl << "Результат сохранён в файл newMatrix.txt" << endl;
    }

    if (numberEnter == 2) {
        cout << "Введите количество вершин в матрице: ";
        scanf_s("%d", &n);
        cout << endl;
        int** matrix;
        int numb;
        matrix = (int**)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            matrix[i] = (int*)malloc(sizeof(int) * n);
        }
        for (int i = 0; i < n; i++) {
            cout << "Ввод " << i + 1 << "-й строки" << endl <<endl;
            for (int j = 0; j < n; j++) {
                if (i == j)
                {
                    cout << j + 1 << "-й элемент массива по умолчанию 0" << endl;
                    matrix[i][j] = 0;
                }

                else
                {
                    proverka = false;
                    while (!proverka) {
                        cout << "Введите " << j + 1 << "-й элемент массива: ";
                        cin >> numb;
                        cout << endl;
                        if (numb >= 0) {
                            matrix[i][j] = numb;
                            proverka = true;
                        }

                        else
                        {
                            cout << "Невозможно ввести отрицательный элемент. Повторите попытку" << endl;
                            proverka = false;
                        }
                    }
                }
            }
        }

        cout << "Исходная матрица: " << endl;
        fout << "Исходная матрица: " << endl;
        fout << "Количество вершин: " << n << endl;
        printMatrix(matrix, n, fout);
        originalFloydWarshall(matrix, n);
        cout << endl;
        fout << endl;
        cout << "Полученная матрица: " << endl;
        fout << "Полученная матрица: " << endl;
        fout << "Количество вершин: " << n << endl;
        printMatrix(matrix, n, fout);
        cout << endl << "Результат сохранён в файл newMatrix.txt" << endl;
    }

    if (numberEnter == 3) {
        ifstream file("matrix.txt");
        if (!file.is_open()) { // если файл не открыт
            cout << "Файл не может быть открыт!\n";
            system("pause");
            return 1;
        }
        file >> n;
        cout << "Количесвто вершин в матрице равно: " << n << endl;

        int** matrix = (int**)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            matrix[i] = (int*)malloc(sizeof(int) * n);
        }

        //Считываем матрицу 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> matrix[i][j];
                if (matrix[i][j] < 0) {
                    cout << "В матрице обнаружет отрицательный элемент. Исправьте матрицу." << endl;
                    system("pause");
                    return 1;
                }
                if (i == j) {
                    if (matrix[i][j] != 0) {
                        cout << "В матрице не все элементы главной диагонали нули. Исправьте матрицу." << endl;
                        system("pause");
                        return 1;
                    }
                }
            }
        }

        file.close();

        cout << "Исходная матрица: " << endl;
        fout << "Исходная матрица: " << endl;
        fout << "Количество вершин: " << n << endl;
        printMatrix(matrix, n, fout);
        originalFloydWarshall(matrix, n);
        cout << endl;
        fout << endl;
        cout << "Полученная матрица: " << endl;
        fout << "Полученная матрица: " << endl;
        fout << "Количество вершин: " << n << endl;
        printMatrix(matrix, n, fout);
        cout << endl << "Результат сохранён в файл newMatrix.txt" << endl;
    }
    system("pause");
    return 0;
}