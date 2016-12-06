//
// Created by alexb on 06.12.2016.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *f;
    if ((f = fopen("array.dat", "wt")) == NULL)
    {
        printf("Error");
        exit(1);
    }
    int i;
    int a = 0;
    for (i = 1; i <= 1000000; i++)
    {
        if (i % 100 == 0)
            a += 100;

        fprintf(f, "%d ", rand() % 100 + a);
    }

    fclose(f);
}