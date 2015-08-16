#include <stdio.h>
#include <stdlib.h>

void checkAccuracy(int *data, int count) {

    int hold;
    for(int i = 0; i < count; i++) {

        if (i > 1) {
            if (hold > data[i]) {
                printf("\nERROR\n");
            }
        }
        hold = data[i];
    }
}

void printArray(int *data, int count) {
    for(int i = 0; i < count; i++) {
        printf("%d, ", data[i]);
    }
}

void sort(int *data, int start, int mid, int end) {

    // [start...............mid.................end]
    // [        leftArray    |    rightArray       ]
    // [ <--(mid - start)--->| <---(end - mid)---->]

    int la = mid - start + 1;
    int ra = end - mid;

    int *leftArray  = (int *)malloc(sizeof(int) * la);
    int *rightArray = (int *)malloc(sizeof(int) * ra);


    for(int i = 0; i < la; i++) {
        leftArray[i] = data[start + i];
    }

    for(int j = 0; j < ra; j++) {
        rightArray[j] = data[ra + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while(i < la && j < ra) {

        if (leftArray[i] <= rightArray[j]) {
            data[k] = leftArray[i];
            i++;
        } else {
            data[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < la) {
        data[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < ra) {
        data[k] = rightArray[j];
        j++;
        k++;
    }
}


void mergeSort(int *data, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
        sort(data, start, mid, end);
    }
}


int main() {

    // read the data from the file
    FILE *file;
    file = fopen("IntegerArray.txt", "r");
    int count = 10;
    int *data = (int *)malloc(sizeof(int) * count);
    for(int i = 0; i < count; i++) {
        fscanf(file, "%d", &data[i]);
    }

    // print array
    printArray(data, count);

    // mergeSort
    mergeSort(data, 0, count - 1);

    printf("\n\n");
    printArray(data, count);
    // print array
    checkAccuracy(data, count);

    return 0;
}
