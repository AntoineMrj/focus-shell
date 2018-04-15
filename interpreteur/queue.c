#include "queue.h"


void pushQ(commandQueue *queue, command *cmd) //ajoute la commande en tête de queue (fifo)
{
  commandQueueCell * newCell = malloc(sizeof(commandQueueCell)); //création de la nouvelle cellule
  newCell->cmd = *cmd;
  newCell->next = queue->head; //chainage avant
  queue->head = newCell; //actualisation de la nouvelle tête
}

command* popQ(commandQueue *queue)
{
  commandQueueCell *currentCell = queue->head;

  while(currentCell->next->next != NULL) //on va à l'avant dernière cellule de la queue
  {
    currentCell = currentCell->next;
  }

  command *cmd = &(currentCell->next->cmd); //on recupère la commande de la dernière cellule
  commandQueueCell *tmp;
  tmp = currentCell->next; //dernière cellule
  currentCell->next = NULL; //l'avant dernière cellule devient la dernière cellule
  free(tmp); //on libère l'espace mémoire de la cellule qu'on vient de dépiler

  return cmd;
}

commandQueue *initQueue()
{
  commandQueue *queue = malloc(sizeof(commandQueue)); //réservation de l'espace mémoire pour la Queue
  queue->head = NULL; //initialisation de la queue;

  return queue;
}
