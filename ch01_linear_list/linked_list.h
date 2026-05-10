#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "utils.h"

typedef struct LNode {
    ElemType       data;
    struct LNode  *next;
} LNode, *LinkedList;

void   LL_Init(LinkedList *L);
void   LL_Destroy(LinkedList *L);
Status LL_Insert(LinkedList L, int i, ElemType e);
Status LL_Delete(LinkedList L, int i, ElemType *e);
Status LL_GetElem(LinkedList L, int i, ElemType *e);
int    LL_LocateElem(LinkedList L, ElemType e);
int    LL_Length(LinkedList L);
void   LL_Print(LinkedList L);

#endif
