#include "chgrp.h"

int chgrp(int argc, char *argv[]){

  char *fichier;
  gid_t gid; //identifiant du groupe
  struct group *grp; //structure contenant les champs partiels d'un enregistrement de la base de données de groupe

  if(argc==1){
    print("chgrp: opérande manquant\n");
  }
  else if(argc==2){
    print("chgrp: opérande manquant après '%s'\n",argv[1]);
  }
  else{
    grp = getgrnam(argv[1]);
    if (grp == NULL){
      print("Nom de groupe incorrect\n");
      return -1;
    }
    gid = grp->gr_gid;
    fichier = argv[2];
    if(chown(fichier, -1, gid) == -1){
      print("Nom de fichier incorrect\n");
    }
  }
  return 0;
}
