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
void add(commandList *list, cmdIdentifier *function);

//libère une liste chainée
void freeList(commandList *list);

//trouve et renvoie la fonction principale d'une commande nommée name contenue dans une liste
cmdFunction find(commandList *list, char *name);

//Retourne un pointeur vers une liste vide
commandList *initList();

//Ajoute un cmdIdentifier à la liste en l'initialisant avec le nom et la fonction passée en paramètre
void addCmdIdentifier(commandList *list, char *name, cmdFunction function);

#endif
