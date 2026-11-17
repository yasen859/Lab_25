#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define K         6    /* число оценок / диапазон значений (1..K) */
#define N         200  /* размер массива              */
#define R         40   /* максимальное число выводимых символов '*' */

int next_random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int find_max_index(const int* arr, int n)
{
    int i, nmax = 0;
    for (i = 1; i < n; i++)
        if (arr[i] > arr[nmax])
            nmax = i;
    return nmax;
}

void print_histogram(const int* counter, int k)
{
    int i, nmax = find_max_index(counter, k);
    printf("Гистограмма частоты выпадения значений (K = %d):\n", k);
    for (i = 0; i < k; i++) {
        int x = counter[i] == 0 ? 0 : counter[i] * R / counter[nmax];
        int j;
        printf("%2d | ", i + 1);
        for (j = 0; j < x; j++)
            putchar('*');
        printf("  (%d)\n", counter[i]);
    }
}

//Циклический сдвиг элементов массива влево на k позиций.
   //begin/end — адреса начала и конца диапазона
   // Возвращает указатель на начало массива. */
int* cyclic_shift_left(int* begin, int* end, int k)
{
    int n = (int)(end - begin);
    int step, i;
    if (n <= 0)
        return begin;
    k %= n;                

    for (step = 0; step < k; step++) {
        int first = begin[0];
        for (i = 0; i < n - 1; i++)
            begin[i] = begin[i + 1];
        begin[n - 1] = first;
    }
    return begin;
}

void print_array(const int* arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    setlocale(LC_ALL, ".UTF8");
    int array[N];
    int counter[K] = { 0 };
    int i;

    srand((unsigned)time(NULL));

    //Генерация N случайных чисел в диапазоне 1..K
    for (i = 0; i < N; i++)
        array[i] = next_random(1, K);

    //3. 
    for (i = 0; i < N; i++)
        counter[array[i]]++;

    /* 4, 5. Вертикальная гистограмма, оформленная отдельной функцией */
    print_histogram(counter, K);

    /* Задание 5, п.2: циклический сдвиг влево на k позиций */
    {
        int shift;
        print_array(array, N);
        printf("Введите k (число позиций сдвига влево): ");
        scanf_s("%d", &shift);

        cyclic_shift_left(array, array + N, shift);
        printf("Массив после сдвига влево на %d позиций:\n", shift);
        print_array(array, N);
    }

    return 0;
}