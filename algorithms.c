//
// Created by Александр Баташев on 02.12.16.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
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
 * Алгоритм слияния двух упорядоченных массивов
 * @param scratch Массив, содержащий два упорядоченных подмассива
 * @param scratch_size Размер массива scratch
 * @param part_size Размер первого подмассива
 * @param arr Массив, в который необходимо поместить результат
 * @param start Начальный индекс в массиве arr
 */
//void merge(int * scratch, int scratch_size, int part_size, int *arr, int start)
//{
//
//    int right_idx = part_size;
//    int left_idx = 0;
//    int mid_idx = part_size;
//    int count = 0;
//
//    // Слияние
//    while ((left_idx < mid_idx) && (right_idx < scratch_size))
//    {
//        if (scratch[left_idx] <= scratch[right_idx])
//        {
//            arr[start + count] = scratch[left_idx++];
//            count++;
//        } else
//        {
//            arr[start + count] = scratch[right_idx++];
//            count++;
//        }
//    }
//
//    // Дописываем оставшиеся элементы
//    for (; left_idx < mid_idx; ++left_idx)
//    {
//        arr[start + count] = scratch[left_idx];
//        count++;
//    }
//
//    for (; right_idx < scratch_size; ++right_idx)
//    {
//        arr[start + count] = scratch[right_idx];
//        count++;
//    }
//}

void merge(int *arr, int n, int *scratch, int size, int start)
{
    int i;
    int left_idx = start;
    int right_idx = start + size;
    int mid_point = right_idx;
    int end = start + size * 2;
    if (n - end < size)
    {
        end = n;
    }
    int scratch_idx = left_idx;
    while ((left_idx < mid_point) && (right_idx < end))
    {
        if (arr[left_idx] <= arr[right_idx])
        {
            scratch[scratch_idx++] = arr[left_idx++];
        } else
        {
            scratch[scratch_idx++] = arr[right_idx++];
        }
    }

    for (i = left_idx; i < mid_point; i++)
    {
        scratch[scratch_idx++] = arr[i];
    }

    for (i = right_idx; i < end; ++i)
    {
        scratch[scratch_idx++] = arr[i];
    }

    for (i = start; i < end; i++)
    {
        arr[i] = scratch[i];
    }
}

/**
 * Сортировка слиянием
 * @param arr Исходный массив
 * @param n Количество элементов
 */
void merge_sort(int *arr, int n)
{

    int start = 0;
    int size = 0;

    int *scratch = (int *) calloc((size_t) n, sizeof(int));

    for (size = 1; size < n; size *= 2)
    {
        for (start = 0; start + size < n; start += size * 2)
        {
            // Слияние
            merge(arr, n, scratch, size, start);

        }
    }

    free(scratch);
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

void improved_selection_sort(int *arr, int n)
{
    const int split = 2;
    int * mins = (int *) calloc((size_t) n*2, sizeof(int));
    int mins_count = 0;
    int i, j, min_idx, delta, t, incr;

    for (i = 0; i < n / split; ++i)
    {
        mins[mins_count++] = min(arr + i * split, split);
    }

    if (n - (n / split) * split > 0)
    {
        for (i = (n / split) * split; i < n; ++i)
        {
            mins[mins_count++] = i;
        }
    }

    for (i = 0; i < n; i++)
    {
        min_idx = 0;
        for (j = 1; j < mins_count; j++)
        {
            if (arr[mins[j]] > arr[mins[min_idx]])
            {
                min_idx = j;
            }
        }

        // переформатируем массив минимальных
        delta = (mins[min_idx] / split) * split;
        t = mins[min_idx];
        incr = split;
        if (t == delta)
        {
            delta++;
            incr--;
        }

        mins[min_idx] = delta;
        for (j = delta; j < delta + incr; j++)
        {
            mins[mins_count++] = j;
        }

        arr[t] ^= arr[i];
        arr[i] ^= arr[t];
        arr[t] ^= arr[i];
    }

    free(mins);
}