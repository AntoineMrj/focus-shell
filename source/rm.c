#include "rm.h"
#include <stdlib.h>
#include <stdio.h>

void rm(int argc, char *argv[])
{
<<<<<<< HEAD
  print("le fichier \"%s\" a bien été supprimé.\n", argv[1]);
  if (argv[1] != NULL)
  {
    remove(argv[1]);
    return 0;
  }else{return 1;}
=======
  if (argc == 1)
  {
    printErr("rm: opérande manquant\n");
  }
  else
  {
    for (int i = 1; i < argc; i++)
    {
      if ((remove(argv[i])) == -1)
      {
        printErr("Le fichier '%s' n'existe pas.\n", argv[i]);
      }
    }
  }
>>>>>>> f568ce8e34571c286664390db1f0eb7d4e9de2e2
}
