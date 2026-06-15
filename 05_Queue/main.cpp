#include "../common/utils.h"

typedef char QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front) exit(OVERFLOW);
    Q.front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q) {
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q, QElemType &e) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) return ERROR;
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    free(p);
    return OK;
}

//循环队列
#define MAXQSIZE 100

typedef struct {
    QElemType *base;
    int rear;
    int front;
}SqQueue;

Status InitSqQueue(SqQueue &Q) {
    Q.base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if (Q.base) exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

int SqQueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}

Status EnSqQueue(SqQueue &Q, QElemType &e) {
    if ((Q.rear+1)%MAXQSIZE == Q.front) return ERROR;//队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeSqQueue(SqQueue &Q, QElemType &e) {
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1)%MAXQSIZE;
    return OK;
}

int main(void) {

    return 0;
}
