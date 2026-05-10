#include "linked_list.h"

void LL_Init(LinkedList *L) {
    *L = (LNode *)malloc(sizeof(LNode));  /* 带头结点 */
    (*L)->next = NULL;
}

void LL_Destroy(LinkedList *L) {
    LNode *p = (*L)->next;
    while (p) {
        LNode *tmp = p->next;
        free(p);
        p = tmp;
    }
    free(*L);
    *L = NULL;
}

Status LL_Insert(LinkedList L, int i, ElemType e) {
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1) { p = p->next; j++; }
    if (!p) return ERROR;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status LL_Delete(LinkedList L, int i, ElemType *e) {
    LNode *p = L;
    int j = 0;
    while (p->next && j < i - 1) { p = p->next; j++; }
    if (!p->next) return ERROR;

    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

Status LL_GetElem(LinkedList L, int i, ElemType *e) {
    LNode *p = L->next;
    int j = 1;
    while (p && j < i) { p = p->next; j++; }
    if (!p) return ERROR;
    *e = p->data;
    return OK;
}

int LL_LocateElem(LinkedList L, ElemType e) {
    LNode *p = L->next;
    int i = 1;
    while (p) {
        if (p->data == e) return i;
        p = p->next;
        i++;
    }
    return 0;
}

int LL_Length(LinkedList L) {
    int len = 0;
    LNode *p = L->next;
    while (p) { p = p->next; len++; }
    return len;
}

void LL_Print(LinkedList L) {
    printf("LinkedList: ");
    LNode *p = L->next;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
