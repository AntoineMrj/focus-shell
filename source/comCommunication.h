#ifndef FOCUSCOMCOMMAND_H
#define FOCUSCOMCOMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

typedef enum e_outPutMode {
    CONSOLE_MODE,
    LOGFILE_MODE,
    BASHFILE_MODE,
    NONE_MODE
} e_outPutMode;
//Envoit du résultat de la commande
//Agit comme un printf
int print(char *str, ...);
int printErr(char *str, ...);
#endif