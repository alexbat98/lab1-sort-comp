//
// Created by Александр Баташев on 02.12.16.
//

#ifndef LAB1_SOT_COMP_ALGORITHMS_H
#define LAB1_SOT_COMP_ALGORITHMS_H

void bubble_sort(int *arr, int n);
void better_bubble_sort(int *arr, int n);
void shell_sort(int *arr, int n);
void selection_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
//void merge_sort(int *arr, int *scratch, int start, int end);
void quick_sort(int *arr, int start, int end, int counter);
void improved_selection_sort(int *arr, int n);
void merge(int *arr, int n, int *scratch, int size, int start);
void merge_sort(int *arr, int n);

#endif //LAB1_SOT_COMP_ALGORITHMS_H
