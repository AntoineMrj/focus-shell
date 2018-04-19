#include "queue.h"

void pushQ(commandQueue *queue, command *cmd) //ajoute la commande en tête de queue (fifo)
{
  commandQueueCell *newCell = malloc(sizeof(commandQueueCell)); //création de la nouvelle cellule
  newCell->cmd = *cmd;
  newCell->next = queue->head; //chainage avant

  if (queue->head != NULL) //si la queue est non vide
  {
    queue->head->prev = newCell; //chainage arrière de la tête
  }

  queue->head = newCell; //actualisation de la nouvelle tête
}
void pushEndQ(commandQueue *queue, command *cmd) //ajoute la commande en fin de queue (fifo)
{
  commandQueueCell *newCell = malloc(sizeof(commandQueueCell)); //création de la nouvelle cellule
  newCell->cmd = *cmd;
  newCell->next = queue->head; //chainage avant

  if (queue->head == NULL) //si la queue est non vide
  {
    queue->head = newCell; //actualisation de la nouvelle tête
  }
  else
  {
    commandQueueCell *cell = queue->head;
    while (cell->next != NULL)
    {
      cell = cell->next;
    }
    cell->next = newCell;
  }
}

command popQ(commandQueue *queue) //on peut faire plus propre avec une liste doublement chainée
{
  command cmd; //sert à stocker la command à pop
  commandQueueCell *currentCell = queue->head;

  if (currentCell == NULL)
    return cmd; //la queue est vide /!\ Renvoyer NULL ne marche pas HELP /!\ 

  else          //plus de 2 cellules
  {
    while (currentCell->next != NULL) //on va à la dernière cellule de la queue
    {
      currentCell = currentCell->next;
    }
    cmd = currentCell->cmd;         //on recupère la commande de la dernière cellule
    if (currentCell == queue->head) //si il n'y a qu'une seule cellule dans la queue
    {
      queue->head = NULL;
    }
    else
    {
      currentCell->prev->next = NULL; //l'avant dernière cellule devient la dernière cellule
      free(currentCell);              //on libère l'espace mémoire de la cellule qu'on vient de dépiler
    }
  }

  return cmd;
}

commandQueue *initQueue()
{
  commandQueue *queue = malloc(sizeof(commandQueue)); //réservation de l'espace mémoire pour la Queue
  queue->head = NULL;                                 //initialisation de la queue;

  return queue;
}
command *getTopQ(commandQueue *queue)
{
  if (queue->head != NULL)
  {
    commandQueueCell *currentCell = queue->head;
    while (currentCell->next != NULL) //on va à la dernière cellule de la queue
    {
      currentCell = currentCell->next;
    }
    return &(currentCell->cmd);
  }
  else
    return NULL;
}
void setTopQ(commandQueue *queue, command *cmd) //ajoute la commande en tête de queue (fifo)
{
  commandQueueCell *currentCell = queue->head;
  while (currentCell->next != NULL) //on va à la dernière cellule de la queue
  {
    currentCell = currentCell->next;
  }
  currentCell->cmd = *cmd;
}