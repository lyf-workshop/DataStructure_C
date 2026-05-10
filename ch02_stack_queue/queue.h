#ifndef QUEUE_H
#define QUEUE_H

#include "utils.h"

#define QUEUE_SIZE 100

/* 循环队列 */
typedef struct {
    ElemType data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void   Queue_Init(Queue *Q);
Status Queue_Enqueue(Queue *Q, ElemType e);
Status Queue_Dequeue(Queue *Q, ElemType *e);
Status Queue_GetFront(Queue *Q, ElemType *e);
bool   Queue_IsEmpty(Queue *Q);
int    Queue_Length(Queue *Q);

#endif
