#ifndef STATIC_LINKED_LIST_H
#define STATIC_LINKED_LIST_H

#include "../common/utils.h"

#define LIST_INIT_SIZE 100

typedef struct {
    ElemType data;
    int cur;
} component, SLinkList[LIST_INIT_SIZE];

// 查找静态链表 S 中第一个值等于 e 的元素，返回其数组下标，未找到返回 0。
int LocateElem_SL(SLinkList &S, ElemType e);

// 初始化静态链表备用空间，将所有未用结点串成备用链表。
void InitList_SL(SLinkList &space);

// 从静态链表备用空间中分配一个空闲结点，返回其数组下标，失败返回 0。
int Malloc_SL(SLinkList &space);

// 将下标为 k 的结点回收到静态链表备用空间。
void Free_SL(SLinkList &space, int k);

// 在静态链表 S 的第 i 个位置插入元素 e，i 从 1 开始。
Status ListInsert_SL(SLinkList &S, int i, ElemType e);

// 删除静态链表 S 的第 i 个元素，并用 e 返回被删除元素的值。
Status ListDelete_SL(SLinkList &S, int i, ElemType &e);

// 返回静态链表 S 中数据元素的个数。
int ListLength_SL(SLinkList S);

// 求集合差集，结果保存在静态链表 S 中。
void difference(SLinkList &space, int &S);

// 依次输出静态链表 S 中所有数据元素。
void PrintList_SL(SLinkList S);

#endif
