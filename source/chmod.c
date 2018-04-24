#include "chmod.h"
void chmode(int argc, char *argv[])
{

  /*droits:
    S_IRUSR : accès lecture propriétaire
    S_IWUSR : accès écriture propriétaire
    S_IXUSR : accès éxecution propriétaire

    S_IRGRP : accès lecture groupe
    S_IWGRP : accès écriture groupe
    S_IXGRP : accès éexecution groupe

    S_IROTH : accès lecture monde
    S_IWOTH : accès écriture monde
    S_IXOTH:  accès éxecution monde
  */

  char *droits = malloc(sizeof(char) * 256);
  char *fichier = malloc(sizeof(char) * 256);
  if (argc <= 2)
  {
    printErr("opérande manquant\n");
  }

  else if (argc > 3)
  {
    printErr("trop d'arguments\n");
  }

  else
  {
    droits = argv[1];
    fichier = argv[2];
  }

  switch (atoi(droits) / 100 % 10)
  { //on récupère le chiffre des centaines

  case 0: //aucun droits
    break;
  case 1: //executable
    chmod(fichier, S_IXUSR);
    break;
  case 2: //ecriture
    chmod(fichier, S_IWUSR);
    break;
  case 3: //ecrire et executer
    chmod(fichier, S_IXUSR);
    chmod(fichier, S_IWUSR);
    break;
  case 4: //lire
    chmod(fichier, S_IRUSR);
    break;
  case 5: //lire et executer
    chmod(fichier, S_IRUSR);
    chmod(fichier, S_IXUSR);
    break;
  case 6: //lire et ecrire
    chmod(fichier, S_IRUSR);
    chmod(fichier, S_IWUSR);
    break;
  case 7: //lire, ecrire et executer
    chmod(fichier, S_IRWXU);
    break;
  default:
    printErr("Erreur: droits mal formulés\n");
    break;
  }

  switch (atoi(droits) / 10 % 10)
  { //on récupère le chiffre des dizaines

  case 0: //aucun droits
    break;
  case 1: //executable
    chmod(fichier, S_IXGRP);
    break;
  case 2: //ecriture
    chmod(fichier, S_IWGRP);
    break;
  case 3: //ecrire et executer
    chmod(fichier, S_IXGRP);
    chmod(fichier, S_IWGRP);
    break;
  case 4: //lire
    chmod(fichier, S_IRGRP);
    break;
  case 5: //lire et executer
    chmod(fichier, S_IRGRP);
    chmod(fichier, S_IXGRP);
    break;
  case 6: //lire et ecrire
    chmod(fichier, S_IRGRP);
    chmod(fichier, S_IWGRP);
    break;
  case 7: //lire, ecrire et executer
    chmod(fichier, S_IRWXG);
    break;
  default:
    printErr("Erreur: droits mal formulés\n");
    break;
  }

  switch (atoi(droits) % 10)
  { //on récupère le chiffre des unités

  case 0: //aucun droits
    break;
  case 1: //executable
    chmod(fichier, S_IXOTH);
    break;
  case 2: //ecriture
    chmod(fichier, S_IWOTH);
    break;
  case 3: //ecrire et executer
    chmod(fichier, S_IXOTH);
    chmod(fichier, S_IWOTH);
    break;
  case 4: //lire
    chmod(fichier, S_IROTH);
    break;
  case 5: //lire et executer
    chmod(fichier, S_IROTH);
    chmod(fichier, S_IXOTH);
    break;
  case 6: //lire et ecrire
    chmod(fichier, S_IROTH);
    chmod(fichier, S_IWOTH);
    break;
  case 7: //lire, ecrire et executer
    chmod(fichier, S_IRWXO);
    break;
  default:
    printErr("Erreur: droits mal formulés\n");
    break;
  }
}
