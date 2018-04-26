#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void compteFichiersArgs(int argc, char *argv[], int *nbFichier);
int effacerArgument(char *toDelete);
int verification();


int main(int argc, char *argv[])
{
  if (argc == 1)
    return 0;

  printf("nb arg :%d\n",argc);
  char c ="";

  // Options possibles
  char AvailableOptions[] = "idf";

  int nbOption = 0;
  int nbChampsOption;
  int nbFichier = 0;
  compteFichiersArgs(argc,argv,&nbFichier);

  int retour;

  //Stockage des options activées ou non,
  //initialisées à non activées
  int i = 0;
  int d = 0;
  int f = 0;
  int courant;
  //Tant que toutes les fonctions n'ont pas été lues
  while(courant !=EOF)
  {
    courant = getopt(argc,argv,AvailableOptions);
    c = (char)courant;
    if (c == 'i')
    {
        i = 1;
        nbOption ++;
    }
    else if (c == 'd')
    {
        d = 1;
        nbOption ++;
    }
    else if (c == 'f')
    {
        f = 1;
        nbOption ++;
    }
  }

  //On test l'existence d'un argument correspondant au fichier pour ne pas
  //aller effacer une case mémoire en cas de mauvaise manip de l'utilisateur
  printf("nb de fichier %d \n", nbFichier);
  if(nbFichier <= 0)
  {
    printf("Le Nombre d'argument est insuffisant, veuillez preciser les fichier à effacer\n");
    return 0;
  }
  nbChampsOption = argc - nbFichier - 1;

  printf("options : i %d d %d f %d nb d\'options: %d\n", i,d,f,nbChampsOption);


  // Si l'option f est activée, on ignore les avertissements.
  if (f)
  {
    for (int i = nbChampsOption +1; i < argc; i++)
    {
      effacerArgument(argv[i]);
      return 0;
    }
  }


  if(i)
  {
    for (int i = nbChampsOption +1; i < argc; i++)
    {
      retour = verification();
      if (retour ==1)
        effacerArgument(argv[i]);
    }
    return 0;
  }

  // Formule sans option, le d n'étant pas une option à gere
  // Car remove() supprime également les repertoires
  retour = verification();
  if (retour ==1)
  {
    for(int i = nbChampsOption+1; i < argc; i++)
    {
      printf("tout va bien %d\n",i);
      effacerArgument(argv[i]);
    }
  }
  return 0;
}

int verification()
{
  size_t tailleSaisie = 14; //Seul le premier caractère Y/N comptera, +1 pour \0
  char saisie[tailleSaisie];
  int saisieOk = 0;
  while (!saisieOk)
  {
    printf("Etes vous sûr(e) de vouloir supprimer ce(s) fichier(s) ?\n");
    printf("Yes/No ?\n");
    fgets(saisie,tailleSaisie, stdin);
    if (saisie[0] =='Y' || saisie[0] == 'y')
    {
      saisieOk = 1;
    } else if (saisie[0] == 'N' || saisie[0] == 'n')
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

  for(int i=1;i<argc;i++)
  {
    chaineCourante = argv[i];
    premierCaractere = chaineCourante[0];
    if(premierCaractere != '-')
    {
      *nbFichier += 1;
    }

  }
}
