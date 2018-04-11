#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char*argv[]){

  char* repertoire_courant = malloc(sizeof(char)*256);
  size_t size = 256;

  getcwd(repertoire_courant, size);

  printf("%s\n",repertoire_courant);

  return 0;

}
