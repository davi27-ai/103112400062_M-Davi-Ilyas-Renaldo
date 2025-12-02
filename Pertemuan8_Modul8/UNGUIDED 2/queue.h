#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h> 

#define MAX_QUEUE 5

typedef int infotype; 

typedef struct {
    infotype info[MAX_QUEUE]; 
    int head;
    int tail;
} Queue;

void createQueue(Queue *Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
bool enqueue(Queue *Q, infotype x);
infotype dequeue(Queue *Q);
void printInfo(Queue Q);

#endif