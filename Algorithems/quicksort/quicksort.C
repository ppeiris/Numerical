#include <stdio.h>
#include <stdlib.h>
#include "qsort.h"

#define N 10
#define DEBUG
void displayList(DataList *list)
{
    printf("\n ====== Display list ===============\n");
    printf("[");
    for (int i = 0; i < N; i++) {
        printf(" %d ", (list + i)->datapoint->x);
    }
    printf("]\n =================================== \n");
}

void displayPoint(Point *p)
{
    printf("\n ====== Display Point ==============\n");
    printf("[%d]\n", p->x);
    printf("===================================\n");
}

DataList *initialize()
{
    FILE *file = fopen("points.txt", "r");
    // FILE *file = fopen("IntegerArray.txt", "r");
    DataList *list = (DataList *)malloc(sizeof(DataList) * N);

    for (int i = 0; i < N; i++) {
        (list + i)->datapoint = (Point *)malloc(sizeof(Point));
        fscanf(file, "%d", &(list + i)->datapoint->x);
    }

    return list;
}

void solveit(DataList *list, int start, int mid, int end)
{
    // pic the pivot
    Point *pivot = (list + start)->datapoint;

    displayPoint(pivot);

    int i = start + 1;
    for(int j = i + 1; j < end; j++) {
        if ((list + j)->datapoint->x < pivot->x) {
            Point *tmpPoint = (list + i)->datapoint;
            (list + i)->datapoint = (list + j)->datapoint;
            (list + j)->datapoint = tmpPoint;
            i++;
            tmpPoint = NULL;
            free(tmpPoint);
        }
    }

    // Switch the pivot
    (list + start)->datapoint = (list + (i - 1))->datapoint;
    (list + (i - 1))->datapoint = pivot;
    pivot = NULL;
    free(pivot);
}

void qsort(DataList *list, int start, int end)
{
    if ((end - start + 1) < 2) {
        int mid = start + (end - start)/2;
        qsort(list, start, mid);
        qsort(list, mid + 1, end);
        solveit(list, start, mid, end);
    }
}

int main()
{
    DataList *list = initialize();


    #ifdef DEBUG
        displayList(list);
    #endif

    // solveit(list, 0, 4, 9);
    qsort(list, 0, N - 1);

    #ifdef DEBUG
        displayList(list);
    #endif

    return 0;
}
