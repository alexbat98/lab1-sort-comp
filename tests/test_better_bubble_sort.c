//
// Created by Александр Баташев on 02.12.16.
//

#include "../algorithms.h"
#include "../utils.h"
#include <stdio.h>

extern int CONSTANT_ARRAY[17];
#define N N_CONST

int main()
{

    int *arr = CONSTANT_ARRAY; // для удобсва

    better_bubble_sort(arr, N);

    int i;

    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n Обнаружено %d ошибок", check_sort_order(arr, N));

    return 0;
}