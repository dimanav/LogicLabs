#include <time.h>
#include <iostream>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;
queue <int> Q;
int i, j, m, n, h;
int* vis;
int** graph;
int* ex;


void BFS() {
	for (int j = 0; j < m; j++) {
		printf("\n����� ���������� �� ������� %d\n", j + 1);
		for (int i = 0; i < m; i++) {
			vis[i] = 1000;
		}

		int s = j;
		Q.push(s);
		int st = s;

		vis[s] = 0;

		while (!Q.empty())
		{
			s = Q.front();
			Q.pop();

			for (int r = 0; r < n; r++)
				if ((graph[s][r] > 0) && (vis[r] > vis[s] + graph[s][r]))
				{
					Q.push(r);
					vis[r] = vis[s] + graph[s][r];
				}
		}

		for (int i = 0; i < m; i++)
		{
			
			//�������� �� ������������� �������
			if (vis[i] == 1000) {
				printf("- ");
				vis[i] = 0;
			}
			//����� ������
			else
				printf("%d ", vis[i]);

			if (vis[i] > ex[st])
			{
				ex[st] = vis[i];
			}

		}
	}
	int rad = 100000;
	int dia = 0;
	printf("\n���������������: \n");
	for (int i = 0; i < m; i++) {

		printf("%d ", ex[i]);
		if (ex[i] == 0)
			continue;
		if (ex[i] > dia)
			dia = ex[i];
		if ((ex[i] < rad) && (ex[i] != -1))
			rad = ex[i];
	}
	printf("\n\n������ - %d\n������� - %d", rad, dia);
	printf("\n����������� �������: \n");
	for (int i = 0; i < m; i++) {
		if (ex[i] == rad)
			printf("%d ", i + 1);
	}
	printf("\n������������ �������: \n");
	for (int i = 0; i < m; i++) {
		if (ex[i] == dia)
			printf("%d ", i + 1);
	}

	int deg = 0;
	printf("\n������������� �������: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] != 0) {
				deg += 1;
			}

		}
		if (deg == 0) {
			printf("%d ", i + 1);
		}

		deg = 0;
	}
	
	printf("\n������������ �������: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] != 0) {
				deg += 1;
			}

		}
		if (deg == m - 1) {
			printf("%d ", i + 1);
		}
		deg = 0;

	}
	printf("\n�������� �������: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] != 0) {
				deg += 1;
			}
				
		}
		if (deg == 1) {
			printf("%d ", i + 1);
		}
		deg = 0;
		
	}
}

void main(void)
{
	setlocale(LC_ALL, "Rus");
	printf("�����������:  ");
	scanf_s("%d", &m);
	printf("�������� ����� � �����: ");
	scanf_s("%d", &h);
	h++;
	n = m;
	graph = new int* [m];
	ex = (int*)malloc(m * sizeof(int));
	vis = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}
	//��������� �������
	printf("������� ���������: \n");
	srand(time(NULL));
	for (i = 0; i < m; ++i) {
		for (j = i; j < m; ++j) {
			graph[i][j] = graph[j][i] = rand() % h;
		}
		graph[i][i] = 0; //��������� �������
	}
	h--;


	printf("\n");

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < m; ++j)
			printf("%d ", graph[i][j]);
		printf("\n");
	}

	

	printf("\n");
	BFS();
	_getch();
}
