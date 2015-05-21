#include <stdio.h>
#include <stdlib.h>

void printArray(int data[], int count) {

    printf("\n[ ");
    for(int i = 0; i < count; i++) {
        if (i == count - 1) {
            printf("%d ", data[i]);
        } else {
            printf("%d, ", data[i]);
        }
    }
    printf("]\n");
}

void sort(int data[], int min, int mid, int max) {

    int i, j, k;
    int n1 = mid - min + 1;
    int n2 = max - mid;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++) {
        L[i] = data[min + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = data[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = min;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        }
        else
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int data[], int min, int max) {

    if (min < max) {
        int mid = min + (max-min)/2;
        mergeSort(data, min, mid);
        mergeSort(data, (mid + 1), max);
        sort(data, min, mid, max);
    }

}

int main() {

    FILE *file;
    file = fopen("IntegerArray.txt", "r");
    int count = 100000;
    int data[count];
    for(int i = 0; i < count; i++) {
        fscanf(file, "%d", &data[i]);
    }
    printArray(data, count);
    mergeSort(data, 0, count - 1);
    printArray(data, count);

}
