#include "myecho.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i =1;
  while(argv[i] != NULL)
  {
    printf("%s ", argv[i]);
    i++;
  }
  printf("\n");
  return 0;
}
