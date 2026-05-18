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

Status ListInsert_L(LinkList &L,int i,ElemType &e) {}

int main(void) {
    LinkList L = (LinkList)malloc(sizeof(struct ListNode));

    return 0;
}

