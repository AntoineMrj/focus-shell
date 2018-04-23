#include "du.h"

int du(int argc, char *argv[]){

  struct stat s;
  char *filename;
  char *dirname;
  DIR *dirp;
  struct dirent *dptr;
  long size=0;
  char* point;

  if(argc==1 || (argv[1][0]=='.' && !argv[1][1]) || (argv[1][1]=='.' && !argv[1][2])){ //si on ne met pas d'argument à la commande 'du' OU si l'argument passé est le répertoire courant (.) OU le répertoire parent (..)
    if(argc==1){ //si pas d'argument
      dirp = opendir(get_current_dir_name()); //on ouvre le répertoire courant
      point = "./";
    }
    else if(argv[1][1]=='.' && !argv[1][2]){ // si l'argument passé est le répertoire parent (..)
      dirp = opendir(argv[1]); ////on ouvre le répertoire parent
      point = "../";
    }
    else{ //si c'est le répertoire courant
      dirp = opendir(get_current_dir_name()); //on ouvre le répertoire courant
      point = "./";
    }
    while((dptr = readdir(dirp))){
      if ((dptr->d_type == DT_DIR)){ //si c'est un dossier, on affiche sa taille
        if((dptr->d_name[0]) != '.'){
          stat(dptr->d_name,&s);
          print("%li\t%s%s\n",s.st_size,point,dptr->d_name);
          size = size + s.st_size; //on ajoute la taille du dossier à 'size': la taille du dossier courant (.) ou parent (..)
        }
      }
      else{ //si c'est un fichier, on n'affiche pas sa taille, mais on l'ajoute à 'size'
        stat(dptr->d_name,&s);
        size = size + s.st_size;
      }
    }
    closedir(dirp);
    print("%li\t%s\n",size,point); //on affiche la taille du dossier courant (.) ou du dossier parent (..)
  }

  else{ //si on met un argument à la commande 'du'
    for(int i=1; i<argc; i++){
      if(!(dirp=opendir(argv[i]))){ //si cet argument est un fichier
        filename = argv[i];
        if(stat(filename,&s) != 0){
          print("Le fichier n'existe pas.\n");
        }
        else{
          print("%li\t%s\n",s.st_size,filename); //on affiche la taille du fichier
        }
      }
      else{ //si l'argument est un dossier
        dirname = argv[i];
        stat(dirname,&s);
        print("%li\t%s\n",s.st_size,dirname); //on affiche la taille du dossier
      }
    }
  }
  return 0;
}
