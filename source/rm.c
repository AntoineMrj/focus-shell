#include "rm.h"

void rm(int argc, char *argv[])
{
  if (argc == 1)
    return;

  int c;

  // Options possibles
  char AvailableOptions[] = "idf";

  int nbOption = 0;
  int nbChampsOption;
  int nbFichier = 0;
  compteFichiersArgs(argc, argv, &nbFichier);

  int retour;

  //Stockage des options activées ou non,
  //initialisées à non activées
  int i = 0;
  int d = 0;
  int f = 0;
  int courant;
  //Tant que toutes les fonctions n'ont pas été lues
  while (courant != EOF)
  {
    courant = getopt(argc, argv, AvailableOptions);
    c = courant;
    if (c == 'i')
    {
      i = 1;
      nbOption++;
    }
    else if (c == 'd')
    {
      d = 1;
      nbOption++;
    }
    else if (c == 'f')
    {
      f = 1;
      nbOption++;
    }
  }

  //On test l'existence d'un argument correspondant au fichier pour ne pas
  //aller effacer une case mémoire en cas de mauvaise manip de l'utilisateur
  if (nbFichier <= 0)
  {
    printErr("Le Nombre d'argument est insuffisant, veuillez preciser les fichier à effacer\n");
    return;
  }
  nbChampsOption = argc - nbFichier - 1;

  // Si l'option f est activée, on ignore les avertissements.
  if (f)
  {
    for (int i = nbChampsOption + 1; i < argc; i++)
    {
      effacerArgument(argv[i]);
      return;
    }
  }

  if (i)
  {
    for (int i = nbChampsOption + 1; i < argc; i++)
    {
      retour = verification();
      if (retour == 1)
        effacerArgument(argv[i]);
    }
    return;
  }

  // Formule sans option, le d n'étant pas une option à gere
  // Car remove() supprime également les repertoires
  for (int i = nbChampsOption + 1; i < argc; i++)
  {
    effacerArgument(argv[i]);
  }
  return;
}

int verification()
{
  size_t tailleSaisie = 14; //Seul le premier caractère Y/N comptera, +1 pour \0
  char saisie[tailleSaisie];
  int saisieOk = 0;
  while (!saisieOk)
  {
    print("Etes vous sûr(e) de vouloir supprimer ce(s) fichier(s) ?\n");
    print("Yes/No ?\n");
    fgets(saisie, tailleSaisie, stdin);
    if (saisie[0] == 'Y' || saisie[0] == 'y')
    {
      saisieOk = 1;
    }
    else if (saisie[0] == 'N' || saisie[0] == 'n')
    {
      saisieOk = 2;
    }
  }
  return saisieOk;
}

int effacerArgument(char *toDelete)
{
  if ((remove(toDelete)) == -1)
  {
    //printErr("Le fichier '%s' n'existe pas.\n", argv[i]);
    //printf("%s\n",toDelete);
    printf("Le fichier n'existe pas\n");
  }
  return 0;
}

void compteFichiersArgs(int argc, char *argv[], int *nbFichier)
{
  char *chaineCourante;
  char premierCaractere;

  for (int i = 1; i < argc; i++)
  {
    chaineCourante = argv[i];
    premierCaractere = chaineCourante[0];
    if (premierCaractere != '-')
    {
      *nbFichier += 1;
    }
  }
}
