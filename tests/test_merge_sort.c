//
// Created by alexb on 06.12.2016.
//


#include "../algorithms.h"
#include "../utils.h"
#include <stdio.h>
#include <stdlib.h>

extern int CONSTANT_ARRAY[17];
#define N N_CONST

int main()
{

    int *arr = CONSTANT_ARRAY; // для удобсва

    int *s = calloc(N, sizeof(int));

    merge_sort(arr, s, 0, N - 1);

    int i;

    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n Обнаружено %d ошибок", check_sort_order(arr, N));

    return 0;
}
