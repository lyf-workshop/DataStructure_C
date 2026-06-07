#include "singly_linked_list.h"
#include "doubly_linked_list.h"
#include "static_linked_list.h"


void PrintStatus(const char *funcName, Status status) {
    printf("%s: %s\n", funcName, status == OK ? "OK" : "ERROR");
}

void PrintIntResult(const char *funcName, int result) {
    printf("%s: %d\n", funcName, result);
}

LinkList BuildSingleList(const ElemType data[], int n) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList tail = L;
    for (int i = 0; i < n; i++) {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->data = data[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return L;
}

DuLinkList BuildDoubleList(const ElemType data[], int n) {
    DuLinkList L = (DuLinkList)malloc(sizeof(DuLNode));
    L->next = NULL;
    L->prior = NULL;
    DuLinkList tail = L;
    for (int i = 0; i < n; i++) {
        DuLinkList p = (DuLinkList)malloc(sizeof(DuLNode));
        p->data = data[i];
        p->next = NULL;
        p->prior = tail;
        tail->next = p;
        tail = p;
    }
    return L;
}

void TestSinglyLinkedList() {
    printf("========== Singly Linked List ==========\n");

    LinkList L = NULL;
    PrintStatus("InitList_L", InitList_L(L));
    PrintStatus("ListEmpty_L", ListEmpty_L(L));
    PrintIntResult("ListLength_L", ListLength_L(L));

    ElemType data[] = {1, 3, 5, 7, 9};
    L = BuildSingleList(data, 5);

    ElemType e = 0;
    PrintStatus("GetElem_L", GetElem_L(L, 3, e));
    printf("GetElem_L value: %d\n", e);

    PrintIntResult("LocateElem_L", LocateElem_L(L, 7));

    e = 4;
    PrintStatus("ListInsert_L", ListInsert_L(L, 3, e));
    printf("PrintList_L after insert: ");
    PrintList_L(L);

    PrintStatus("ListDelete_L", ListDelete_L(L, 4, e));
    printf("ListDelete_L value: %d\n", e);
    printf("PrintList_L after delete: ");
    PrintList_L(L);

    LinkList p = L->next;
    e = 0;
    PrintStatus("ListPriorInsert_L", ListPriorInsert_L(p, e));
    printf("PrintList_L after prior insert: ");
    PrintList_L(L);

    LinkList L0 = NULL;
    CreatListPrior_L(L0, 0);
    printf("CreatListPrior_L: called with n = 0\n");

    LinkList LR = NULL;
    CreateList_R(LR, 0);
    printf("CreateList_R: called with n = 0\n");

    ElemType aData[] = {1, 3, 5};
    ElemType bData[] = {2, 4, 6};
    LinkList La = BuildSingleList(aData, 3);
    LinkList Lb = BuildSingleList(bData, 3);
    LinkList Lc = NULL;
    MergeList_L(La, Lb, Lc);
    printf("MergeList_L result: ");
    PrintList_L(Lc);

    PrintStatus("ClearList_L", ClearList_L(L));
    PrintStatus("DestroyList_L", DestroyList_L(L));
    printf("\n");
}

void TestDoublyLinkedList() {
    printf("========== Doubly Linked List ==========\n");

    DuLinkList L = NULL;
    PrintStatus("InitList_DuL", InitList_DuL(L));
    PrintStatus("ListEmpty_DuL", ListEmpty_DuL(L));
    PrintIntResult("ListLength_DuL", ListLength_DuL(L));

    ElemType data[] = {10, 20, 30, 40};
    L = BuildDoubleList(data, 4);

    ElemType e = 0;
    PrintStatus("GetElem_DuL", GetElem_DuL(L, 2, e));
    printf("GetElem_DuL value: %d\n", e);

    PrintIntResult("LocateElem_DuL", LocateElem_DuL(L, 30));

    PrintStatus("ListInsert_DuL", ListInsert_DuL(L, 2, 15));
    printf("PrintList_DuL after insert: ");
    PrintList_DuL(L);

    PrintStatus("ListDelete_DuL", ListDelete_DuL(L, 3, e));
    printf("ListDelete_DuL value: %d\n", e);
    printf("PrintList_DuL after delete: ");
    PrintList_DuL(L);

    DuLinkList L0 = NULL;
    CreateList_DuL(L0, 0);
    printf("CreateList_DuL: called with n = 0\n");

    PrintStatus("ClearList_DuL", ClearList_DuL(L));
    PrintStatus("DestroyList_DuL", DestroyList_DuL(L));
    printf("\n");
}

void TestStaticLinkedList() {
    printf("========== Static Linked List ==========\n");

    SLinkList space;
    InitList_SL(space);
    printf("InitList_SL: called\n");

    int first = Malloc_SL(space);
    PrintIntResult("Malloc_SL", first);

    Free_SL(space, first);
    printf("Free_SL: called\n");

    space[0].cur = 1;
    space[1].data = 11;
    space[1].cur = 2;
    space[2].data = 22;
    space[2].cur = 3;
    space[3].data = 33;
    space[3].cur = 0;

    PrintIntResult("LocateElem_SL", LocateElem_SL(space, 22));
    PrintIntResult("ListLength_SL", ListLength_SL(space));

    ElemType e = 0;
    PrintStatus("ListInsert_SL", ListInsert_SL(space, 2, 99));
    PrintStatus("ListDelete_SL", ListDelete_SL(space, 2, e));
    printf("ListDelete_SL value: %d\n", e);

    int S = 0;
    difference(space, S);
    PrintIntResult("difference S", S);

    printf("PrintList_SL: ");
    PrintList_SL(space);
    printf("\n");
}

int main(void) {
    TestSinglyLinkedList();
    TestDoublyLinkedList();
    TestStaticLinkedList();
    return 0;
}
