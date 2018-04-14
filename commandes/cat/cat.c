#include "cat.h"

int cat(int argc, char *argv[])
{
  int i;
  char ligne[1000] = "";
  FILE *fichier = NULL;

  for (i = 1; i < argc; i++)
  {
    fichier = fopen(argv[i], "r");

    if (!fichier)
    {
      printf("This file does not exist, check the name\n");
      break;
    }

    else
    {
      while (fgets(ligne, 1000, fichier))
      {
        printf("%s", ligne);
      }
    }

    fclose(fichier);
  }

  return (0);
}
