#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//первое задание

void zadanie1() {
		int n = 10, i = 0, min, max;
        int a[10]={4,1,2,0,124,5,6,78,8,9};
		min = a[i];
		max = a[i];
		while (i < n) {
			if (a[i] > max) max = a[i]; 
			if (a[i] < min) min = a[i];
			i++;
		}
		printf("Массив: ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		printf("Минимальный элемент массива: %d Максимальный элемент массива: %d\n", min, max);
		
}

//второе задание

void zadanie2() {
	    int n = 10, i = 0;
        int b[10];
		printf("Случайно сгенерированный массив:\n ");
		while (i < n) {
			b[i] = rand()%1000;
			printf("%d\n", b[i]);
			i++;
		}

		
}

//третье задание

void zadanie3() {
	int *c;
 	int  n;
	int i = 0;
	printf("Введите количество элементов массива: ");
	scanf_s("%d", &n);
	printf("Случайно сгенерированный массив из %d элементвов: \n", n);
 	c = (int*)malloc(n * sizeof(int));
	while (i < n) {
			c[i] = rand()%1000;
			printf("%d\n", c[i]);
			i++;
		}
	

}

//четвёртое задание

void zadanie4(){
	int d[3][3];
	int s1 = 0, s2 = 0, s3 = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
		d[i][j] = rand()%10;
		}
	}

	printf("Случайно сгенерированный массив размером 3х3: \n");

	for (int i = 0; i < 3; i++){	
		for (int j = 0; j < 3; j++){
		printf("%d ", d[i][j]);
		if (j == 2) printf("\n");
		}
	}

	for (int i = 0; i < 3; i++){	
		for (int j = 0; j < 3; j++){
		if (i == 0) s1 += d[i][j];
		if (i == 1) s2 += d[i][j];
		if (i == 2) s3 += d[i][j];
		}
	}

	printf("Сумма первой строки: %d Сумма второй строки: %d Сумма третьей строки: %d\n", s1, s2, s3);
	
}

//пятое задание

void zadanie5(){
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i;
	char vvod[20];
	struct student
	{
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[3];

	for(i=0;i<3;i++)
	{
		printf("Введите фамилию студента\n"); scanf("%20s",stud[i].famil);
		printf("Введите имя студента %s\n",stud[i].famil); scanf("%20s",stud[i].name);
		printf("Введите название факультета студента %s %s\n",stud[i].famil,stud[i].name); scanf("%20s",stud[i].facult);
		printf("Введите номер зачётной книжки студента %s %s\n",stud[i].famil,stud[i].name); scanf("%d",&stud[i].Nomzach);
	}

	printf("\n");
	printf("Введите фамилию студента, которого хотите найти: \n");
	
	scanf("%s",vvod);

	for (i=0;i<3;i++){
		if (strcmp(vvod, stud[i].famil) == 0) {
			printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach); break;
		}
		else { printf("Студент с фамилией %s не найден", vvod); break; }
	}

	

}

//главная функция

int   main(void)
    {
		setlocale(LC_ALL, "Rus");

		printf("Задание 1:\n");
		zadanie1();
		printf("\n");

		printf("Задание 2:\n");
		zadanie2();
		printf("\n");

		printf("Задание 3:\n");
		zadanie3();
		printf("\n");

		printf("Задание 4:\n");
		zadanie4();
		printf("\n");

		printf("Задание 5:\n");
		zadanie5();

		_getch();

        return 0;
}
