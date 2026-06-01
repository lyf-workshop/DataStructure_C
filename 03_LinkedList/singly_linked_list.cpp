#include "singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Status InitList_L(LinkList &L) {
    return ERROR;
}

Status DestroyList_L(LinkList &L) {
    return ERROR;
}

Status ClearList_L(LinkList &L) {
    return ERROR;
}

Status ListEmpty_L(LinkList L) {
    return FALSE;
}

int ListLength_L(LinkList L) {
    return 0;
}

Status GetElem_L(LinkList L, int i, ElemType &e) {
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

int LocateElem_L(LinkList L, ElemType e) {
    return 0;
}

Status ListPriorInsert_L(LinkList &P, ElemType &e) {
    if (!P) return ERROR;
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if (!p) return ERROR;
    p->next = P->next;
    P->next = p;
    p->data = P->data;
    P->data = e;
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType &e) {
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1) return ERROR;
    LNode *pnew = (LNode *)malloc(sizeof(LNode));
    if (!pnew) return ERROR;
    pnew->data = e;
    pnew->next = p->next;
    p->next = pnew;
    return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
    LinkList p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || !p->next || j > i - 1) return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

void CreatListPrior_L(LinkList &L, int n) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = n; i > 0; i--) {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}


void CreateList_R(LinkList &L, int n) {
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

void PrintList_L(LinkList L) {
}
