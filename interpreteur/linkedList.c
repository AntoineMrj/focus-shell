#include "linkedList.h"

void add(commandList *list, cmdIdentifier function)
{
  commandListCell *newCell = (commandListCell *)malloc(sizeof(commandListCell)); //allocation de la mémoire pour la nouvelle cellule

  if (newCell == NULL)
  {
    printf("Allocation de mémoire impossible\n");
    exit(-1);
  }

  //creation de la Cellule
  newCell->function = function;
  newCell->next = NULL; //On ajoute la cellule à la fin

  if (list->head == NULL)
  { //si la liste et vide on met la cellule dans head
    list->head = newCell;
  }
  else
  { //sinon on cherche le dernier élément et on ajoute la cellule après
    commandListCell *currentCell = list->head;
    while (currentCell->next != NULL)
    { //on se place à la fin de la liste
      currentCell = currentCell->next;
    }
    currentCell->next = newCell; //on chaine la nouvelle cellule
  }
}
}

void freeList(commandList *list)
{
  commandListCell *head = list->head;
  commandListCell *tmp;
  while (head->next != NULL)
  { //Tant que la liste n'est pas vide on supprime decale la tete vers l'avant et on supprime la cellule
    tmp = head;
    head = head->next;
    free(tmp);
  }
  list->head = NULL; //une fois la liste vide on réinitialise la tete et la queue
}

cmdFunction find(commandList list, char *name) //renvoie la fonction si elle est trouvée
{
  commandListCell *currentFunction = list.head;
  while (strcmp(name, currentFunction->function.name) && currentFunction->next != NULL)
  { //tant que la fonction n'a pas été trouvée et qu'on est pas à la fin de la liste
    currentFunction = currentFunction->next;
  }
  if (!strcmp(name, currentFunction->function.name))
  {                                            //si la fonction a été trouvée
    return currentFunction->function.function; //retourne la commande
  }
  else
  {
    return 0; //A modifier, il faudrait renvoyer un message comme quoi la fonction n'existe pas ou une commande d'erreur
  }
}

commandList initializeList()
{
  commandList list;
  list.head = NULL;

  return list;
}
