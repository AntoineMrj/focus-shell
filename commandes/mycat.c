#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char*argv[]){
  int i;
  int byte_lu;
  char tampon [1024];
  size_t fd;

  for (i=1; i<argc; i++){
    fd = open(argv[i],O_RDONLY);

    if(fd==-1){
      printf("these file does not exist, check the name\n");
      return(2);
    }

    else{
      while((byte_lu=read(fd,tampon,1024)) >0)
        fd = write(STDOUT_FILENO,tampon,byte_lu);

      close(fd);
    }

    return(0) ;
  }
}
