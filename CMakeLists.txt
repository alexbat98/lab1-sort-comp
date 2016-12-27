cmake_minimum_required(VERSION 3.6)
project(lab1_sort_comp)

#set(CMAKE_CXX_STANDARD 11

set(SOURCE_FILES src/main.c src/algorithms.c src/algorithms.h src/utils.c src/utils.h)
add_executable(lab1_sort_comp ${SOURCE_FILES})

add_executable(test_bubble_sort src/algorithms.c tests/test_bubble_sort.c src/utils.c src/utils.h)
add_executable(test_better_bubble_sort src/algorithms.c tests/test_better_bubble_sort.c src/utils.c src/utils.h)
add_executable(test_shell_sort src/algorithms.c tests/test_shell_sort.c src/utils.c src/utils.h)
add_executable(test_selection_sort src/algorithms.c tests/test_selection_sort.c src/utils.c src/utils.h)
add_executable(test_improved_selection_sort src/algorithms.c tests/test_improved_selection_sort.c src/utils.c src/utils.h)
add_executable(test_insertion_sort src/algorithms.c tests/test_insertion_sort.c src/utils.c src/utils.h)
add_executable(test_merge_sort src/algorithms.c tests/test_merge_sort.c src/utils.c src/utils.h)
add_executable(test_merge src/algorithms.c tests/test_merge.c src/utils.c src/utils.h)
add_executable(test_quick_sort src/algorithms.c tests/test_quick_sort.c src/utils.c src/utils.h)

add_executable(generate_array generate_array.c)