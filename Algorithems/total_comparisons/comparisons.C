#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// #define DEBUG
#define COUNT 10000

typedef struct _node {
    int x;
} Node;

typedef struct _list {
    Node *node;
} List;


void printlist(List *list)
{
    printf("====== List ======\n");
    for(int i = 0; i < COUNT; i++) {
        printf("data %d = %d\n", i, (list + i)->node->x);
    }
}

List *initialize()
{
    List *list = (List *)malloc(sizeof(List) * COUNT);

    FILE *file;
    file = fopen("data.txt", "r");
    for(int i = 0; i < COUNT; i++) {
        (list + i)->node = (Node *)malloc(sizeof(Node));
        fscanf(file, "%d", &(list + i)->node->x);
    }
    return list;
}

void swap(List *list, int i, int j)
{
    Node *tmp = (list + i)->node;
    (list + i)->node = (list + j)->node;
    (list + j)->node = tmp;
}

int comparisonLastElementAsThePivot(List *list, int start, int end)
{

    int comparisonCount = 0 ;
    if (start < end) {
        int j = start + 1;
        // Pick a pivot
        swap(list, start, end - 1);
        Node *pivot = (list + start)->node;
        // Number of comparisons
        comparisonCount = end - start - 1;
        // printf("Comparison = %d \n", comparisonCount);
        for(int i = start + 1; i < end; i++) {
            if ((list + i)->node->x < pivot->x) {
                swap(list, i, j);
                j++;
            }
        }
        // put the pivot at the right place
        // pivot is at start
        // j has the first big element than pivot
        swap(list, start, j - 1);
        comparisonCount += comparisonLastElementAsThePivot(list, start, j - 2);
        comparisonCount += comparisonLastElementAsThePivot(list, j, end);
    }

    return comparisonCount;

}

int comparisonFirstElementAsThePivot(List *list, int start, int end)
{
    int comparisonCount;
    if (start < end) {
        int j = start + 1;
        // Pick a pivot
        Node *pivot = (list + start)->node;
        // Number of comparisons
        comparisonCount = end - start - 1;
        // printf("Comparison = %d \n", comparisonCount);
        for(int i = start + 1; i < end; i++) {
            if ((list + i)->node->x < pivot->x) {
                swap(list, i, j);
                j++;
            }
        }
        // put the pivot at the right place
        // pivot is at start
        // j has the first big element than pivot
        swap(list, start, j - 1);
        comparisonCount += comparisonFirstElementAsThePivot(list, start, j - 2);
        comparisonCount += comparisonFirstElementAsThePivot(list, j, end);
    }
    return comparisonCount;
}

int comparisonMedianElementAsThePivot(List *list, int start, int end)
{
    int comparisonCount;

    if (start < end) {
        // calculate the median
        int median = start + (end - start)/2;
        // get the pivot
        // printf("start = %d, end = %d, median = %d\n", start, end, median);
        Node *tmp = (list + median)->node;
        //swap start pivot with the median
        swap(list, start, median);
        int j = start + 1;
        for (int i = start + 1; i < (end + 1); i++) {
            if ((list + i)->node->x < tmp->x) {
                swap(list, i, j);
                j++;
            }
        }
        swap(list, start, j - 1);
        comparisonCount += comparisonMedianElementAsThePivot(list, start, j - 2);
        comparisonCount += comparisonMedianElementAsThePivot(list, j, end);
    }

    return comparisonCount;

}

int main()
{
    clock_t begin, end;
    List *list = initialize();

    printf(" (1) Comparison, first element as the pivot\n");
    printf(" (2) Comparison, last element as the pivot\n");
    printf(" (3) Comparison, median element as the pivot\n");
    printf("Choise [1][2][3] : ");

    char ch = getchar();

    switch (ch) {
        case '1':
            begin = clock();
            printf(
                   "Comparison count = %d\n",
                   comparisonFirstElementAsThePivot(list, 0, COUNT)
                );
            end = clock();
            printf("Time took %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
            break;
        case '2':
            begin = clock();
            printf(
                   "comparison count = %d\n",
                   comparisonLastElementAsThePivot(list, 0, COUNT)
                );
            end = clock();
            printf("Time took %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
            break;
        case '3':
            begin = clock();
            printf(
                   "Comparison count = %d\n",
                   comparisonMedianElementAsThePivot(list, 0, COUNT - 1)
                );
            end = clock();
            printf("Time took %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
            break;
    }

    #ifdef DEBUG
        printlist(list);
    #endif

    return 0;
}
