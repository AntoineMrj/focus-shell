#ifndef QUEUE_H
#define QUEUE_H
#include "command.h"
//Queue (fifo) avec ses fonctions

typedef struct commandQueueCell
{
  command cmd;
  struct commandQueueCell *next;
}commandQueueCell;


typedef struct commandQueue
{
  commandQueueCell *head;
}commandQueue;

void pushQ(commandQueue *queue, command *cmd);
command* popQ(commandQueue *queue);
commandQueue *initQueue(); //retourne une queue vide

#endif
