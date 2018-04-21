#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include "commandFunction.h"
#include "command.h"

//Structure identifiant une commande par une chaine de caractère
typedef struct cmdIdentifier
{
    cmdFunction function;
    char *name;
} cmdIdentifier;

//Cellule d'une liste chainée
typedef struct commandListCell
{
    cmdIdentifier *function;
    struct commandListCell *next;
} commandListCell;

//Liste chainée
typedef struct commandList
{
    commandListCell *head;
} commandList;

//ajoute un élément à une liste chainée
//de préférence trié par ordre alphabétique
void add(commandList *list, cmdIdentifier *function);

//libère une liste chainée
void freeList(commandList *list);

//trouve et renvoit la fonction principale d'une commande nommée name
//contenue dans une liste
cmdFunction find(commandList *list, char *name);

//Vérifie si la chaine passée en paramètre correspond a un executable (de la forme "./"...".exe") et qu'il existe bien
int isProgram(char *name);

//Retourne un pointeur vers une liste vide
commandList *initList();
//Ajoute un cmdIdentifieur à la liste en l'initialisant avec le nom et la fonction passé en paramètre
void addCmdIdentifier(commandList *list, char *name, cmdFunction function);

#endif
