#include "echo.h"

int echo(int argc, char *argv[])
{
  int i = 1;
  while (argv[i] != NULL)
  {
    print("%s ", argv[i]);
    i++;
  }
  print("\n");
  return 0;
}
