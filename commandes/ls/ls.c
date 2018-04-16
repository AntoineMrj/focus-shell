#include "ls.h"

int ls(int argc, char *argv[])
{
  DIR *dirp;
  struct dirent *dptr;
  char *repertoire_courant = malloc(sizeof(char) * 256);
  size_t size = 256;
  if (argv[1] == NULL || argv[1] == ' ' || argv[1] == '.' || argv[1] == '\n' || argv[1] == '\0' || argc == 1)
  {
    getcwd(repertoire_courant, size);
  }
  else
  {
    repertoire_courant = argv[1];
  }
  if ((dirp = opendir(repertoire_courant)) == NULL)
  {
    printf("Erreur le dossier %s n'existe pas.\n", argv[1]);
    return (-1);
  }

  while ((dptr = readdir(dirp)))
  {
    if (dptr->d_name[0] != '.')
      printf("%s\n", dptr->d_name);
  }
  closedir(dirp);

  return 0;
}
