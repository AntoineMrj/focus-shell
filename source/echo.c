#include "echo.h"

void echo(int argc, char *argv[])
{
  int c;
  int n=0;
  char optstring[]="n";
  int argc2 = argc;

  while((c=getopt(argc, argv, optstring)) != -1){
    switch(c){
      case 'n':
            n=1;
            argc2--;
            break;
    }
  }

  for(int i=1; i<argc; i++)
    if(argv[i][0]!='-'){
      if(i+1!=argc)
        print("%s ", argv[i]);
      else
        print("%s", argv[i]);
    }

  if(!n)
    print("\n");
}
