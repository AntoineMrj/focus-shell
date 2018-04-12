#ifndef STACK_H
#define STACK_H
#include "command.h"
//pile de base avec ses fonctions

typedef struct commandStackCell
{
  command cmd;
  commandStackCell *next;
}commandStackCell;


typedef struct commandStack
{
  commandStackCell *head;
}commandStack;

void push(commandStack *stack, command cmd);
command pop(commandStack *stack);
commandStack *initStack(); //retourne une stack vide

#endif
