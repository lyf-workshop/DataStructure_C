#include "queue.h"

void Queue_Init(Queue *Q) {
    Q->front = Q->rear = 0;
}

Status Queue_Enqueue(Queue *Q, ElemType e) {
    if ((Q->rear + 1) % QUEUE_SIZE == Q->front) return ERROR;  /* 队满 */
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % QUEUE_SIZE;
    return OK;
}

Status Queue_Dequeue(Queue *Q, ElemType *e) {
    if (Q->front == Q->rear) return ERROR;  /* 队空 */
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % QUEUE_SIZE;
    return OK;
}

Status Queue_GetFront(Queue *Q, ElemType *e) {
    if (Q->front == Q->rear) return ERROR;
    *e = Q->data[Q->front];
    return OK;
}

bool Queue_IsEmpty(Queue *Q) {
    return Q->front == Q->rear;
}

int Queue_Length(Queue *Q) {
    return (Q->rear - Q->front + QUEUE_SIZE) % QUEUE_SIZE;
}
