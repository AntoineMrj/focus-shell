#ifndef MYRM_H
#define MYRM_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./comCommunication.h"
void rm(int argc, char *argv[]);
void compteFichiersArgs(int argc, char *argv[], int *nbFichier);
int effacerArgument(char *toDelete);
int verification();
#endif
