#include <stdio.h>
#include <stdlib.h>
#include "closestpair.h"

void printPoints(DataList *data, int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d -> (%d %d)\n", (data + i)->datapoint->p, (data + i)->datapoint->x, (data + i)->datapoint->y);
	}

}

void divide(DataList *data, int start, int end)
{
	// if(start < end) {
	// 	int mid =
	// }
}

int main()
{
	int readCount = 10;
	FILE *file = fopen("points.txt", "r");
	DataList *datalist = (DataList *)malloc(sizeof(DataList) * readCount);
	for(int i = 0; i < readCount; i++) {
		(datalist + i)->datapoint = (Point *)malloc(sizeof(Point));
		fscanf(file, "%d %d", &(datalist + i)->datapoint->x, &(datalist + i)->datapoint->y);
		(datalist + i)->datapoint->p = i;
	}


	divide(datalist, 0, readCount - 1);


	printPoints(datalist, 10);

	return 0;
}
