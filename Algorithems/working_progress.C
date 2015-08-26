#include <stdio.h>
#include <stdlib.h>

void checkaccuracy(int *data, int count) {

    int hold;
    for(int i = 0; i < count; i++) {

        if (i > 1) {
            if (hold > data[i]) {
                printf("\nerror\n");
            }
        }
        hold = data[i];
    }
}

void printarray(int *data, int count) {
    for(int i = 0; i < count; i++) {
        printf("%d, ", data[i]);
    }
}

void sort(int *data, int start, int mid, int end) {

    // [start...............mid.................end]
    // [        leftarray    |    rightarray       ]
    // [ <--(mid - start)--->| <---(end - mid)---->]

    int la = mid - start + 1;
    int ra = end - mid;

    int *leftarray  = (int *)malloc(sizeof(int) * la);
    int *rightarray = (int *)malloc(sizeof(int) * ra);


    for(int i = 0; i < la; i++) {
        leftarray[i] = data[start + i];
    }

    for(int j = 0; j < ra; j++) {
        rightarray[j] = data[ra + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while(i < la && j < ra) {

        if (leftarray[i] <= rightarray[j]) {
            data[k] = leftarray[i];
            i++;
        } else {
            data[k] = rightarray[j];
            j++;
        }
        k++;
    }

    while(i < la) {
        data[k] = leftarray[i];
        i++;
        k++;
    }

    while(j < ra) {
        data[k] = rightarray[j];
        j++;
        k++;
    }
}


void mergesort(int *data, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        mergesort(data, start, mid);
        mergesort(data, mid + 1, end);
        sort(data, start, mid, end);
    }
}


int main() {

    // read the data from the file
    file *file;
    file = fopen("integerarray.txt", "r");
    int count = 10;
    int *data = (int *)malloc(sizeof(int) * count);
    for(int i = 0; i < count; i++) {
        fscanf(file, "%d", &data[i]);
    }

    // print array
    printarray(data, count);

    // mergesort
    mergesort(data, 0, count - 1);

    printf("\n\n");
    printarray(data, count);
    // print array
    checkaccuracy(data, count);

    return 0;
}
