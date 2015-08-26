#include <stdio.h>
#include <stdlib.h>

int main()
{
  // load the data from the file 
  int readCount = 10;
  FILE *file;
  int *data = (int *)malloc(sizeof(int) * readCount);
  file = fopen("smallNumbers.txt", "r");
  
  int *tmp = (int *)malloc(sizeof(int) * 2);
  
  tmp[0] = 100;

  tmp[1] = 200;

  printf("%d", *tmp);
  printf("%d", *(tmp+1));
  






  for(int i = 0; i < readCount; i++) {
    //fscanf(file, "%d", *data
  }

    return 0;
}
