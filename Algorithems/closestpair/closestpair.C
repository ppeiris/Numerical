#include <stdio.h>
#include <stdlib.h>
#include "closestpair.h"

void sortXY(Point *data, int start, int mid, int end)
{

		printf("[%d %d %d]\n", start, mid, end);

		int *X = (int *)malloc(sizeof(int) * (end - start + 1)); // X values
		int *Y = (int *)malloc(sizeof(int) * (end - start + 1)); // Y values


		int leftCount = mid - start + 1;
		int rightCount = end - mid;

		for (int i = 0; i < leftCount; i++) {
			*(X + i) =
		}



}


void findClosestPair(Point *data, int start, int end)
{
	if (start < end) {
		int mid = start + (end - start)/2;
		findClosestPair(data, start, mid);
		findClosestPair(data, (mid + 1), end);
		sortXY(data, start, mid, end);
	}
}


int main()
{
	int readCount = 10;

	FILE *file = fopen("points.txt", "r");
	Point *pointsList = (Point *)malloc(sizeof(Point) * readCount);

	for(int i = 0; i < readCount; i++) {
		fscanf(file, "%d %d",&((pointsList + i)->x), &((pointsList + i)->y));
		// printf("[ %d, %d ]\n", (pointsList + i)->x, (pointsList + i)->y);

	}


	findClosestPair(pointsList, 0, readCount - 1);


	return 0;
}
