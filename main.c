//
// Created by Александр Баташев on 01.12.16.
//
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <memory.h>
#include <time.h>

//#define N 30000
//
//void bubble_sort(int *a, int length)
//{
//    int swapped;
//    for (int i = 0; i < length-1; i++) {
//        swapped = 0;
//        for (int j = 0; j < length-i-1; j++) {
//            if (a[j] > a[j+1]) {
//                a[j] ^= a[j+1];
//                a[j+1] ^= a[j];
//                a[j] ^= a[j+1];
//                swapped = 1;
//            }
//        }
//
//        if(!swapped)
//            break;
//    }
//}
//
//void insert_sort(int * a, int length)
//{
//    int ne, location;
//
//    for (int i = 1; i < length; i++)
//    {
//        ne = a[i];
//        location = i - 1;
//        while(location >= 0 && a[location] > ne)
//        {
//            a[location+1] = a[location];
//            location = location - 1;
//        }
//        a[location+1] = ne;
//    }
//}
//
//int min(int * a, int length)
//{
//    int minPos = 0;
//    int i;
//    for (i = 0; i < length; ++i) {
//        if (a[i] < a[minPos])
//            minPos = i;
//    }
//
//    return minPos;
//}
//
//void selection_sort(int * a, int length)
//{
//    int i;
//
//    for (i = 0; i < length; ++i) {
//        int minPos = i + min(a + i, length - i);
//        a[i] ^= a[minPos];
//        a[minPos] ^= a[i];
//        a[i] ^= a[minPos];
//    }
//}
//
//int* merge_sort(int *up, int *down, unsigned int left, unsigned int right)
//{
//    if (left == right)
//    {
//        down[left] = up[left];
//        return down;
//    }
//
//    unsigned int middle = (unsigned int)((left + right) * 0.5);
//
//    // разделяй и сортируй
//    int *l_buff = merge_sort(up, down, left, middle);
//    int *r_buff = merge_sort(up, down, middle + 1, right);
//
//    // слияние двух отсортированных половин
//    int *target = l_buff == up ? down : up;
//
//    unsigned int width = right - left, l_cur = left, r_cur = middle + 1;
//    for (unsigned int i = left; i <= right; i++)
//    {
//        if (l_cur <= middle && r_cur <= right)
//        {
//            if (l_buff[l_cur] < r_buff[r_cur])
//            {
//                target[i] = l_buff[l_cur];
//                l_cur++;
//            }
//            else
//            {
//                target[i] = r_buff[r_cur];
//                r_cur++;
//            }
//        }
//        else if (l_cur <= middle)
//        {
//            target[i] = l_buff[l_cur];
//            l_cur++;
//        }
//        else
//        {
//            target[i] = r_buff[r_cur];
//            r_cur++;
//        }
//    }
//    return target;
//}
//
//void quick_sort(int * a, int l, int r)
//{
//    int x = a[l + (r - l) / 2];
//    //запись эквивалентна (l+r)/2,
//    //но не вызввает переполнения на больших данных
//    int i = l;
//    int j = r;
//    //код в while обычно выносят в процедуру particle
//    while(i <= j)
//    {
//        while(a[i] < x) i++;
//        while(a[j] > x) j--;
//        if(i <= j)
//        {
//            a[i] ^= a[j];
//            a[j] ^= a[i];
//            a[i] ^= a[j];
//            i++;
//            j--;
//        }
//    }
//    if (i<r)
//        quick_sort(a, i, r);
//
//    if (l<j)
//        quick_sort(a, l, j);
//}

int main()
{
    setlocale(LC_ALL, "");

    printf("Сравнение алгоритмов сортировки\n");

//    srand(31321);
//
//    int *randNumbers = (int *) calloc(N, sizeof(int));
//    int *worstScenario = (int *) calloc(N, sizeof(int));
//
//    int i;
//
//    for (i = 0; i < N; ++i) {
//        randNumbers[i] = rand();
//        worstScenario[i] = N - i;
//    }
//
//    int *sortableSet = (int *) calloc(N, sizeof(int));
//
//    // Тест Пузырьковой сортировки
//    // 1) Случайные числа
//    memcpy(sortableSet, randNumbers, N * sizeof(int));
//
//    clock_t startTime = clock();
//    bubble_sort(sortableSet, N);
//    clock_t endTime = clock();
//
//    float result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    // 2) Случайные числа
//    printf("%f\n", result);
//
//    memcpy(sortableSet, worstScenario, N * sizeof(int));
//
//    startTime = clock();
//    bubble_sort(sortableSet, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//    // Конец теста Пузырьковой сортировки
//
//    //Тест Сортировки вставками
//    memcpy(sortableSet, randNumbers, N * sizeof(int));
//
//    startTime = clock();
//    insert_sort(sortableSet, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//
//    memcpy(sortableSet, worstScenario, N * sizeof(int));
//
//    startTime = clock();
//    insert_sort(sortableSet, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//    // Конец теста Сортировки вставками
//
//
//
//
//
//    // Тест Сортировки выбором
//    memcpy(sortableSet, randNumbers, N * sizeof(int));
//
//    startTime = clock();
//    selection_sort(sortableSet, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//
//
//    memcpy(sortableSet, worstScenario, N * sizeof(int));
//
//    startTime = clock();
//    selection_sort(sortableSet, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//    // Конец теста Сортировки выбором
//
//
//
//
//
//    // Тест Сортировки слиянием
//
//    memcpy(sortableSet, randNumbers, N * sizeof(int));
//    startTime = clock();
//    int *mem = (int *) calloc(N, sizeof(int));
//    merge_sort(sortableSet, mem, 0, N);
//    endTime = clock();
//    free(mem);
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//
//    memcpy(sortableSet, worstScenario, N * sizeof(int));
//    startTime = clock();
//    mem = (int *) calloc(N, sizeof(int));
//    merge_sort(sortableSet, mem, 0, N);
//    endTime = clock();
//    free(mem);
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//    // Конец теста сортировки слиянием
//
//
//
//
//
//    // Тест Быстрой сортировки
//    memcpy(sortableSet, randNumbers, N * sizeof(int));
//    startTime = clock();
//    quick_sort(sortableSet, 0, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//
//    memcpy(sortableSet, worstScenario, N * sizeof(int));
//    startTime = clock();
//    quick_sort(sortableSet, 0, N);
//    endTime = clock();
//
//    result = (float)(endTime - startTime) / CLOCKS_PER_SEC;
//
//    printf("%f\n", result);
//    //Конец теста быстрой сортировки

    return 0;
}