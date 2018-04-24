#include "echo.h"

void echo(int argc, char *argv[])
{
  int i = 1;
  while (argv[i] != NULL)
  {
    print("%s ", argv[i]);
    i++;
  }
  print("\n");
}
