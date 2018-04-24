#include "cp.h"
#include <stdlib.h>
#include <stdio.h>

void cp(int argc, char *argv[])
{
  FILE *source = NULL;
  FILE *destination = NULL;
  char chaine[1000] = "";
  if(argc >= 2)
  {
  source = fopen(argv[1], "r");
  destination = fopen(argv[2], "w");
  }
  else
  {
    return;
  }

  if (source == NULL)
  {
    printErr("Le fichier source \"%s\" est introuvable.", argv[1]);
  }
  else
  {

    while (fgets(chaine, 1000, source) != NULL)
    {
      fputs(chaine, destination);
    }
    fclose(source);
    fclose(destination);
  }
}
