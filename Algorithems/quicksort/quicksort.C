/*********************************************************

    This algorithem sort the fiven integer data using
    quick sort algorithem.

    Bruteforce algorithem using to check the accuracy of
    the algorithem

    Prabath Peiris.

*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "qsort.h"

#define N 100000
// #define DEBUG

/*************************************
    Display the list of data
*************************************/
void displayList(DataList *list)
{
    printf("\n ====== Display list ===============\n");
    printf("[");
    for (int i = 0; i < N; i++) {
        printf(" %d ", (list + i)->datapoint->x);
    }
    printf("]\n =================================== \n");
}


/*********************************************************
    Load the data from the file and build the data list
*********************************************************/
DataList *initialize()
{
    // FILE *file = fopen("points.txt", "r");
    FILE *file = fopen("IntegerArray.txt", "r");
    DataList *list = (DataList *)malloc(sizeof(DataList) * N);

    for (int i = 0; i < N; i++) {
        (list + i)->datapoint = (Point *)malloc(sizeof(Point));
        fscanf(file, "%d", &(list + i)->datapoint->x);
    }

    return list;
}

void swap(DataList *list, int i, int j)
{
    Point *tmpP = (list + i)->datapoint;
    (list + i)->datapoint = (list + j)->datapoint;
    (list + j)->datapoint = tmpP;
    tmpP = NULL;
    free(tmpP);
}


/*************************************************************
    quick sort with moving the pivot to the end of the array
*************************************************************/
void quicksort(DataList *list, int left, int right)
{
    if (left < right) {
        int pivot_index = left;
        int j = left;
        Point *pivot = (Point *)malloc(sizeof(Point));
        pivot = (list + pivot_index)->datapoint;
        swap(list, pivot_index, right);

        for (int i = left; i < right; i++) {
            if ((list + i)->datapoint->x < pivot->x) {
                swap(list, i, j);
                j++;
            }
        }

        swap(list, j, right);
        quicksort(list, left, j - 1);
        quicksort(list, j + 1, right);

        pivot = NULL;
        free(pivot);
    }
}

/**********************************************
    Brute force to cehck if the list is sorted
**********************************************/
void errorCheck(DataList *list)
{
    for (int i = 1; i < N; i++) {
        if ((list + i)->datapoint->x < (list + i - 1)->datapoint->x) {
            printf("ERROR >>>>>>>>>>>>>> (%d %d)\n", i, i-1);
        }
    }
}

/*****************************************************
    Keep the pivot at the start of the array
******************************************************/
void sort(DataList *list, int start, int end)
{
   if (start < end) {
    Point *pivot = (list + start)->datapoint;
    int j = start + 1;
    for(int i = start + 1; i < (end + 1); i++) {
        if ((list + i)->datapoint->x < pivot->x) {
            swap(list, i, j);
            j++;
        }
    }
    pivot = NULL;
    free(pivot);
    swap(list, j - 1, start);
    sort(list, start, j - 2);
    sort(list, j, end);
   }
}


int main()
{
    clock_t begin, end;
    DataList *list = initialize();

    #ifdef DEBUG
        displayList(list);
    #endif
    begin = clock();

    // Quick sort (move the pivot to the end of the array)
    quicksort(list, 0, N - 1);
    // Quick sort (leave the pivot at the beginning of the array)
    // sort(list, 0, N - 1);

    end = clock();
    #ifdef DEBUG
        displayList(list);
    #endif
    errorCheck(list);
    double time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time spend sorting %d number of data took %f second\n", N, time_spend);
    return 0;
}
