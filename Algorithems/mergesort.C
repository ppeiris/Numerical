#include <stdio.h>
#include <stdlib.h>


void printData(int *read, int count)
{
  for(int i = 0; i < count; i++) {
    printf("Address [%p] = %d\n", (read + i),*(read + i));
  }
}



void mergeSort(int *data, int start, int mid, int end)
{

  printf("Sort start [%d] mid [%d] end [%d]\n", start, mid, end);

  int i, j, k;

  int n1 = (mid - start);
  int n2 = (end - mid);




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
  int readCount = 10;
  FILE *file;
  int *data = (int *)malloc(sizeof(int) * readCount);
  file = fopen("smallNumbers.txt", "r");


  for(int i = 0; i < readCount; i++) {
    fscanf(file, "%d", (data + i));
  }

  // printData(data, readCount);
  divide(data, 0, readCount - 1);



  return 0;
}
