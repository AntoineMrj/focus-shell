#include "rm.h"

int rm(int argc, char *argv[])
{
  printf("le fichier \"%s\" a bien été supprimé.\n", argv[1]);
  remove(argv[1]);
  return 0;
}
