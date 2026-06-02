#include "../common/utils.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef ElemType SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S) {
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(S.top-1);
    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType*)realloc(S.base, (S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);
        S.top = S.base+S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top++) = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if (S.top = S.base) {
        e = *--S.top;
        return OK;
    }
}

int main(void) {

    return 0;
}

