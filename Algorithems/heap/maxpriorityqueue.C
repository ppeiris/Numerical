#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int x;
} Node;


typedef struct _list {
    Node *data;
} List;

#define RCOUNT 10

void printlist(List *list, int *length)
{
    for (int i = 0; i < *length; i++) {
        printf("%d ", (list +i)->data->x);
    }
    printf("\n");
}

int left(int i)
{
    return (2 * i) + 1;
}

int right(int i)
{
    return (2 * i) + 2;
}

int parent(int i)
{
    return i/2;
}

void swap(List *list, int i, int j)
{
    Node *tmp = (list + i)->data;
    (list + i)->data = (list + j)->data;
    (list + j)->data = tmp;
}

void heapify(List *list, int root, int length)
{
    int l = left(root);
    int r = right(root);
    int max;

    if (length > l && (list + root)->data->x < (list + l)->data->x) {
        max = l;
    } else {
        max = root;
    }

    if (length > r && (list + r)->data->x > (list + max)->data->x) {
        max = r;
    }

    if (root != max) {
        swap(list, root, max);
        heapify(list, max, length);
    }

}

void maxheapify(List *list, int length)
{
    for (int i = length/2; i > -1; i--) {
        heapify(list, i, length);
    }
}

int heapmaximum(List *list)
{
    return (list + 0)->data->x;
}

/**
 * Extract the max node from the heap (the first element in the array)
 * rearrage the heap
 */
Node *extractmax(List *list, int *length)
{
    Node *_max = (list + 0)->data;
    (list + 0)->data = (list + ((*length) - 1))->data;
    (*length)--;
    heapify(list, 0, *length);
    return _max;
}

/**
 * Increase the value of one of the node and re-arrange it in the heap
 * parent Node of i is given by i/2
 */
void heap_increase_key(List *list, int i, int value)
{

    if (value < (list + i)->data->x) {
        printf("Value is smaller than the current value\n");
        return;
    }

    (list + i)->data->x = value;

    // int parent_index = i/2;

    while (i > 0 && (list + i/2)->data->x < value) {
        // swap i/2 and i
        swap(list, i/2, i);
        i = i/2;
    }
}

int main()
{
    FILE *file = fopen("IntegerArray.txt", "r");
    int num = 10;
    int *rcount = &num;

    List *list = (List *)malloc(sizeof(List) * (*rcount));

    for (int i = 0; i < *rcount; i++) {
        (list + i)->data = (Node *)malloc(sizeof(Node));
        fscanf(file, "%d", &(list + i)->data->x);
    }

    printlist(list, rcount);
    maxheapify(list, *rcount);
    printlist(list, rcount);

    printf("heap maximum = %d\n", heapmaximum(list));
    Node *maxNode = extractmax(list, rcount);
    printf("extract max = %d\n", maxNode->x);
    printlist(list, rcount);

    maxNode = extractmax(list, rcount);
    printf("extract max = %d\n", maxNode->x);
    printlist(list, rcount);

    /* Increase the value of a given node and reposision it */
    heap_increase_key(list, 9, 60000);
    printlist(list, rcount);


    return 0;
}
