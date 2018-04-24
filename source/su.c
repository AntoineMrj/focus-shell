#include "su.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void su(int argc, char *argv[])
{
  //Si il n'y a pas d'arguments a la fonction su,
  // Le but est de passer super user
  if (argc == 0)
  {
    // 0 est l'uid root
    seteuid(0);
  }
}
]
