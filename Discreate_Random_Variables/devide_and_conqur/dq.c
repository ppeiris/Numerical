// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <time.h>

// void merge(int *A, int min, int mid, int max) {

//     printf("%d %d %d \n",min, mid, max );



// }

// void sort(int *A, int min, int max) {

//     // for (int i = 0; i < 12; i++)
//     // {
//     //     printf("%d\n", A[i]);
//     // }


//     if (min < max) {

//         int mid = (min + max) / 2;

//         sort(A, min, mid);
//         // sort(A, mid+1, max);

//         merge(A,min,mid,max);
//         // for(int i = min; i < max; i++) {
//         //     printf("%d ", A[i]);
//         // }

//         // printf("\n");


//     }



// }

// int main(int argc, const char *argv[])
// {
//     FILE *file;
//     // file = fopen("IntegerArray.txt", "r");
//     file = fopen("smallnumbers.txt", "r");

//     // int count = 100000;
//     int count = 12;
//     int *N = (int *)malloc(sizeof(int) * count);

//     for(int i = 0; i < count; i++) {
//         fscanf(file, "%d", &N[i]);
//     }

//     sort(N, 0, count);


//     return 0;
// }



/* C program for merge sort */
#include<stdlib.h>
#include<stdio.h>

int count = 0;

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

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

    /* Copy the remaining elements of L[], if there are any */
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

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);

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
    file = fopen("IntegerArray.txt", "r");

    int arr[count];// = {4,8,1,20,13,2,11,7,19,15};

    for(int i = 0; i < count; i++) {
        fscanf(file, "%d", &arr[i]);
    }


    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);


    for (int i = 1; i < count; i++) {
        if (arr[i] < arr[i-1]) {
            printf("ERROR");
        }
    }



    return 0;
}
