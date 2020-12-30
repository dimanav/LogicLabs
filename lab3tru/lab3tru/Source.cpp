#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <time.h>
using namespace std;

void vivod(int n, int** p) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

}

int** delit(int** p1, int n, int del)
{


	int** p = (int**)malloc(n * sizeof(int*));			//выделение памяти под врменный двумерный массив
	for (int i = 0; i < n; i++)
	{
		p[i] = (int*)malloc(n * sizeof(int));
	}



	int k = 0, m = 0;			//k~~i,m~~j
	for (int i = 0; i < n; i++)
	{
		if (i == del)
		{
			continue;
		}
		else {

			for (int j = 0; j < n; j++)
				if (j == del)
				{
					continue;
				}
				else
				{
					p[k][m] = p1[i][j];
					printf("%d ", p[k][m]);
					m++;

				}
			m = 0;
			k++;
		}

		printf("\n");

	}


	for (int i = 0; i < n; i++)
	{
		free(p1[i]);
	}
	free(p1);

	n = n - 1;

	p1 = (int**)malloc(n * sizeof(int*));			//выделение памяти под двумерный массив p1
	for (int i = 0; i < n; i++)
	{
		p1[i] = (int*)malloc(n * sizeof(int));
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p1[i][j] = p[i][j];

		}

	}

	printf("\n\n");

	for (int i = 0; i < n; i++)
	{
		free(p[i]);
	}
	free(p);

	return (p1);
}			// На выход измененный массив

int** dob(int** p1, int n, int add)
{
	n = n + 1;
	int** p = (int**)malloc((n) * sizeof(int*));			//выделение памяти под врменную матрицу порядок которой на 1 больше
	for (int i = 0; i < (n); i++)
	{
		p[i] = (int*)malloc((n) * sizeof(int));
	}




	int m = 0, k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == add)
		{
			i = i + 1;
		}
		for (int j = 0; j < n; j++)
		{
			if (j == add)
			{
				j = j + 1;
			}
			p[i][j] = p1[m][k];
			k++;
		}
		k = 0;
		m++;

	}

	for (int i = 0; i < n; i++)		// обнуление центра и заполнение пустых элементов
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == add) or (j == add))
			{
				p[i][j] = rand() % 2;
			}
			if (i == j) {
				p[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = p[j][i];
		}
	}

	printf("\n\n");

	return (p);
}

int** zamikaniye(int** p1, int n)
{
	int i = 0, j = 0;
	int x = 0, y = 0;
	printf("Введите вершины для отождествления: ");
	scanf_s("%d %d", &x, &y);

	x -= 1;
	y -= 1;
	int del = 0;
	for (i = 0; i < n; i++)					//сложение строчек
	{
		if (i == x)
		{
			for (j = 0; j < n; j++)
			{
				p1[x][j] += p1[y][j];
			}
		}
		else continue;
	}

	for (i = 0; i < n; i++)				// сложение столбцов
	{
		for (j = 0; j < n; j++)
		{
			if (j == x)
			{
				p1[i][x] += p1[1][y];
			}
			else continue;
		}
	}
	for (i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (j = 0; j < n; j++)
		{
			p1[j][i] = p1[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p1[i][j] == 2)
			{
				p1[i][j] = 1;
			}
		}
	}

	p1 = delit(p1, n, y);
	return p1;
}

int** styagivaniye(int** p1, int n)
{
	int i = 0, j = 0;
	int x = 0, y = 0;
	printf("Введите вершины для стягивания: ");
	scanf_s("%d %d", &x, &y);

	x -= 1;
	y -= 1;
	int del = 0;
	for (i = 0; i < n; i++)					//сложение строчек
	{
		if (i == x)
		{
			for (j = 0; j < n; j++)
			{
				p1[x][j] += p1[y][j];
			}
		}
		else continue;
	}

	for (i = 0; i < n; i++)				// сложение столбцов
	{
		for (j = 0; j < n; j++)
		{
			if (j == x)
			{
				p1[i][x] += p1[1][y];
			}
			else continue;
		}
	}
	for (i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (j = 0; j < n; j++)
		{
			p1[j][i] = p1[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p1[i][j] == 2)
			{
				p1[i][j] = 1;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				p1[i][j] = 0;
			}
		}
	}

	p1 = delit(p1, n, y);
	return p1;
}



int main() {
	setlocale(LC_ALL, "Rus");
	int i = 0, j = 0, n;
	printf("Введите размер генерируемой матрицы: >> ");
	scanf_s("%d", &n);
	int** p1, ** p2, ** p;

	p1 = (int**)malloc(n * sizeof(int*));			//выделение памяти под двумерный массив p1
	for (int i = 0; i < n; i++)
	{
		p1[i] = (int*)malloc(n * sizeof(int));
	}
	srand(time(NULL));
	for (i = 0; i < n; i++)							//заполнение массива p1
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				p1[i][j] = 0;
			}
			else
			{
				p1[i][j] = rand() % 2;
			}
		}
	}
	for (i = 0; i < n; i++)							//отзеркаливание матрицы
	{
		for (j = 0; j < n; j++)
		{
			p1[j][i] = p1[i][j];
		}
	}





	while (true)									//меню взаимодействия
	{
		int choose;
		system("cls");
		cout << "1. Вывод матрицы №1" << endl;
		cout << "2. Удаление узла " << endl;
		cout << "3. Расщепление узла" << endl;
		cout << "4. Замыкание узлов" << endl;
		cout << "5. Стягивание узлов" << endl;
		cout << "6. Обьединение матриц" << endl;
		cout << "7. Кольцевая сумма" << endl;
		cout << "8. Пересечение" << endl;
		cout << "9. Выход" << endl;
		cin >> choose;

		if (choose == 1)							//вывод 
		{
			system("cls");
			vivod(n, p1);

			printf("\n\n");
			//vivod(n, p2);
			system("pause");
			continue;
		}

		if (choose == 2)							//удаление узла 
		{
			vivod(n, p1);
			cout << endl;
			int del;
			printf("Какой узел необходимо удалить? ");
			scanf_s("%d", &del);
			del = del - 1;

			p1 = delit(p1, n, del);
			n = n - 1;
			system("pause");
			continue;
		}

		if (choose == 3)	//Добавление узла
		{
			vivod(n, p1);
			cout << endl;
			int add;
			printf("После какого узла добавить новый? ");
			scanf_s("%d", &add);


			p = (int**)malloc((n + 1) * sizeof(int*));			//выделение памяти под двумерный массив p2
			for (int i = 0; i < (n + 1); i++)
			{
				p[i] = (int*)malloc((n + 1) * sizeof(int));
			}


			p = dob(p1, n, add);
			vivod(n + 1, p);



			for (i = 0; i < n; i++)
			{
				free(p1[i]);
			}
			free(p1);

			n = n + 1;

			p1 = (int**)malloc(n * sizeof(int*));			//выделение памяти под двумерный массив p2
			for (int i = 0; i < n; i++)
			{
				p1[i] = (int*)malloc(n * sizeof(int));
			}

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					p1[i][j] = p[i][j];
				}
			}

			system("pause");
			continue;
		}

		if (choose == 4)  //Замыкание узла
		{
			vivod(n, p1);
			cout << endl;
			p1 = zamikaniye(p1, n);

			n -= 1;

			system("pause");

			continue;
		}

		if (choose == 5)		//Стягивание узла
		{
			vivod(n, p1);
			cout << endl;
			p1 = styagivaniye(p1, n);

			n -= 1;

			system("pause");

			continue;
		}

		if (choose == 6) { //Обьединение 
			vivod(n, p1);
			cout << endl;
			p2 = (int**)malloc(n * sizeof(int*));			//выделение памяти под двумерный массив p2
			for (int i = 0; i < n; i++)
			{
				p2[i] = (int*)malloc(n * sizeof(int));
			}
			srand(time(NULL));
			for (i = 0; i < n; i++)							//заполнение массива p2
			{
				for (j = 0; j < n; j++)
				{
					if (i == j)
					{
						p2[i][j] = 0;
					}
					else
					{
						p2[i][j] = rand() % 2;
					}
				}
			}
			for (i = 0; i < n; i++)							//отзеркаливание матрицы
			{
				for (j = 0; j < n; j++)
				{
					p2[j][i] = p2[i][j];
				}
			}
			cout << "Матрица #1" << endl << endl;
			vivod(n, p1);
			cout << endl;
			cout << "Матрица #2" << endl << endl;
			vivod(n, p2);
			cout << endl;
			cout << "Результат: " << endl;
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (p1[i][j] + p2[i][j] != 2)
					{
						cout << p1[i][j] + p2[i][j] << " ";
					}
					else
					{
						cout << "1 ";
					}
				}
				cout << endl;
			}


			for (i = 0; i < n; i++)
			{
				free(p2[i]);
			}
			free(p2);

			system("pause");
			continue;
		}

		if (choose == 7)			//Кольцевая сумма
		{

			p2 = (int**)malloc(n * sizeof(int*));			//выделение памяти под двумерный массив p2
			for (int i = 0; i < n; i++)
			{
				p2[i] = (int*)malloc(n * sizeof(int));
			}
			for (i = 0; i < n; i++)							//заполнение массива p2
			{
				for (j = 0; j < n; j++)
				{
					if (i == j)
					{
						p2[i][j] = 0;
					}
					else
					{
						p2[i][j] = rand() % 2;
					}
				}
			}
			for (i = 0; i < n; i++)							//отзеркаливание матрицы
			{
				for (j = 0; j < n; j++)
				{
					p2[j][i] = p2[i][j];
				}
			}
			cout << "Матрица #1" << endl << endl;
			vivod(n, p1);
			cout << endl;
			cout << "Матрица #2" << endl << endl;
			vivod(n, p2);
			cout << endl;
			cout << "Результат: " << endl;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (p1[i][j] + p2[i][j] == 2) cout << "0 ";
					if (p1[i][j] + p2[i][j] == 1) cout << "1 ";
					if (p1[i][j] + p2[i][j] == 0) cout << "0 ";
				}
				cout << endl;
			}


			for (i = 0; i < n; i++)
			{
				free(p2[i]);
			}
			free(p2);

			system("pause");
			continue;

		}

		if (choose == 8)			//Пересечение
		{

			p2 = (int**)malloc(n * sizeof(int*));			//выделение памяти под двумерный массив p2
			for (int i = 0; i < n; i++)
			{
				p2[i] = (int*)malloc(n * sizeof(int));
			}
			for (i = 0; i < n; i++)							//заполнение массива p2
			{
				for (j = 0; j < n; j++)
				{
					if (i == j)
					{
						p2[i][j] = 0;
					}
					else
					{
						p2[i][j] = rand() % 2;
					}
				}
			}
			for (i = 0; i < n; i++)							//отзеркаливание матрицы
			{
				for (j = 0; j < n; j++)
				{
					p2[j][i] = p2[i][j];
				}
			}
			cout << "Матрица #1" << endl << endl;
			vivod(n, p1);
			cout << endl;
			cout << "Матрица #2" << endl << endl;
			vivod(n, p2);
			cout << endl;
			cout << "Результат: " << endl;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					cout << p1[i][j] * p2[i][j] << " ";
				}
				cout << endl;
			}


			for (i = 0; i < n; i++)
			{
				free(p2[i]);
			}
			free(p2);

			system("pause");
			continue;
		}

		if (choose == 9)							//выход
		{
			break;
		}

	}

	//////////////////////////////////////////////     // очистка памяти
	for (i = 0; i < n; i++)
	{
		free(p1[i]);
	}
	free(p1);


	/////////////////////////////////////////////
	return 0;
}