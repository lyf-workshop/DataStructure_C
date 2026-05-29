#include "static_linked_list.h"

int LocateElem_SL(SLinkList &S, ElemType e) {
    int i = S[0].cur;
    while (i && S[i].data != e) {
        i = S[i].cur;
    }
    return i;
}

void InitList_SL(SLinkList &space) {
    for (int i = 0; i < LIST_INIT_SIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[LIST_INIT_SIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList &space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SL(SLinkList &space, int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

Status ListInsert_SL(SLinkList &S, int i, ElemType e) {
    return ERROR;
}

Status ListDelete_SL(SLinkList &S, int i, ElemType &e) {
    return ERROR;
}

int ListLength_SL(SLinkList S) {
    return 0;
}

void difference(SLinkList &space, int &S) {
    InitList_SL(space);
    S = Malloc_SL(space);
}

void PrintList_SL(SLinkList S) {
}
