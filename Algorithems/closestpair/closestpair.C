#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file = fopen("points.txt", "r");


	int readCount = 10;

	typedef struct _point{
		int x;
		int y;
	} Point;

	Point *pointsList = (Point *)malloc(sizeof(Point) * readCount);


	pointsList->x = 123;
	pointsList->y = 434;

	printf("%d %d\n", pointsList->x, pointsList->y);


	(pointsList + 1)->x = 234;
	(pointsList + 1)->y = 999;


	printf("%d %d\n", (pointsList + 1)->x, (pointsList + 1)->y);

	for(int i = 0; i < readCount; i++) {
		fscanf(file, "%d %d",&((pointsList + i)->x), &((pointsList + i)->y));
		printf("[ %d, %d ]\n", (pointsList + i)->x, (pointsList + i)->y);

	}




	return 0;
}
