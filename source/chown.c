#include "chown.h"

int chowner(int argc, char *argv[])
{

  char *fichier;
  uid_t uid;          //identifiant de l'utilisateur
  struct passwd *pwd; //structure contenant les divers champs de l'enregistrement de la base de données des mots de passe

  if (argc == 1)
  {
    printErr("chown: opérande manquant\n");
  }
  else if (argc == 2)
  {
    printErr("chown: opérande manquant après '%s'\n", argv[1]);
  }
  else
  {
    pwd = getpwnam(argv[1]);
    if (pwd == NULL)
    {
      printErr("%s: nom d'utilisateur incorrect\n",argv[1]);
      return -1;
    }
    uid = pwd->pw_uid;

    for(int i=2; i<argc; i++)
    {
      fichier = argv[i];
      if(chown(fichier, uid, -1) == -1)
      {
        printErr("%s: nom de fichier incorrect\n",fichier);
      }
    }
  }
  return 0;
}
