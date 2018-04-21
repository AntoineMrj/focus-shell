#include "mkdir.h"

int makedir(int argc, char *argv[]){
  int j=0;
  int k;
  int canCreate=1;
  char *repertoire_courant = malloc(sizeof(char)*256);
  size_t size = 256;
  DIR *dirp;
  struct dirent *dptr;

  getcwd(repertoire_courant, size);
  dirp = opendir(repertoire_courant);
  while ((dptr = readdir(dirp))){
    j++;
  }
  closedir(dirp);

  dirp = opendir(repertoire_courant);
  char *liste_rep[j];
  k=0;
  while((dptr = readdir(dirp))){
    liste_rep[k] = dptr->d_name;
    k++;
  }
  closedir(dirp);

 if(argc<=1){
    printf("opérande manquant\n");
  }
  else{
    for (int i=1; i<argc; i++){
      canCreate = 1;
      for (int l=0; l<j; l++){
        if(strcmp(argv[i],liste_rep[l])==0){
          printf("impossible de créer le répertoire %s : ce nom de fichier existe déjà\n", argv[i]);
          canCreate = 0;
          break;
        }
      }
      if(canCreate==1)
      {
        mkdir(argv[i],ACCESSPERMS);
      }
    }
  }
  return 0;
}
