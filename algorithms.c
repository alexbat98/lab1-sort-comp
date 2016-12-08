//
// Created by Александр Баташев on 02.12.16.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "algorithms.h"

/**
 * Классическая пузырьковая сортировка
 * @param arr Массив значений для сортировки
 * @param n Длина массива
 */
void bubble_sort(int *arr, int n)
{
    int i, l, hasChanged;
    l = n - 1;

    do
    {
        hasChanged = 0;
        for (i = 0; i < l; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                arr[i] ^= arr[i + 1];
                arr[i + 1] ^= arr[i];
                arr[i] ^= arr[i + 1];
                hasChanged = 1;
            }
        }
        l--;
    } while (hasChanged);
}

/**
 * Улучшенная сортировка пузырьком с проходом в обе стороны
 * @param arr Массив данных
 * @param n Количество элементов
 */
void better_bubble_sort(int *arr, int n)
{
    int i, start, finish, hasChanged;

    start = 0;
    finish = n - 1;

    do
    {
        hasChanged = 0;

        for (i = start; i < finish; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                arr[i] ^= arr[i + 1];
                arr[i + 1] ^= arr[i];
                arr[i] ^= arr[i + 1];
                hasChanged = 1;
            }
        }
        --finish;
        if (hasChanged)
        {
            for (i = finish - 1; i >= start; --i)
            {
                if (arr[i] > arr[i + 1])
                {
                    arr[i] ^= arr[i + 1];
                    arr[i + 1] ^= arr[i];
                    arr[i] ^= arr[i + 1];
                    hasChanged = 1;
                }
            }
            start++;
        }
    }
    while (hasChanged);
}

/**
 * Сортировка Шелла
 * @param arr Массив данных
 * @param n Количество элементов
 */
void shell_sort(int *arr, int n)
{
    int i, hasChanged;
    int d = n;

    do
    {
        d = (d + 1) / 2;

        hasChanged = 0;

        for (i = 0; i < n - d; ++i)
        {
            if (arr[i] > arr[i + d])
            {
                arr[i] ^= arr[i+d];
                arr[i + d] ^= arr[i];
                arr[i] ^= arr[i + d];
                hasChanged = 1;
            }
        }
    }
    while (d != 1 || hasChanged);
}

/**
 * Поиск минимального элемента в массиве
 * @param arr Массив
 * @param n Количество элементов
 * @return Индекс минимального
 */
int min(int *arr, int n)
{
    int i, min_idx = 0;

    for (i = 0; i < n; ++i)
    {
        if (arr[i] < arr[min_idx])
        {
            min_idx = i;
        }
    }

    return min_idx;
}

/**
 * Поиск максимального элемента в массиве
 * @param arr Массив
 * @param n Количество элементов
 * @return Индекс минимального
 */
int max(int *arr, int n)
{
    int i, max_idx = 0;

    for (i = 0; i < n; ++i)
    {
        if (arr[i] > arr[max_idx])
        {
            max_idx = i;
        }
    }

    return max_idx;
}

/**
 * Сортировка выбором
 * @param arr Массив данных
 * @param n Количество элементов
 */
void selection_sort(int *arr, int n)
{
    int i, j, pos;

    for (i = 0; i < n - 1; ++i)
    {
        pos = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[pos] > arr[j])
            {
                pos = j;
            }
        }

        if (pos != i)
        {
            arr[i] ^= arr[pos];
            arr[pos] ^= arr[i];
            arr[i] ^= arr[pos];
        }
    }
}

/**
 * Сортировка вставками
 * @param arr Массив
 * @param n Количество элементов
 */
void insertion_sort(int *arr, int n)
{
    int i, j, b;

    for (i = 0; i < n - 1; ++i)
    {
        b = arr[i + 1];
        j = i;
        while ((j >= 0) && (b < arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = b;
    }
}

/**
 * Сортировка слиянием
 * @param arr Исходный массив
 * @param scratch Внешняя память
 * @param start Начальный индекс
 * @param end Конечный индекс
 */
void merge_sort(int *arr, int *scratch, int start, int end)
{
    if (end == start)
    {
        return;
    }

    // Середина массива
    int mid_point = (start + end) / 2;

    // Сортируем две половины
    merge_sort(arr, scratch, start, mid_point);
    merge_sort(arr, scratch, mid_point + 1, end);

    // Слияние
    int left_idx = start;
    int right_idx = mid_point + 1;
    int scratch_idx = left_idx;
    while ((left_idx <= mid_point) && (right_idx <= end))
    {
        if (arr[left_idx] <= arr[right_idx])
        {
            scratch[scratch_idx++] = arr[left_idx++];
        } else
        {
            scratch[scratch_idx++] = arr[right_idx++];
        }
    }

    int i;

    for (i = left_idx; i <= mid_point; i++)
    {
        scratch[scratch_idx++] = arr[i];
    }

    for (i = right_idx; i <= end; ++i)
    {
        scratch[scratch_idx++] = arr[i];
    }

    for (i = start; i <= end; i++)
    {
        arr[i] = scratch[i];
    }

}

/**
 * Быстрая сортировка
 * В данном случае используется деление не на 2, а на 3 части
 * Подробности:
 * http://www.geeksforgeeks.org/3-way-quicksort/
 * https://www.toptal.com/developers/sorting-algorithms/quick-sort-3-way
 * https://ru.wikipedia.org/wiki/Быстрая_сортировка
 * @param arr Массив данных
 * @param start Начало
 * @param end Конец
 * @param counter Счетчик вложенности рекурсии. При первом вызове всегда равен 0.
 */
void quick_sort(int *arr, int start, int end, int counter)
{

    /*
     * Специальная оптимизация, предотвращающая переполнение стека
     * и увеличивающая скорость работы алгоритма
     */
    if (counter >= 100)
    {
        insertion_sort(arr, end + 1);
        return;
    }

    if (start >= end)
    {
        return;
    }

    int tmp;

    if (end - start <= 1)
    {
        if (arr[start] > arr[end])
        {
            tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
        }
        return;

    }

    // Выбор опорного элемента случайным образом
    srand((unsigned int) time(0));
    int pos;

    do
    {
        pos = start + rand() % end;
    } while (pos < start && pos > end);

    int divider = arr[pos];

    int lo = start, mid = start;
    int hi = end;

    while (mid <= hi)
    {
        if (arr[mid] < divider)
        {
            tmp = arr[lo];
            arr[lo] = arr[mid];
            arr[mid] = tmp;
            mid++;
            lo++;
        } else if (arr[mid] == divider)
        {
            mid++;
        } else if (arr[mid] > divider)
        {
            tmp = arr[hi];
            arr[hi--] = arr[mid];
            arr[mid] = tmp;
        }

    }

    quick_sort(arr, start, lo - 1, ++counter);
    quick_sort(arr, mid, end, counter);

}