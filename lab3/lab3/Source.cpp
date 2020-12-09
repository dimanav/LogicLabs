#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

void dfs_n(int v, int** p1, int n, int* vis)
{
	printf("Нерекурсивный");
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	stack <int> ss;
	ss.push(v);
	vis[v] = 1;
	printf(">> %d\n", v+1);


	while (!ss.empty())
	{

		v = ss.top();
		ss.pop();
		for (int i = 0; i < n; i++)
		{
			if ((p1[v][i] == 1) && (vis[i] == 0))
			{
				vis[i] = 1;
				ss.push(i);
				printf(">> %d\n", i + 1);
			}

		}

	}

}

void dfs(int v, int** p1, int n, int* vis)
{

	vis[v] = true;
	printf(">> %d\n", v + 1);
	for (int i = 0; i < n; i++)
	{
		if ((p1[v][i] == 1) and (vis[i] == 0))
		{
			dfs(i, p1, n, vis);
		}
	}
}

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




int main() {
	setlocale(LC_ALL, "Rus");
	int i = 0, j = 0, n, v;
	printf("Введите размер генерируемой матрицы: >> ");
	scanf_s("%d", &n);
	int** p1, * vis;

	srand(time(NULL));

	p1 = (int**)malloc(n * sizeof(int*));			//выделение памяти под всё, заполнение и отзеркаливание
	for (int i = 0; i < n; i++)
	{
		p1[i] = (int*)malloc(n * sizeof(int));
	}
	vis = (int*)malloc(n * sizeof(int));
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
	//for (i = 0; i < n; i++)							//отзеркаливание матрицы
//	{
	//	for (j = 0; j < n; j++)
//		{
	//		p1[j][i] = p1[i][j];
//		}
//	}


	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}

	printf("Введите вершину с которой начнется обход: >> ");
	scanf_s("%d", &v);
	v -= 1;
	printf("Рекурсивный\n");
	dfs(v, p1, n, vis);

	dfs_n(v, p1, n, vis);

	vivod(n, p1);
	system("pause");
}

