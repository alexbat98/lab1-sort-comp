//
// Created by Александр Баташев on 02.12.16.
//

#include "utils.h"

int CONSTANT_ARRAY[17] = {21, 13, 28, 5, 71, 6, 79, 42, 7, 19, 44, 20, 16, 1, 29, 37, 56};

/**
 * Проверяет корректность сортировки
 * @param arr Массив данных
 * @param n Число элементов
 * @return Количество неправильн отсортированных пар элементов
 */
int check_sort_order(int *arr, int n)
{
    int i, flag = 0;

    for (i = 0; i < n-1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            flag++;
        }
    }

    return flag;
}