#include "stack.h"

void Stack_Init(Stack *S) {
    S->top = -1;
}

Status Stack_Push(Stack *S, ElemType e) {
    if (S->top == STACK_SIZE - 1) return ERROR;
    S->data[++S->top] = e;
    return OK;
}

Status Stack_Pop(Stack *S, ElemType *e) {
    if (S->top == -1) return ERROR;
    *e = S->data[S->top--];
    return OK;
}

Status Stack_GetTop(Stack *S, ElemType *e) {
    if (S->top == -1) return ERROR;
    *e = S->data[S->top];
    return OK;
}

bool Stack_IsEmpty(Stack *S) {
    return S->top == -1;
}
