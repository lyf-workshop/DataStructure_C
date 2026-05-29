#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "../common/utils.h"

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *next;
    struct DuLNode *prior;
} DuLNode, *DuLinkList;

// 初始化带头结点的双向链表 L。
Status InitList_DuL(DuLinkList &L);

// 销毁双向链表 L，释放所有结点空间，并将 L 置空。
Status DestroyList_DuL(DuLinkList &L);

// 清空双向链表 L，保留头结点，删除所有数据结点。
Status ClearList_DuL(DuLinkList &L);

// 判断双向链表 L 是否为空表，空表返回 TRUE，否则返回 FALSE。
Status ListEmpty_DuL(DuLinkList L);

// 返回双向链表 L 中数据结点的个数。
int ListLength_DuL(DuLinkList L);

// 用 e 返回双向链表 L 中第 i 个元素的值，i 从 1 开始。
Status GetElem_DuL(DuLinkList L, int i, ElemType &e);

// 查找双向链表 L 中第一个值等于 e 的元素，返回其位序，未找到返回 0。
int LocateElem_DuL(DuLinkList L, ElemType e);

// 在双向链表 L 的第 i 个位置插入元素 e，i 从 1 开始。
Status ListInsert_DuL(DuLinkList &L, int i, ElemType e);

// 删除双向链表 L 的第 i 个元素，并用 e 返回被删除元素的值。
Status ListDelete_DuL(DuLinkList &L, int i, ElemType &e);

// 创建含 n 个元素的双向链表 L，元素从标准输入读取。
void CreateList_DuL(DuLinkList &L, int n);

// 依次输出双向链表 L 中所有数据元素。
void PrintList_DuL(DuLinkList L);

#endif
