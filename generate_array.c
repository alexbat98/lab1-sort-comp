//
// Created by alexb on 06.12.2016.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define N 300000

int main()
{

    FILE *f;
    if ((f = fopen("array.dat", "wt")) == NULL)
    {
        printf("Error");
        exit(1);
    }
    int i;
    int a = 0, number;

    char * cache = calloc(N, sizeof(char));
    memset(cache, 0, N);

    srand(time(0));

    for (i = 1; i <= N; i++)
    {

        do {
            number = rand() % 100 + a;
        } while(cache[number]);

        cache[number] = 1;

        if (i % 100 == 0)
            a += 100;

        fprintf(f, "%d ", number);
    }

    fclose(f);
}