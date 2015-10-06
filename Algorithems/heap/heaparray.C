#include <stdio.h>
#include <stdlib.h>

/**
 * Print the array
 */
void printA(int *A, int length)
{
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
	int l = left(i); // left child index
	int r = right(i); // right child index
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
		swap(A, largest, i);
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

int main()
{
	int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int length = sizeof(A)/sizeof(int);
	build_max_heap(A, length);
	printA(A, length);
	return 0;

}
