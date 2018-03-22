#include "linkedList.h"

void add(commandList *list,cmdIdentifier function)
{

}

void add(commandList *list,cmdIdentifier function)
{
  commandListCell *newCell = (commandListCell*)malloc(sizeof(commandListCell)); //allocation de la mémoire pour la nouvelle cellule

  if (newCell == NULL) {
    printf("Allocation de mémoire impossible\n");
    exit(-1);
  }

//creation de la Cellule
newCell->function = function;
newCell->next=NULL; //Pour l'instant pas de classement par ordre alphabétique donc on ajoute la cell a la fin

if(list->head == NULL){ //si la liste et vide on met la cellule dans head et tail
  newCell->previous = NULL;
  list->head = newCell;
  list->tail = newCell;
}
else{ //sinon on cherche le dernier élément et on ajoute la cellule après
  commandListCell *currentCell = list->head;
  while(1){
    if (currentCell->next == NULL){ //on a atteint la fin de la liste
      newCell->previous = currentCell;
      currentCell->next = newCell;
      list->tail = newCell;
      break;
    }
    currentCell = currentCell->next;
  }
}
}
void freeList(commandList *list)
{

}
cmdFunction find(commandList list, char* name)
{

}
