#include "cp.h"
#include <stdlib.h>
#include <stdio.h>

int cp(int argc, char *argv[])
{
  FILE* source = NULL;
  FILE* destination = NULL;
  char chaine[1000]="";
  source = fopen(argv[1], "r");
  destination = fopen(argv[2],"w");
  if (source == NULL)
  {
    printf("Le fichier source \"%s\" est introuvable.", argv[1]);
    return(-1);
  }

  while (fgets(chaine, 1000, source) != NULL)
{
    fputs(chaine, destination);

}
  fclose(source);
  fclose(destination);
  return 0;
}
