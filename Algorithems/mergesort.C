#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printData(int *read, int count)
{
  for(int i = 0; i < count; i++) {
    printf("Address [%p] = %d\n", (read + i),*(read + i));
  }
}

void mergeSort(int *data, int start, int mid, int end)
{

  int n1 = (mid - start) + 1; // 4 - 0 + 1 = 5
  int n2 = (end - mid); // 9 - 4 = 5

  int leftArray[n1], rightArray[n2];

  for(int i = 0; i < n1; i++) {
    leftArray[i] = *(data + start + i);
  }

  for(int i = 0; i < n2; i++) {
    rightArray[i] = *(data + mid + 1 + i);
  }

  int leftIndex = 0;
  int rightIndex = 0;
  int dataIndex = start;
  while (leftIndex < n1 && rightIndex < n2) {

    if (leftArray[leftIndex] <= rightArray[rightIndex]) {
      *(data + dataIndex) = leftArray[leftIndex];
      leftIndex++;
    } else {
      *(data + dataIndex) = rightArray[rightIndex];
      rightIndex++;
    }

    dataIndex++;
  }

  while(leftIndex < n1) {
    *(data + dataIndex) = leftArray[leftIndex];
    dataIndex++;
    leftIndex++;
  }

  while(rightIndex < n2) {
    *(data + dataIndex) = rightArray[rightIndex];
    dataIndex++;
    rightIndex++;
  }
}

void divide(int *data, int start, int end)
{
  int mid = start + (end - start)/2;
  if(start < end) {
    divide(data, start, mid);
    divide(data, mid + 1, end);
    mergeSort(data, start, mid, end);
  }

}

int main()
{
  // load the data from the file
  clock_t begin, end;
  double time_spent;
  int readCount = 100000;
  FILE *file;
  int *data = (int *)malloc(sizeof(int) * readCount);
  file = fopen("IntegerArray.txt", "r");

  for(int i = 0; i < readCount; i++) {
    fscanf(file, "%d", (data + i));
  }

  // printData(data, readCount);
  printf("===============================\n");
  begin = clock();
  divide(data, 0, readCount - 1);
  end = clock();
  printData(data, readCount);
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time spend = %f\n", time_spent);
  return 0;
}
