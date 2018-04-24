#include "mv.h"
#include "./comCommunication.h"

void mv(int argc, char *argv[])
{
  FILE *source = NULL;
  FILE *destination = NULL;
  char chaine[1000] = "";
  source = fopen(argv[1], "r");
  destination = fopen(argv[2], "w");
  if (source == NULL)
  {
    printErr("Le fichier source \"%s\" est introuvable.", argv[1]);
    return;
  }
  while (fgets(chaine, 1000, source) != NULL)
  {
    fputs(chaine, destination);
  }
  fclose(source);
  fclose(destination);
  if (remove(argv[1]))
  {
    print("le fichier \"%s\" a bien été supprimé.\n", argv[1]);
  }
  else
  {
    printErr("Erreur lors de la suppression de %s.", argv[1]);
  }
}
