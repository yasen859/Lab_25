#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, ".UTF8");
	
	int m = 1 + rand() % 10;
	int i = 1 + rand() % 10;
	int k, c;
	printf("Введите число от 1 до 10");
	scanf_s("%d", &k);
	if (m == k) {
		printf("Число угадано\n");
	}
	else
	{
		printf("Число не угадано, загаданное число %d\n", m);
	}
	do{
		printf("Вы кидаете игральную десятигранную кость и вам выпадает число: %d\n", i);
		printf("Хотите бросить кость повторно? (Да - 1, Нет - 2)\n");
		scanf_s("%d", &c);
	
	} while (c == 1);
	return 0;

	
}