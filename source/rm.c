#include "rm.h"
#include <stdlib.h>
#include <stdio.h>

int rm(int argc, char *argv[])
{
  print("le fichier \"%s\" a bien été supprimé.\n", argv[1]);
  if (argv[1] != NULL)
  {
    remove(argv[1]);
    return 0;
  }else{return 1;}
}
