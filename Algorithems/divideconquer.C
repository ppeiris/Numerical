/* C program for merge sort */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int count = 0;


void printData(int *read, int count)
{
  for(int i = 0; i < count; i++) {
    printf("Address [%p] = %d\n", (read + i),*(read + i));
  }
}


/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // printf("...........................Sorting --- [%d] to [%d] \n", l, r);
    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    printf("left >> \n ");
    printData(L, n1);
    printf("right >> \n ");
    printData(R, n2);
    printf("==============\n");
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

     // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void printMap(int big, int start, int end, int final, int b)
{
    printf("[");

    for(int i = big; i < start; i++) {
        printf(" . ");
    }
    for (int i = start; i < end; i++) {
        if (b) {
            printf(" 0 ");
        } else {
            printf(" 1 ");
        }
    }
    for(int i = end; i < final; i++) {
        printf(" . ");
    }
    printf("]\n");
}


/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h

        // printf("> start [%d] end [%d]\n", l, r);
        // printMap(0, l, r, 9, 0);
        mergeSort(arr, l, m);
        // printf(">> mid [%d] end [%d]\n", m + 1, r);
        // printMap(0, m+1, r, 9, 1);
        mergeSort(arr, m+1, r);


        // printf("Sorting\n");
        // printMap(0, l, r, 9, 1);
        merge(arr, l, m, r);

    } else {
        // printf(">> start [%d] end [%d]\n", l, r);
        // printMap(0, l, r, 9, 0);
    }
}


/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int count = 10;
    FILE *file;
    // file = fopen("IntegerArray.txt", "r");
    file = fopen("smallNumbers.txt", "r");

    int arr[count];// = {4,8,1,20,13,2,11,7,19,15};

    for(int i = 0; i < count; i++) {
        fscanf(file, "%d", &arr[i]);
    }


    int arr_size = sizeof(arr)/sizeof(arr[0]);

    // printf("Given array is \n");
    // printArray(arr, arr_size);

    // printf("%0*d\n", 20, 0);
    mergeSort(arr, 0, arr_size - 1);

    // printf("\nSorted array is \n");
    // printArray(arr, arr_size);


    for (int i = 1; i < count; i++) {
        if (arr[i] < arr[i-1]) {
            printf("ERROR");
        }
    }
    return 0;
}
