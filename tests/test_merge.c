//
// Created by Александр Баташев on 16.12.16.
//
#include <stdio.h>
#include "../algorithms.h"
#include <stdlib.h>

int main()
{
    int n1, n2, i;
    int *scratch, *arr;

    printf("Введите размер массива 1 ");
    scanf("%d", &n1);

    printf("Введите размер массива 2 ");
    scanf("%d", &n2);

    scratch = (int *) calloc((size_t) (n1 + n2), sizeof(int));
    arr = (int *) calloc((size_t) (n1 + n2), sizeof(int));

    printf("Введите числа первого массива\n");
    for (i = 0; i < n1; ++i)
    {
        scanf("%d", &scratch[i]);
    }

    printf("Введите числа второго массива\n");
    for (i = n1; i < n1 + n2; ++i)
    {
        scanf("%d", &scratch[i]);
    }

    merge(scratch, n1 + n2, n1, arr, 0);

    printf("Итоговый массив\n");
    for (i = 0; i < n1 + n2; ++i)
    {
        printf("%d ", arr[i]);
    }

    free(scratch);
    free(arr);
}