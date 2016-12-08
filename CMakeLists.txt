cmake_minimum_required(VERSION 3.6)
project(lab1_sort_comp)

#set(CMAKE_CXX_STANDARD 11

set(SOURCE_FILES main.c algorithms.c algorithms.h utils.c utils.h)
add_executable(lab1_sort_comp ${SOURCE_FILES})

add_executable(test_bubble_sort algorithms.c tests/test_bubble_sort.c utils.c utils.h)
add_executable(test_better_bubble_sort algorithms.c tests/test_better_bubble_sort.c utils.c utils.h)
add_executable(test_shell_sort algorithms.c tests/test_shell_sort.c utils.c utils.h)
add_executable(test_selection_sort algorithms.c tests/test_selection_sort.c utils.c utils.h)
add_executable(test_insertion_sort algorithms.c tests/test_insertion_sort.c utils.c utils.h)
add_executable(test_merge_sort algorithms.c tests/test_merge_sort.c utils.c utils.h)
add_executable(test_quick_sort algorithms.c tests/test_quick_sort.c utils.c utils.h)

add_executable(generate_array generate_array.c)