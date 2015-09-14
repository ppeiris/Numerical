#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "closestpair.h"

// #define DEBUG_PRINT
void printPoints(DataList *data, int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d -> (%d %d)\n", (data + i)->datapoint->p, (data + i)->datapoint->x, (data + i)->datapoint->y);
	}
}

void printPoint(Point *p)
{
	printf("Point %d -> (%d %d)\n", p->p, p->x, p->y);
}

void sortData(DataList *datax, int start, int mid, int end, char field[])
{
	// Number of elements in the left half of the list
	int leftCount = mid - start + 1;
	// Number of elements in the right half of the list
	int rightCount = end - mid;

	// Define left tmp list for X
	DataList *leftPointsx = (DataList *)malloc(sizeof(DataList) * leftCount);
	// Define right tmp list for X
	DataList *rightPointsx = (DataList *)malloc(sizeof(DataList) * rightCount);

	// Copy the left half of the list to a tmp list
	for (int i = 0; i < leftCount; i++) {
		(leftPointsx + i)->datapoint = (datax + start + i)->datapoint;
	}

	// Copy the right half of the list to a tmp list
	for (int i = 0; i < rightCount; i++) {
		(rightPointsx + i)->datapoint = (datax + mid + 1 + i)->datapoint;
	}

	// Index for the right tmp list
	int leftIndexx = 0;
	// Index for the left tmp list
	int rightIndexx = 0;
	// Index for the main data
	int dataIndex = start;

	int leftCmpVal = 0;
	int rightCmpVal = 0;

	while (leftIndexx < leftCount && rightIndexx < rightCount) {
		if ( strcmp(field, "x") == 0) {
			leftCmpVal = (leftPointsx + leftIndexx)->datapoint->x;
			rightCmpVal = (rightPointsx + rightIndexx)->datapoint->x;
		} else { // Sort by X
			leftCmpVal = (leftPointsx + leftIndexx)->datapoint->y;
			rightCmpVal = (rightPointsx + rightIndexx)->datapoint->y;
		} // Sort by Y

		if ( leftCmpVal <= rightCmpVal) {
			(datax + dataIndex)->datapoint = (leftPointsx + leftIndexx)->datapoint;
			leftIndexx++;
		} else {
			(datax + dataIndex)->datapoint = (rightPointsx + rightIndexx)->datapoint;
			rightIndexx++;
		}
		dataIndex++;
	}

	while (leftIndexx < leftCount) {
		(datax + dataIndex)->datapoint = (leftPointsx + leftIndexx)->datapoint;
		dataIndex++;
		leftIndexx++;
	}

	while (rightIndexx < rightCount) {
		(datax + dataIndex)->datapoint = (rightPointsx + rightIndexx)->datapoint;
		dataIndex++;
		rightIndexx++;
	}

}

void sortInitialDataPoints(DataList *datax, int start, int end, char field[] = "x")
{
	if (start < end) {
		int mid = start + (end - start) / 2;
		sortInitialDataPoints(datax, start, mid, field);
		sortInitialDataPoints(datax, mid + 1, end, field);
		sortData(datax, start, mid, end, field);
	}
}




void initialize(DataList *datalistX, DataList *datalistY, int readCount)
{
	FILE *file = fopen("points.txt", "r");
	for (int i = 0; i < readCount; i++) {
		(datalistX + i)->datapoint = (Point *)malloc(sizeof(Point));
		fscanf(file, "%d %d", &(datalistX + i)->datapoint->x, &(datalistX + i)->datapoint->y);
		(datalistX + i)->datapoint->p = i;
		(datalistY + i)->datapoint = (datalistX + i)->datapoint;
	}

	#ifdef DEBUG_PRINT
	printf("=========================== Original Data ============================\n");
	printPoints(datalistX, 10);
	#endif
	sortInitialDataPoints(datalistX, 0, readCount - 1);

	#ifdef DEBUG_PRINT
	printf("=========================== X - Sorted ============================\n");
	printPoints(datalistX, 10);
	#endif

	char ch[] = "y";
	sortInitialDataPoints(datalistY, 0, readCount - 1, ch);

	#ifdef DEBUG_PRINT
	printf("=========================== Y - Sorted ============================\n");
	printPoints(datalistY, 10);
	#endif
}

double calcDistance(Point *p1, Point *p2)
{

	printPoint(p1);
	printPoint(p2);
	double n1 = pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2);
}

double closestPoints(DataList *datalistX, DataList *datalistY, int start, int end)
{


	int npoints = end - start + 1;
	double leftmin;
	double rightmin;
	double min1;

	if (start < end) {
		if (npoints == 2) {
			// Calculate the distance between 2 point
			return calcDistance((datalistX + start + 0)->datapoint, (datalistY + start + 1)->datapoint);
		} else if (npoints == 3) {
			printf("calculate 3 points \n");

			min1 = calcDistance((datalistX + start + 0)->datapoint, (datalistY + start + 1)->datapoint);
			double min2 = calcDistance((datalistX + start + 1)->datapoint, (datalistY + start + 2)->datapoint);
			double min3 = calcDistance((datalistX + start + 2)->datapoint, (datalistY + start + 3)->datapoint);
			min1 = min1 < min2 ? min1 : min2;
			min1 = min1 < min3 ? min1 : min3;

			return min1;
		}

		int mid = start + (end - start)/2;


		leftmin = closestPoints(datalistX, datalistY, start, mid);
		printf("leftmin %f\n", leftmin);
		rightmin = closestPoints(datalistX, datalistY, mid + 1, end);
		printf("rightmin %f\n", rightmin);

		return leftmin < rightmin ? leftmin : rightmin;
	}


	return 0.0;
}


int main()
{
	int readCount = 10;
	DataList *datalistX = (DataList *)malloc(sizeof(DataList) * readCount);
	DataList *datalistY = (DataList *)malloc(sizeof(DataList) * readCount);
	initialize(datalistX, datalistY, readCount);

	DataList *closestpair = (DataList *)malloc(sizeof(DataList) * 2);

	double min = closestPoints(datalistX, datalistY, 0, readCount - 1);

	printf("___ distance is %f\n", min);


	return 0;
}
