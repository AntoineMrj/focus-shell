#include "ls.h"

//Fonction pour ls-l (affiche en plus les informations du fichier en argument)
void show_file_info(char *filename, struct stat *info_p)
{
	char modestr[11]; //chaîne de 12 caractères (0->11) qui va contenir le mode
	mode_to_letters(info_p->st_mode, modestr);

	print("%s %d %s %s %ld %.12s ", modestr, (int)info_p->st_nlink, uid_to_name(info_p->st_uid), gid_to_name(info_p->st_gid), (long)info_p->st_size, 4+ctime(&info_p->st_mtime));
  print(GRN "%s\n" RESET , filename);
}


//Fonction pour convertir le mode (droits d'un fichier) en lettres
void mode_to_letters(int mode, char str[])
{
	strcpy(str, "----------");

	if(S_ISDIR(mode)) str[0] = 'd';		//répertoire
	if(S_ISCHR(mode)) str[0] = 'c';		//périphérique de type caractère
	if(S_ISBLK(mode)) str[0] = 'b';		//périphérique de type bloc

	if(mode & S_IRUSR) str[1] = 'r';	//3 bits pour l'utilisateur
	if(mode & S_IWUSR) str[2] = 'w';
	if(mode & S_IXUSR) str[3] = 'x';

	if(mode & S_IRGRP) str[4] = 'r';	//3 bits pour le groupe
	if(mode & S_IWGRP) str[5] = 'w';
	if(mode & S_IXGRP) str[6] = 'x';

	if(mode & S_IROTH) str[7] = 'r';	//3 bits pour les autres
	if(mode & S_IWOTH) str[8] = 'w';
	if(mode & S_IXOTH) str[9] = 'x';

}


//Fonction qui renvoie un pointeur sur le nom de l'utilisateur associé à uid
char *uid_to_name(uid_t uid)
{
	struct passwd *getpwuid(), *pw_ptr;
	static char numstr[10];

	if((pw_ptr = getpwuid(uid)) == NULL){
		sprintf(numstr, "%d", uid);
		return numstr;
	}
	else
		return pw_ptr->pw_name;
}

//Fonction qui renvoie un pointeur sur le nom du groupe associé à gid
char *gid_to_name(gid_t gid)
{
	struct group *getgrgid(), *grp_ptr;
	static char numstr[10];

	if((grp_ptr = getgrgid(gid)) == NULL){
		sprintf(numstr, "%d", gid);
		return numstr;
	}
	else
		return grp_ptr->gr_name;
}


//Fonction pour parcourir un dossier
void parcoursDossier(int a, int l, char *repertoire_courant){
  int nb;
  int i;
  struct dirent *dptr;
  DIR *dirp;
  struct stat s;

  dirp = opendir(repertoire_courant);
  //Détermination du nombre l de ficheirs dans le dossier courant:
  nb=0;
  while ((dptr = readdir(dirp)))
  {
    if(a==1)
      nb++;
    else{
      if (dptr->d_name[0] != '.'){
        nb++;
      }
    }
  }
  closedir(dirp);

  i=0;
  dirp = opendir(repertoire_courant);
  while ((dptr = readdir(dirp)))
  {
    if(a==1){
      i++;
      if(l){
        stat(dptr->d_name,&s);
        show_file_info(dptr->d_name,&s);
      }
      else if(i==nb)
        print(GRN "%s\n" RESET, dptr->d_name);
      else
        print(GRN "%s " RESET, dptr->d_name);
    }
    else{
      if (dptr->d_name[0] != '.'){
        i++;
        if(l){
          stat(dptr->d_name,&s);
          show_file_info(dptr->d_name,&s);
        }
        else if(i==nb)
          print(GRN "%s\n" RESET, dptr->d_name);
        else
          print(GRN "%s " RESET, dptr->d_name);
      }
    }
  }
  closedir(dirp);
}

//Fonction principale de ls
void ls(int argc, char *argv[]){
  DIR *dirp;
  char *repertoire_courant = malloc(sizeof(char) * 256);
  size_t size = 256;
  int a=0;
  int l=0;
  char optstring[]="al";
  int c;
  struct stat s;
  int argc2 = argc;

  while((c=getopt(argc, argv, optstring)) != -1){
    switch(c){
      case 'a':
            a=1;
            argc2--;
            break;
      case 'l':
            l=1;
            argc2--;
            break;
      case '?':
            printErr("Ligne de commande incorrecte.\n");
            return;
    }
  }

  if (argc2 == 1)
  {
    getcwd(repertoire_courant, size);
    parcoursDossier(a, l, repertoire_courant);
  }
  else
  {
    for(int i=1; i<argc; i++){
      if(argv[i][0]!='-'){
        repertoire_courant = argv[i];
        if ((dirp = opendir(repertoire_courant)) == NULL) //si l'argument n'est pas un repertoire mais un fichier
        {
          if(i+1!=argc){
            if(l){
              stat(argv[i],&s);
              show_file_info(argv[i],&s);
            }
            else
              print(GRN "%s " RESET,argv[i]); //on affiche le nom du fichier
          }
          else{
            if(l){
              stat(argv[i],&s);
              show_file_info(argv[i],&s);
            }
            else
              print(GRN "%s\n" RESET,argv[i]);
          }
        }
        else //si l'argument est un dossier
        {
          parcoursDossier(a, l, repertoire_courant);
        }
      }
    }
  }
}
