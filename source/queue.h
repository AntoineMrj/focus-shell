#ifndef QUEUE_H
#define QUEUE_H
#include "command.h"
//Queue (fifo) avec ses fonctions

typedef struct commandQueueCell //liste FIFO doublement chainée
{
  command cmd;
  struct commandQueueCell *prev;
  struct commandQueueCell *next;
} commandQueueCell;

typedef struct commandQueue
{
  commandQueueCell *head;
} commandQueue;

//Ajoute une commande à la queue
void pushQ(commandQueue *queue, command *cmd);

//Ajoute une commande à la fin de la queue
void pushEndQ(commandQueue *queue, command *cmd); //ajoute la commande en fin de queue (fifo)

//Retourne la commande contenue dans la dernière cellule puis free de la cellule
command popQ(commandQueue *queue);

//Retourne une queue vide
commandQueue *initQueue();

//Retourne la commande en haut de la queue
command *getTopQ(commandQueue *queue);

//Ajoute la commande en tête de queue
void setTopQ(commandQueue *queue, command *cmd);

//Vide la queue (pops sucessifs)
void cleanQueue(commandQueue *queue);

#endif
