#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int rand10(int mmax) {
	return 1 + rand() % mmax;
}

double rand_double(double dmin, double dmax) {
	return dmin + (double)rand() / RAND_MAX * (dmax - dmin);
}

int* rand10_arr(int n, int mmax) {
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr[i] = rand10(mmax);
	}
	return arr;
}

double* rand_double_arr(int n, double dm) {
	double* arr = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		arr[i] = rand_double(-dm, dm);
	}
	return arr;
}


int main() {
	setlocale(LC_ALL, ".UTF8");
	srand(time(NULL));
	int n = 10;
	int mmax_v = 100;
	double dm_v = 5.5;
	int* int_arrey = rand10_arr(n, mmax_v);
	double* doubl_arrey = rand_double_arr(n, dm_v);
	
	printf("Случайные вещественные числа от 1 до 100: "); 
	for (int i = 0; i < n; i++) {
		printf("%.3f ", doubl_arrey[i]);
	}

	printf("\nСлучайные целые числа от 1 до 100: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", int_arrey[i]);
	}



	printf("\nОдно число (1 до10): %d\n", rand10(10));

	printf("Одно вещественное (-5 до 5): %f\n", rand_double(-5.0, 5.0));

	
}