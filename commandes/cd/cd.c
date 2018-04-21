#include "cd.h"

void cd(int argc, char *argv[]){
  char *dir;
  char *repertoire_courant = malloc(sizeof(char) * 256);
  size_t size = 256;

  if(argc==1){
    dir = getenv("HOME");
  }
  else{
    if (!strcmp(argv[1], "~")){
      dir = getenv("HOME");
    }
    else{
      dir = argv[1];
    }
  }

  if((chdir(dir))==-1){
    printf("\nDirectory change failed.\n");
  }
  else{
    getcwd(repertoire_courant, size);
    printf("%s\n", repertoire_courant);
  }

}
