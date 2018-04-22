#include "linkedList.h"

void add(commandList *list, cmdIdentifier *function)
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
  { //si la liste est vide on met la cellule dans head
    list->head = newCell;
  }
  else
  { //sinon on cherche le dernier élément et on ajoute la cellule après
    commandListCell *currentCell = list->head;
    while (currentCell->next != NULL)
    { //on se place à la fin de la liste
      currentCell = currentCell->next;
    }
    currentCell->next = newCell; //on chaîne la nouvelle cellule
  }
}

//supprime une liste chainée et libère sa mémoire
void freeList(commandList *list)
{
  commandListCell *head = list->head;
  commandListCell *tmp;
  while (head->next != NULL)
  { //Tant que la liste n'est pas vide on decale la tete vers l'avant et on supprime la cellule
    tmp = head;
    head = head->next;
    free(tmp);
  }
  list->head = NULL; //une fois la liste vide on réinitialise la tete et la queue
}

//renvoie la fonction si elle est trouvée
cmdFunction find(commandList *list, char *name)
{
  if (list != NULL)
  {
    commandListCell *currentFunction = list->head;
    while (currentFunction != NULL && strcmp(name, currentFunction->function->name) != 0)
    {
      //tant que la fonction n'a pas été trouvée et qu'on est pas à la fin de la liste
      currentFunction = currentFunction->next;
    }
    if (currentFunction != NULL)
    {
      //si la fonction a été trouvée
      return currentFunction->function->function; //retourne la commande
    }
  }

  return NULL;
}

//Retourne un pointeur vers une liste vide
commandList *initList()
{
  commandList *list = malloc(sizeof(commandList));
  list->head = NULL;

  return list;
}

//Ajoute un cmdIdentifier à la liste en l'initialisant avec le nom et la fonction passée en paramètre
void addCmdIdentifier(commandList *list, char *name, cmdFunction function)
{
  //déclaration du pointeur qui va contenir les fonctions une à une
  //création des cmdIdentifier
  cmdIdentifier *newCmdIdentifier = malloc(sizeof(cmdIdentifier));
  newCmdIdentifier->function = function;
  newCmdIdentifier->name = name;
  //ajout de la cellule
  add(list, newCmdIdentifier);
}
