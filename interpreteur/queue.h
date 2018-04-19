#ifndef QUEUE_H
#define QUEUE_H
#include "command.h"
//Queue (fifo) avec ses fonctions

typedef struct commandQueueCell
{
  command cmd;
  struct commandQueueCell *prev;
  struct commandQueueCell *next;
} commandQueueCell;

typedef struct commandQueue
{
  commandQueueCell *head;
} commandQueue;

void pushQ(commandQueue *queue, command *cmd);
void pushEndQ(commandQueue *queue, command *cmd); //ajoute la commande en fin de queue (fifo)
command popQ(commandQueue *queue);
commandQueue *initQueue(); //retourne une queue vide
command *getTopQ(commandQueue *queue);
void setTopQ(commandQueue *queue, command *cmd);
#endif
