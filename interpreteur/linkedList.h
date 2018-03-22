#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "command.h"


//Cellule d'une liste chainée
typedef struct commandListCell{
    cmdIdentifier function;
    commandListCell* next;
    commandListCell* previous;
}commandListCell;

//Liste chainée
typedef struct commandList{
    commandListCell* head;
    commandListCell* tail;
}commandList;

//ajoute un élément à une liste chainée
//de préférence trié par ordre alphabétique
void add(commandList *list,cmdIdentifier function);

//libère une liste chainée
void freeList(commandList *list);

//trouve et renvoit la fonction principale d'une commande nommée name
//contenue dans une liste
cmdFunction find(commandList list, char* name);


#endif
