#ifndef QUEUE_H
#define QUEUE_H
#include "command.h"
//Queue (fifo) avec ses fonctions

typedef struct commandQueueCell
{
  command cmd;
  commandQueueCell *next;
}commandQueueCell;


typedef struct commandQueue
{
  commandQueueCell *head;
}commandQueue;

void push(commandQueue *queue, command cmd);
command pop(commandQueue *queue);
commandQueue *initQueue(); //retourne une queue vide

#endif
