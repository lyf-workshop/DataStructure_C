#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0
#define INFEASIBLE   -1
#define OVERFLOW     -2
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define ElemType int
#include <stdlib.h>
typedef int Status;

#include <stdio.h>

typedef struct ListNode {
    ElemType data;
    struct ListNode *next;
}LNode,*LinkList;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *next;
    struct DuLNode *prior;
}DuLNode,*DuLinkList;

Status ListInsert_DuL(DuLinkList &L) {
    if (!())
        return ERROR;

}

typedef struct {
    ElemType data;
    int cur;
}component,SLinkList[LIST_INIT_SIZE];

int LocateElem_SL(SLinkList &S,ElemType e) {
    int i=S[0].cur;
    while (i&&S[i].data!=e) {
        i=S[i].cur;
    }
    return i;
}

void InitList_SL(SLinkList &space) {
    for (int i =0;i<LIST_INIT_SIZE-1;i++) {
        space[i].cur = i+1;
    }
    space[LIST_INIT_SIZE-1].cur = 0;
}

int Malloc_SL(SLinkList &space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
}

void Free_SL(SLinkList &space,int k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

Status GetElem_L(LinkList L,int i,ElemType &e) {
    LinkList p = L->next;
    int j=1;
    while (p&&j<i) {
        p = p->next;
        j++;
    }
    if (!p||j>i)return ERROR;
    e = p->data;
    return OK;
}

Status ListPriorInsert_L(LinkList &P,ElemType &e) {
    if (!P) return ERROR;
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if (!p) return ERROR;
    p ->next = P->next;
    P->next = p;
    p->data = P->data;
    P->data = e;
    return OK;
}

Status ListInsert_L(LinkList &L,int i,ElemType &e) {

    LinkList p = L;
    int j=0;
    while (p&&j<i-1) {
        p = p->next;
        j++;
    }
    if (!p||j>i-1)return ERROR;
    LNode *pnew = (LNode *)malloc(sizeof(LNode));
    pnew->data = e;
    pnew->next = p->next;
    p->next = pnew;
    return OK;
}

Status ListDelete_L(LinkList &L,int i,ElemType &e) {
    LinkList p = L;
    int j=0;
    while (p&&j<i-1) {
        p = p->next;
        j++;
    }
    if (!p->next||j>i-1)return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

void CreatList_L(LinkList &L,int n) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i =n;i>0;i--) {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
}

void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc) {
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc=pc=La;
    while (pa&&pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
        pc->next =pa?pa:pb;
        free(Lb);
    }
}

int main(void) {
    printf("hello world\n");
    LinkList La;
    CreatList_L(La,10);
    int i ,j=0;
    for (i=1;i<=10;i++) {
        GetElem_L(La,i,j);
        printf("%d\t",j);
    }
    LinkList Lb;
    CreatList_L(Lb,10);
    LinkList Lc;
    MergeList_L(La,Lb,Lc);
    for (i=1;i<=10;i++) {
        GetElem_L(Lc,i,j);
        printf("%d\t",j);
    }
    return 0;
}

