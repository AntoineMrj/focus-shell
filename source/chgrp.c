#include "chgrp.h"

int chgrp(int argc, char *argv[])
{

  char *fichier;
  gid_t gid;         //identifiant du groupe
  struct group *grp; //structure contenant les champs partiels d'un enregistrement de la base de données de groupe

  if (argc == 1)
  {
    printErr("chgrp: opérande manquant\n");
  }
  else if (argc == 2)
  {
    printErr("chgrp: opérande manquant après '%s'\n", argv[1]);
  }
  else
  {
    grp = getgrnam(argv[1]);
    if (grp == NULL)
    {
      printErr("%s: nom de groupe incorrect\n",argv[1]);
      return -1;
    }
    gid = grp->gr_gid;

    for(int i=2; i<argc; i++)
    {
      fichier = argv[i];
      if(chown(fichier, -1, gid) == -1)
      {
        printErr("%s: nom de fichier incorrect\n",fichier);
      }
    }
  }
  return 0;
}
