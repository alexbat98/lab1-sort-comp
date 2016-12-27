//
// Created by Александр Баташев on 01.12.16.
//
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <time.h>

#ifdef OS_WINDOWS
    #include <windows.h>
#else
    #include <ncurses.h>
    #include <menu.h>
#include <locale.h>

#endif

#include "utils.h"
#include "algorithms.h"

int N;
//#define N 300000

#ifdef OS_WINDOWS
int chooseMenu(char *name[], int np)
{
    int bestnumber=0;
    int i;
    char code;
    system("color 17");
    do
    {
        system("cls");
        for(i=0;i<np;i++)
        {
            if(i!=bestnumber)
            {printf("%s\n",name[i]);
            }
            else
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, (WORD) ((7 << 4) | 1));
                printf("%s\n",name[i]);
                SetConsoleTextAttribute(hConsole, (WORD) ((1 << 4) | 7));

            }
        }
        code=getch();
        if(code==(char)0) code=getch();
        if(code==72)
        {
            bestnumber--;
            if(bestnumber<0) bestnumber=np-1;
        }
        else
        {if(code==80)
            {bestnumber++;
                if(bestnumber>=np) bestnumber=0;
            }
        }
    }while(code!=13);
    return bestnumber;
}
#else
int chooseMenu(char ** name, int np)
{
#ifdef OS_WINDOWS
    system("cls");
#else
    system("clear");
#endif

    ITEM **my_items;
    MENU *my_menu;
    int i;
    int selected = 0;

    reset_prog_mode();
    refresh();

    keypad(stdscr, TRUE);

    clear();

    init_pair(1, COLOR_BLUE, COLOR_WHITE);
//    wattron(stdscr, COLOR_PAIR(2));

    my_items = (ITEM **) calloc((size_t) (np+1), sizeof(ITEM *));
    for (i = 0; i < np; ++i)
    {
        my_items[i] = new_item(name[i], "");
    }

    my_items[np] = (ITEM *) NULL;
    my_menu = new_menu((ITEM **) my_items);
    set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
    set_menu_back(my_menu, COLOR_PAIR(1));
    set_menu_grey(my_menu, COLOR_PAIR(1));
    wbkgd(stdscr, COLOR_PAIR(1));
    post_menu(my_menu);
    refresh();

    int code;

    do
    {
        code = wgetch(stdscr);
        switch (code)
        {
            case KEY_DOWN:
                menu_driver(my_menu, REQ_DOWN_ITEM);
                selected++;
                if (selected >= np) {
                    selected = 0;
                    menu_driver(my_menu, REQ_FIRST_ITEM);
                }
                break;
            case KEY_UP:
                menu_driver(my_menu, REQ_UP_ITEM);
                selected--;
                if (selected < 0) {
                    selected = np-1;
                    menu_driver(my_menu, REQ_LAST_ITEM);
                }
                break;
            default:
                break;
        }
    } while (code != 10);

    for (i = 0; i < np; ++i) {
        free_item(my_items[i]);
    }
    free_menu(my_menu);

    def_prog_mode();
    endwin();

    return selected;
}

#endif

int * original_arr;
int * working_arr;

void runBubbleTest()
{
    clock_t start, end;
    float res;
    char check_flag;
// Тестирование классического пузырька

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    bubble_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%15.3f%20c\n", "Классический пузырек", res, check_flag);

    // Конец тестирования классического пузырька

}

void runCocktailTest()
{
    clock_t start, end;
    float res;
    char check_flag;
// Тестирование улучшенного пузырька

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    better_bubble_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%13.3f%20c\n", "Улучшенный пузырек", res, check_flag);

    // Конец тестирования улучшенного пузырька

}

void runShellTest()
{
    clock_t start, end;
    float res;
    char check_flag;
// Тестирование сортировки Шелла

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    shell_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%11.3f%20c\n", "Сортировка Шелла", res, check_flag);

    // Конец тестирования Сортировки Шелла

}

void runInsertionTest()
{
    clock_t start, end;
    float res;
    char check_flag;
// Тестирование сортировки вставками

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    insertion_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%15.3f%20c\n", "Сортировка вставками", res, check_flag);

    // Конец тестирования Сортировки вставками

}

void runMergeTest()
{
    clock_t start, end;
    float res;
    char check_flag;
// Тестирование сортировки слиянием

    memcpy(working_arr, original_arr, N * sizeof(int));
    int *scratch = (int *) calloc(N, sizeof(int));

    start = clock();
    merge_sort(working_arr, N);
    end = clock();

    free(scratch);

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%14.3f%20c\n", "Сортировка слиянием", res, check_flag);

    // Конец тестирования Сортировки слиянием

}

void runSelectionTest()
{
    clock_t start, end;
    float res;
    char check_flag;
// Тестирование сортировки выбором

    memcpy(working_arr, original_arr, N * sizeof(int));

    start = clock();
    selection_sort(working_arr, N);
    end = clock();

    if (check_sort_order(working_arr, N))
    {
        check_flag = '-';
    } else
    {
        check_flag = '+';
    }

    res = (float)(end - start) / CLOCKS_PER_SEC;

    printf("%-64s%13.3f%20c\n", "Сортировка выбором", res, check_flag);

    // Конец тестирования Сортировки выбором

}

const char* tests[] = {
        "Все тесты",
        "Пузырьковая сортировка",
        "Шейкерная (двунаправленная) сортировка",
        "Сортировка Шелла",
        "Сортировка выбором",
        "Сортировка вставками",
        "Сортировка слиянием"
};

const int tests_count = 7;

const char* files[] = {
        "30 000 элементов (частично упоряд)",
        "50 000 элементов (частично упоряд)",
        "100 000 элементов (частично упоряд)",
        "150 000 элементов (частично упоряд)",
        "200 000 элементов (частично упоряд)",
        "300 000 элементов (частично упоряд)",
        "30 000 элементов (случайный)",
        "50 000 элементов (случайный)",
        "100 000 элементов (случайный)",
        "150 000 элементов (случайный)",
        "200 000 элементов (случайный)",
        "300 000 элементов (случайный)",
        "Выход"
};

const int files_count = 13;

void initScreen()
{
    initscr();
    cbreak();
    noecho();
    start_color();
}

int main()
{
    setlocale(LC_ALL, "");
    printf("Сравнение алгоритмов сортировки\n\n");

    FILE *fp;
    int i;

    int k;

    initScreen();

    k = chooseMenu((char **) files, files_count);


    switch (k)
    {
        case 0:
            fp = fopen("samples/30k_p.dat", "r");
            N = 30000;
            break;
        case 1:
            fp = fopen("samples/50k_p.dat", "r");
            N = 50000;
            break;
        case 2:
            fp = fopen("samples/100k_p.dat", "r");
            N = 100000;
            break;
        case 3:
            fp = fopen("samples/150k_p.dat", "r");
            N = 150000;
            break;
        case 4:
            fp = fopen("samples/200k_p.dat", "r");
            N = 200000;
            break;
        case 5:
            fp = fopen("samples/300k_p.dat", "r");
            N = 300000;
            break;
        case 6:
            fp = fopen("samples/30k_r.dat", "r");
            N = 30000;
            break;
        case 7:
            fp = fopen("samples/50k_r.dat", "r");
            N = 50000;
            break;
        case 8:
            fp = fopen("samples/100k_r.dat", "r");
            N = 100000;
            break;
        case 9:
            fp = fopen("samples/150k_r.dat", "r");
            N = 150000;
            break;
        case 10:
            fp = fopen("samples/200k_r.dat", "r");
            N = 200000;
            break;
        case 11:
            fp = fopen("samples/300k_r.dat", "r");
            N = 300000;
            break;
        case 12:
            exit(0);
        default:
            printf("Unexpected error");
            exit(1);
    }

    original_arr = (int *) calloc(N, sizeof(int));

    for (i = 0; i < N; ++i)
    {
        fscanf(fp, "%d", &original_arr[i]);
    }

    fclose(fp);

    working_arr = (int *) calloc(N, sizeof(int));

    printf("%-64s%18s%38s\n", "Название алгоритма", "Время", "Корректность");

    k = chooseMenu((char **) tests, tests_count);

    setvbuf(stdout, NULL, _IOLBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    switch (k)
    {
        case 0:
            runBubbleTest();
            runCocktailTest();
            runShellTest();
            runInsertionTest();
            runMergeTest();
            runSelectionTest();
            break;
        case 1:
            runBubbleTest();
            break;
        case 2:
            runCocktailTest();
            break;
        case 3:
            runShellTest();
            break;
        case 4:
            runSelectionTest();
            break;
        case 5:
            runInsertionTest();
            break;
        case 6:
            runMergeTest();
            break;
        default:
            exit(1);
    }

    printf("Нажмите любую клавишу, чтобы продолжить...");
    wgetch(stdscr);

    endwin();

#ifdef OS_WINDOWS
    system("cls");
#else
    system("clear");
#endif

    return 0;
}