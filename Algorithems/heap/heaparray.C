#include <stdio.h>
#include <stdlib.h>

/**
 * Print the array
 */
void printA(int *A, int length)
{
	printf("===== Array ======\n");
	for (int i = 0; i < length; i++) {
		printf("Data at %d = %d\n", i, A[i]);
	}

}

/**
 * Swap two array positions
 */
void swap(int *A, int i, int j)
{
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

/**
 * return the right clild index using the (2i + 1)
 * formula. Additional 1 being added since the array
 * index start from 0
 */
int right(int i)
{
	return ((2 * i) + 1 + 1);
}

/**
 * return the left child index using (2i) formula, and
 * additional 1 being added since the array index start from 0
 */
int left(int i)
{
	return ((2 * i) + 1);
}

/**
 * Max hepify the array
 */
void max_hepify(int *A, int i, int length)
{

	int l = left(i);
	int r = right(i);
	int largest;

	if (l < length && A[l] > A[i]) {
		largest = l;
	} else {
		largest = i;
	}

	if (r < length && A[r] > A[largest]) {
		largest = r;
	}

	if (largest != i) {

		swap(A, i, largest);
		max_hepify(A, largest, length);
	}

}

/**
 * Build the MAX HEAP structure
 * Root contain the max value
 */
void build_max_heap(int *A, int length)
{
	for (int i = length/2; i > -1; i--) {
		max_hepify(A, i, length);
	}
}


void min_hepify(int *A, int i, int length)
{

	int l = left(i);
	int r = right(i);

	int s;

	if (l < length && A[l] < A[i]) {
		s = l;
	} else {
		s = i;
	}


	if (r < length && A[r] < A[s]) {
		s = r;
	}

	if (s != i) {
		swap(A, s, i);
		min_hepify(A, s, length);
	}

}

void build_min_heap(int *A, int length)
{
	for (int i = length/2; i > -1; i--) {
		min_hepify(A, i, length);
	}
}

int main()
{
	int A[] = {8, 1, 3, 2, 16, 9, 10, 14, 4, 7};
	int length = sizeof(A)/sizeof(int);
	build_max_heap(A, length);
	printA(A, length);
	build_min_heap(A, length);
	printA(A, length);
	return 0;

}
