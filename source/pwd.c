#include "pwd.h"

void pwd(int argc, char *argv[])
{

  char *repertoire_courant = malloc(sizeof(char) * 256);
  size_t size = 256;

  getcwd(repertoire_courant, size);

  print("%s\n", repertoire_courant);

}
