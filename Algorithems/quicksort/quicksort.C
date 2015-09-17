#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

#define N 10

List *initialize()
{
    FILE *file = fopen("IntegerArray.txt", "r");
    List *list = (List *)malloc(sizeof(list) * N);

    for (int i = 0; i < N; i++) {
        (list + i)->point = (Point *)malloc(sizeof(Point));
        printf("---------\n");
        fscanf(file, "%d", &(list + i)->point->x);
    }


    return list;
}

int main()
{
    List *list;
    list = initialize();

    return 0;
}
