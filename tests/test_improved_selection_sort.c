//
// Created by Александр Баташев on 09.12.16.
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

//    FILE *fp = fopen("array.dat", "r");
//    int i;
//    int * arr = (int *) calloc(N, sizeof(int));
//
//    for (i = 0; i < N; ++i)
//    {
//        fscanf(fp, "%d", &arr[i]);
//    }
//
//    fclose(fp);

    improved_selection_sort(arr, N);

    int i;

    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n Обнаружено %d ошибок", check_sort_order(arr, N));

    return 0;
}