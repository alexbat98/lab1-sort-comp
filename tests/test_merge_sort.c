//
// Created by alexb on 06.12.2016.
//


#include "../src/algorithms.h"
#include "../src/utils.h"
#include <stdio.h>
#include <stdlib.h>

extern int CONSTANT_ARRAY[17];
//#define N N_CONST
#define N 20
int main()
{


//    int *arr = CONSTANT_ARRAY; // для удобсва

//    int arr[] = {4, 2, 5, 8, 0, 17, 32, 6, 1, 3, 9, 12, 18, 23, 15, 93, 21, 45, -1, 8};
    int arr[N];
    int i;

    for (i = 0; i < N; ++i)
    {
        arr[i] = rand() % 10000;
    }

    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, N);


    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n Обнаружено %d ошибок", check_sort_order(arr, N));

    return 0;
}
