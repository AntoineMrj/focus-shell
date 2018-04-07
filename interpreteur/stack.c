#include "stack.h"

void push(commandStack *stack, command cmd) //ajoute la commande en haut de la stack (lifo)
{
  commandStackCell *newCell = malloc(sizeof(commandStackCell)); //création de la nouvelle cellule
  newCell->cmd = cmd;
  newCell->next = stack->head; //chainage avant
  stack->head = newCell; //actualisation de la nouvelle head
}

command pop(commandStack *stack)
{
  command cmd = stack->head->cmd; //on recupère la commande
  commandStackCell *tmp;
  tmp = stack->head;
  stack->head = stack->head->next; //on dépile la commande en mettant à jour la stack
  free(tmp); //on libère l'espace mémoire

  return cmd;
}
