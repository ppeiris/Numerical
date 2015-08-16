#include <stdio.h>
#include <stdlib.h>




int main(int argc, char * argv[])
{

	/* read the data from the file */

	FILE *file;
	int readCount = 100;
	file = fopen("IntegerArray.txt", "r");
	int *data = (int *)malloc(sizeof(int) * readCount);

	for (int i = 0; i < readCount; i++) {
		fread(file, "%d", &data[i]);
	}



	/* print the initial array */

	/* merge sort */

	/* print the sorted array */

	return 0;
}
