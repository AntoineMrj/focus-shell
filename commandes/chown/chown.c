#include "chown.h"

int chowner(int argc, char *argv[]){

  char *fichier;
  uid_t uid; //identifiant de l'utilisateur
  struct passwd *pwd; //structure contenant les divers champs de l'enregistrement de la base de données des mots de passe

  if(argc==1){
    print("chown: opérande manquant\n");
  }
  else if(argc==2){
    print("chown: opérande manquant après '%s'\n",argv[1]);
  }
  else{
    pwd = getpwnam(argv[1]);
    if (pwd == NULL){
      print("Nom d'utilisateur incorrect\n");
      return -1;
    }
    uid = pwd->pw_uid;
    fichier = argv[2];
    if(chown(fichier, uid,-1) == -1){
      print("Nom de fichier incorrect\n");
    }
  }
  return 0;
}
