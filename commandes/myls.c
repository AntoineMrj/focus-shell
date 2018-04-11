#include "myls.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
  DIR *dirp;
  struct dirent *dptr;
  char* repertoire_courant = malloc(sizeof(char)*256);
  size_t size = 256;

  if (argv[1] == NULL)
    getcwd(repertoire_courant, size);
  else
    repertoire_courant = argv[1];

  if ((dirp=opendir(repertoire_courant))==NULL){
    printf("Error\n");
    return(-1);
  }

  while ((dptr=readdir(dirp))){
    if (dptr->d_name[0] != '.')
      printf("%s\n",dptr->d_name);
  }
  closedir(dirp);

  return 0;
}
