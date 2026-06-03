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
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S) {
    if (S.base == NULL) return ERROR;
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack &S) {
    if (S.base == NULL) return ERROR;
    S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S.top == S.base) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int StackSize(SqStack S) {

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
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;

}

Status StackTraverse(SqStack &S,Status (*visit)(SElemType)) {
    return OK;
}

void conversion() {
    SqStack S;
    InitStack(S);
    int N;
    printf("Enter the number of elements you would like to convert: ");
    scanf("%d", &N);
    while (N) {
        Push(S,N%8);
        N/=8;
    }
    int e=0;
    while (!StackEmpty(S)) {
        Pop(S,e);
        printf("%d ",e);
    }
    DestroyStack(S);
}



int main(void) {
    conversion();
    return 0;
}

