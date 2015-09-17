#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "closestpair.h"

// #define DEBUG_PRINT
// #define DEBUG_PRINT_PAIR
#define DEBUG_TMP
void printPoints(DataList *data, int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d -> (%d %d)\n", (data + i)->datapoint->p, (data + i)->datapoint->x, (data + i)->datapoint->y);
	}
}

void printPair(DataList *pair)
{
	printf(
	    " The closest pair is (%d %d) and (%d %d)\n",
	    (pair + 0)->datapoint->x,
	    (pair + 0)->datapoint->y,
	    (pair + 1)->datapoint->x,
	    (pair + 1)->datapoint->y
	);

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
		if (strcmp(field, "x") == 0) {
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




void initialize(DataList *datalistX, DataList *datalistY, DataList *pair, int readCount)
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

	(pair + 0)->datapoint = NULL;
	(pair + 1)->datapoint = NULL;
}

double calcDistance(Point *p1, Point *p2)
{
	double distance = pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2);
#ifdef DEBUG_PRINT_PAIR
	printPoint(p1);
	printPoint(p2);
	printf("--------- Distance = %f\n", distance);
#endif
	return distance;
}

/**
 * this should run only when npx <= 8
 */
double bruteforce(DataList *datalistX, int npx, DataList *pair)
{
	double min_dist = DBL_MAX;
	double pointDistance = DBL_MAX;

	// Find the distance between already picked points
	if ((pair + 0)->datapoint != NULL && (pair + 1)->datapoint != NULL) {
		pointDistance = calcDistance(
		                    (pair + 0)->datapoint,
		                    (pair + 1)->datapoint
		                );
	}

	for (int i = 0; i < npx; i++) {
		for (int j = i + 1; j < npx; j++) {
			int distance = calcDistance(
			                   (datalistX + i)->datapoint,
			                   (datalistX + j)->datapoint
			               );
			if (distance < min_dist) {
				min_dist = distance;
				if ((pair + 0)->datapoint == NULL && (pair + 1)->datapoint == NULL) {
					(pair + 0)->datapoint = (datalistX + i)->datapoint;
					(pair + 1)->datapoint = (datalistX + j)->datapoint;
				} else {
					if (min_dist < pointDistance) {
						(pair + 0)->datapoint = (datalistX + i)->datapoint;
						(pair + 1)->datapoint = (datalistX + j)->datapoint;
					}
				}
			}
		}
	}
	return min_dist;
}

double closestPoints(DataList *datalistX,
                     int npx,
                     DataList *datalistY,
                     int npy,
                     DataList *pair)
{
	double mid_x;
	double mid_distance;
	double distance;
	Point *tmpPoint;
	if (npx <= 8) {

		return bruteforce(datalistX, npx, pair);
	}

	DataList *datalistYY = (DataList *)malloc(sizeof(DataList) * npy);

	/** get the mid x value of the PX array. this is the division for left being Q and right 		being R */
	mid_x = (datalistX + npx / 2)->datapoint->x;

	int rightIndex = npy - 1;
	int leftIndex = 0;
	for (int i = 0; i < npy; i++) {
		if ((datalistY + i)->datapoint->x < mid_x) {
			(datalistYY + leftIndex)->datapoint = (datalistY + i)->datapoint;
			leftIndex++;
		} else {
			(datalistYY + rightIndex)->datapoint = (datalistY + i)->datapoint;
			rightIndex--;
		}
	}


	/**************************************************************
		Reverse the RY part of the array to reverse the order
		at this point RY has data in decending order for Y value.
		we need to make this accending order for RY for Y value

		datalistYY
		----------------------------------
		|	|	|	|	|	|	|	|	|
		----------------------------------
		<---- QY -----> ^ <---- RY ----->

	*************************************************************/

#ifdef DEBUG_PRINT
	printf("=========================== QY and RY ============================\n");
	printPoints(datalistYY, npy);
#endif

	for (int i = npy - 1; rightIndex < i; rightIndex++, i--) {
		tmpPoint = (datalistYY + rightIndex)->datapoint;
		(datalistYY + rightIndex)->datapoint = (datalistYY + i)->datapoint;
		(datalistYY + i)->datapoint = tmpPoint;
	}

#ifdef DEBUG_PRINT
	printf("=========================== QY and RY (reversed) ==================\n");
	printPoints(datalistYY, npy);
#endif

	mid_distance = closestPoints(
	                   datalistX,
	                   npx / 2,
	                   datalistYY,
	                   (leftIndex + 1),
	                   pair
	               );

	distance = closestPoints(
	               datalistX,
	               (npx - npx / 2),
	               datalistYY,
	               (npy - leftIndex - 1),
	               pair
	           );

	if (distance < mid_distance) {
		mid_distance = distance;
	}


	int delta = calcDistance(
	            (pair + 0)->datapoint,
	            (pair + 1)->datapoint
	        );


	int dleftIndex = 0;
	int drightIndex = npy - 1;
	for (int i = 0; i < npy; i++) {
		double distanceofy = (datalistY + i)->datapoint->x - mid_x;
		if (distanceofy <= (mid_x - delta)) { // the point is in the left side of mid_x
			(datalistYY + dleftIndex)->datapoint = (datalistY + i)->datapoint;
			dleftIndex++;
		} else if (distanceofy <= (mid_x + delta)) {
			(datalistYY + drightIndex)->datapoint = (datalistY + i)->datapoint;
			drightIndex--;
		}
	}


	// while(dleftIndex >= 0) {
	// 	int x0 = (datalistYY + dleftIndex)->datapoint->y + delta;

	// }

	return sqrt(mid_distance);
}

double bruteforceForAllData(DataList *x, int npx, DataList *pair)
{
	double min_dist = DBL_MAX;
	double dist;
	for (int i = 0; i < npx; i++) {
		for (int j = i + 1; j < npx; j++) {
			dist = calcDistance((x + i)->datapoint, (x + j)->datapoint);
			if (dist < min_dist) {
				min_dist = dist;
				(pair + 0)->datapoint = (x + i)->datapoint;
				(pair + 1)->datapoint = (x + j)->datapoint;
			}
		}
	}

	return min_dist;
}



int main()
{
	int readCount = 20;
	DataList *datalistX = (DataList *)malloc(sizeof(DataList) * readCount);
	DataList *datalistY = (DataList *)malloc(sizeof(DataList) * readCount);
	DataList *pair = (DataList *)malloc(sizeof(DataList) * 2);
	initialize(datalistX, datalistY, pair, readCount);

	int npx = readCount;
	int npy = readCount;

	double min = closestPoints(datalistX, npx, datalistY, npy, pair);
	printPair(pair);
	printf(" >>>>>>>>>> Distance 1 is = %f\n", min);

	printf(" >>>>>>>>>>> Distance 2 is = %f\n", sqrt(bruteforceForAllData(datalistX, npx, pair)));

	printPair(pair);
	printf("------------------------------\n");
	return 0;
}
