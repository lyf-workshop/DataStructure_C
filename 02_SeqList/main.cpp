#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0
#define INFEASIBLE   -1
#define OVERFLOW     -2
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#include <stdlib.h>
typedef int Status;
#include <stdio.h>

#define ElemType int

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}Sqlist;

Status InitList_Sq(Sqlist &L) {
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

Status SqlistInsert_Sq(Sqlist &L, int i, ElemType e) {
    if (i<1||i>L.length) {
        return ERROR;
    }
    if (L.length >= L.listsize) {
        ElemType* newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LIST_INCREMENT;
    }
    int* q = &L.elem[i-1];
    for (int* p=&(L.elem[L.length-1]); p>=q; p-- )  *(p+1) = *p;
    *q = e;
    L.length++;
    return OK;
}

int main()
{
    return 0;
}