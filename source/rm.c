#include "rm.h"

int rm(int argc, char *argv[]){
  if(argc==1){
    printErr("rm: opérande manquant\n");
  }
  else{
    for(int i=1; i<argc; i++){
      if((remove(argv[i]))==-1){
        printErr("Le fichier '%s' n'existe pas.\n",argv[i]);
      }
    }
  }
  return 0;
}
