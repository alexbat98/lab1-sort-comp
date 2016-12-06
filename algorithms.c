//
// Created by Александр Баташев on 02.12.16.
//

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
 * Поиск минимального элемента в массиве
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
    int i, min_idx;

    for (i = 0; i < n - 1; ++i)
    {
        // C-style конструкция, прибавляем i к адресу первого элемента массива a
        // чтобы получить новый массив размера n - i
        min_idx = i + min(arr + i, n - i);
        arr[i] ^= arr[min_idx];
        arr[min_idx] ^= arr[i];
        arr[i] ^= arr[min_idx];
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
 * @param arr Массив данных
 * @param start Начало
 * @param end Конец
 */
void quick_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }


    // выбор опорного элемента
    int max_idx = max(arr + start, end + 1);
    int min_idx = min(arr + start, end + 1);

    int divider = arr[(max_idx + min_idx) / 2];

    int lo = start;
    int hi = end;
    int flag = 0;

    while (1)
    {
        while (arr[hi] >= divider)
        {
            hi--;
            if (hi <= lo)
            {
                break;
            }
        }

        if (hi <= lo)
        {
            arr[lo] = divider;
            break;
        }

        arr[lo] = arr[hi];

        lo++;

        while (arr[lo] < divider)
        {
            lo++;
            if (lo >= hi)
            {
                flag = 1;
                break;
            }
        }

        if (flag) break;

        if (lo >= hi)
        {
            lo = hi;
            arr[hi] = divider;
            flag = 1;
        }
        if (flag) break;

        arr[hi] = arr[lo];
    }

    quick_sort(arr, start, lo - 1);
    quick_sort(arr, lo + 1, end);
}