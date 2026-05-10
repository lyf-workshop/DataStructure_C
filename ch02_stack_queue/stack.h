#ifndef STACK_H
#define STACK_H

#include "utils.h"

#define STACK_SIZE 100

/* 顺序栈 */
typedef struct {
    ElemType data[STACK_SIZE];
    int top;
} Stack;

void   Stack_Init(Stack *S);
Status Stack_Push(Stack *S, ElemType e);
Status Stack_Pop(Stack *S, ElemType *e);
Status Stack_GetTop(Stack *S, ElemType *e);
bool   Stack_IsEmpty(Stack *S);

#endif
