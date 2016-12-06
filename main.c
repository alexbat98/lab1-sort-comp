//
// Created by Александр Баташев on 01.12.16.
//
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <memory.h>
#include <time.h>
#include "utils.h"
#include "algorithms.h"

#define N 1000000

int main()
{
    setlocale(LC_ALL, "");

    printf("Сравнение алгоритмов сортировки\n\n");

    FILE *fp = fopen("array.dat", "r");
    int i;
    int * original_arr = (int *) calloc(N, sizeof(int));

    for (i = 0; i < N; ++i)
    {
        fscanf(fp, "%d", &original_arr[i]);
    }

    fclose(fp);

    int * working_arr = (int *) calloc(N, sizeof(int));

    clock_t start, end;
    float res;
    char check_flag;

    printf("%-64s%-15s%-20s\n", "Название алгоритма", "Время", "Корректность");

    // Тестирование классического пузырька

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    bubble_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Классический пузырек", res, check_flag);

    // Конец тестирования классического пузырька

    // Тестирование улучшенного пузырька

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    better_bubble_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Улучшенный пузырек", res, check_flag);

    // Конец тестирования улучшенного пузырька

    // Тестирование сортировки Шелла

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    shell_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Сортировка Шелла", res, check_flag);

    // Конец тестирования Сортировки Шелла

    // Тестирование сортировки выбором

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    //selection_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Сортировка выбором", res, check_flag);

    // Конец тестирования Сортировки выбором

    // Тестирование сортировки вставками

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    insertion_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Сортировка вставками", res, check_flag);

    // Конец тестирования Сортировки вставками

    // Тестирование сортировки слиянием

    memcpy(working_arr, original_arr, N * sizeof(int));
    int *scratch = (int *) calloc(N, sizeof(int));

    start = clock();
    merge_sort(working_arr, scratch, 0, N - 1);
    end = clock();

    free(scratch);

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Сортировка слиянием", res, check_flag);

    // Конец тестирования Сортировки слиянием

    // Тестирование быстрой сортировки

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    quick_sort(working_arr, 0, N - 1);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%-15.3f%-20c\n", "Быстрая сортировка", res, check_flag);

    // Конец тестирования быстрой сортировки

    return 0;
}