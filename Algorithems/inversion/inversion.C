#include "stdio.h"
#include "stdlib.h"
#include <time.h>

void printData(int *data, int count)
{
	for(int i = 0; i < count; i++) {
		printf("data[%d] = %d \n", i, *(data + i));
	}
}



void countSplit(int *data, int start, int mid, int end)
{
	int leftCount = mid - start + 1;
	int rightCount = end - mid;

	int *left = (int *)malloc(sizeof(int) * leftCount);
	int *right = (int *)malloc(sizeof(int) * rightCount);







	printf("[%d, %d, %d]\n", start, mid, end);



}



void divide(int *data, int start, int end)
{
	if (start < end) {
		int mid = start + (end - start)/2;
		// printf("[%d %d]\n", start, end);
		divide(data, start, mid);
		// printf("[%d %d]\n", mid + 1, end);
		divide(data, mid + 1, end);

		countSplit(data, start, mid, end);
	}
}


int main()
{
	clock_t begin, end;
	double time_spent;
	int readCount = 10;
	FILE *file = fopen("smallNumbers.txt", "r");
	int *data = (int *)malloc(sizeof(int) *readCount);
	for (int i = 0; i < readCount; i++) {
		fscanf(file, "%d", (data + i));
	}
	divide(data, 0, readCount - 1);
	printData(data, readCount);

  	return 0;
}
