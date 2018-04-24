#include "echo.h"

void echo(int argc, char *argv[])
{
  for(int i = 1;i<argc;i++)
    print("%s ", argv[i]);
  print("\n");
}
