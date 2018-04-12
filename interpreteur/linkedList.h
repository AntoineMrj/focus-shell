#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "stdlib.h"
#include "command.h"

//Cellule d'une liste chainée
typedef struct commandListCell
{
    cmdIdentifier function;
    commandListCell *next;
} commandListCell;

//Liste chainée
typedef struct commandList
{
    commandListCell *head;
} commandList;

//ajoute un élément à une liste chainée
//de préférence trié par ordre alphabétique
void add(commandList *list, cmdIdentifier function);

//libère une liste chainée
void freeList(commandList *list);

//trouve et renvoit la fonction principale d'une commande nommée name
//contenue dans une liste
cmdFunction find(commandList list, char *name);

//Retourne un pointeur vers une liste vide
commandList *initList();

#endif
