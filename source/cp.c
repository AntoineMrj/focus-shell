#include "cp.h"

void cp(int argc, char *argv[])
{
  DIR *destination = NULL;
  FILE *source = NULL;
  FILE *copieSource = NULL;

  if(argc<2){
    printErr("cp: opérande manquant\n");
  }
  else{
    destination = opendir(argv[argc-1]);

    if(destination==NULL){ //si le dernier argument n'est pas un répertoire mais un fichier
      if(argc>3){ //si on a plus de 2 noms de fichier en argument, alors on s'attend à copier les (n-1) premiers fichiers dans le n-ième argument qui doit être un réperoire. Or celui ci est un fichier.
        printErr("La cible '%s' n'est pas un répertoire.\n",argv[argc-1]); //Donc on renvoie une erreur.
        return;
      }
      else{ //si on a 2 noms de fichiers en argument, alors on copie le 1er fichier sous le nom du 2ème fichier, dans le répertoire courant
        source = fopen(argv[1], "r"); //on ouvre le fichier source
        copieSource = fopen(argv[2], "w"); //on ouvre le fichier qui sera une copie de la source (s'il n'existe pas il sera créé automatiquement)
        char chaine[1000] = "";

        if (source == NULL) //si le fichier source n'existe pas
        {
          printErr("Le fichier source \"%s\" est introuvable.\n", argv[1]);
          return;
        }
        while (fgets(chaine, 1000, source) != NULL) //copie ligne par ligne du fichier source
        {
          fputs(chaine, copieSource);
        }
        fclose(source); //on ferme le fichier source
        fclose(copieSource); //on ferme la copie du fichier source
      }
    }
    else{ //si le dernier argument est un répertoire
      closedir(destination);
      for(int i=1; i<argc-1; i++){ //on copie les (n-1) fichiers dans le répertoire

        char *dest = malloc(sizeof(char)*256);
        strcpy(dest,argv[argc-1]);

        strcat(dest,"/"); //on concatène le chemin de destination avec le séparateur '/' ...
        strcat(dest,argv[i]); //...puis avec le nom du fichier source

        copieSource = fopen(dest, "w"); //ainsi on crée une copie de la source dans le répertoire de destination
        source = fopen(argv[i], "r");

        char chaine[1000] = "";
        if (source == NULL) //si le fichier à copier n'existe pas
        {
          printErr("Le fichier source \"%s\" est introuvable.\n", argv[i]);
          return;
        }
        while (fgets(chaine, 1000, source) != NULL) //copie ligne par ligne du fichier source
        {
          fputs(chaine, copieSource);
        }
        fclose(source);
        fclose(copieSource);
      }
    }
  }
}
