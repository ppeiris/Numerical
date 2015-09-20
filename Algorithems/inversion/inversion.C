#include "stdio.h"
#include "stdlib.h"
#include <time.h>

void printData(int *data, int count)
{
	printf("[");
	for(int i = 0; i < count; i++) {
		printf("%d ", *(data + i));
	}
	printf("]\n");
}

int countSplit(int *data, int start, int mid, int end)
{
	int leftCount = mid - start + 1;
	int rightCount = end - mid;

	// printf("[%d %d]\n", leftCount, rightCount);

	int *left = (int *)malloc(sizeof(int) * leftCount);
	int *right = (int *)malloc(sizeof(int) * rightCount);


	for(int i = 0; i < leftCount; i++) {
		*(left + i) = *(data + start + i);
	}


	for(int i = 0; i < rightCount; i++) {
		*(right + i) = *(data + mid + 1 + i);
	}


	int i = 0;
	int j = 0;
	int k = start;
	int inv = 0;
	while(i < leftCount && j < rightCount) {

		if (*(left +i) <= *(right + j)) {
			*(data + k) = *(left + i);
			i++;
		} else {
			*(data + k) = *(right + j);
			j++;
			inv += leftCount - i;
			// printf("number of inversions = %d \n", inv);
		}
		k++;
	}

	while(i < leftCount) {
		*(data + k) = *(left + i);
		k++;
		i++;
	}

	while(j < rightCount) {
		*(data + k) = *(right + j);
		k++;
		j++;
	}

	return inv;
	// return 0;
}

void divide(int *data, int start, int end, long int *invc)
{
	if (start < end) {
		int mid = start + (end - start)/2;
		divide(data, start, mid, invc);
		divide(data, mid + 1, end, invc);
		int inversionCount = countSplit(data, start, mid, end);
		*invc +=inversionCount;
	}
}


int main()
{
	clock_t begin, end;
	double time_spent;
	int readCount = 100000;
	// int readCount = 10;
	// FILE *file = fopen("smallInversions.txt", "r");
	FILE *file = fopen("IntegerArray.txt", "r");
	long int invc = 0;
	int *data = (int *)malloc(sizeof(int) *readCount);
	for (int i = 0; i < readCount; i++) {
		fscanf(file, "%d", (data + i));
	}
	// printData(data, readCount);
	begin = clock();
	divide(data, 0, readCount - 1, &invc);
	end = clock();
	// printData(data, readCount);
	printf("Total inversions = %ld\n", invc);
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time took = %f s\n", time_spent);
  	return 0;
}
