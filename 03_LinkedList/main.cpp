#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0
#define INFEASIBLE   -1
#define OVERFLOW     -2
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define ElemType int
#include <malloc/_malloc.h>
typedef int Status;

#include <stdio.h>

typedef struct ListNode {
    ElemType data;
    struct ListNode *next;
}LNode,*LinkList;

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

int main(void) {
    printf("hello world\n");
    LinkList L;
    CreatList_L(L,10);
    int i ,j=0;
    for (i=1;i<=10;i++) {
        GetElem_L(L,i,j);
        printf("%d\n",j);
    }

    return 0;
}

