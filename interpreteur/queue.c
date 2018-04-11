#include "queue.h"

void push(commandQueue *queue, command cmd) //ajoute la commande en tête de queue (fifo)
{
  commandQueueCell * newCell = malloc(sizeof(commandQueueCell)); //création de la nouvelle cellule
  newCell->cmd = cmd;
  newCell->next = queue->head; //chainage avant
  stack->head = newCell; //actualisation de la nouvelle tête
}

void push(commandQueue *queue, command *cmd) //ajoute la commande en tête de queue (fifo)
{
  commandQueueCell * newCell = malloc(sizeof(commandQueueCell)); //création de la nouvelle cellule
  newCell->cmd = cmd;
  newCell->next = queue->head; //chainage avant
  queue->head = newCell; //actualisation de la nouvelle tête
}

char* pop(commandQueue *queue)
{
  commandQueueCell *currentCell = queue->head;

  while(currentCell->next->next != NULL) //on va à l'avant dernière cellule de la queue
  {
    currentCell = currentCell->next;
  }

  char *cmd = currentCell->next->cmd; //on recupère la commande de la dernière cellule
  commandQueueCell *tmp;
  tmp = currentCell->next; //dernière cellule
  currentCell->next = NULL; //l'avant dernière cellule devient la dernière cellule
  free(tmp); //on libère l'espace mémoire de la cellule qu'on vient de dépiler

  return cmd;
}
