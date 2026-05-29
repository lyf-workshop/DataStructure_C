#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "../common/utils.h"

typedef struct ListNode {
    ElemType data;
    struct ListNode *next;
} LNode, *LinkList;

// 初始化带头结点的单链表 L。
Status InitList_L(LinkList &L);

// 销毁单链表 L，释放所有结点空间，并将 L 置空。
Status DestroyList_L(LinkList &L);

// 清空单链表 L，保留头结点，删除所有数据结点。
Status ClearList_L(LinkList &L);

// 判断单链表 L 是否为空表，空表返回 TRUE，否则返回 FALSE。
Status ListEmpty_L(LinkList L);

// 返回单链表 L 中数据结点的个数。
int ListLength_L(LinkList L);

// 用 e 返回单链表 L 中第 i 个元素的值，i 从 1 开始。
Status GetElem_L(LinkList L, int i, ElemType &e);

// 查找单链表 L 中第一个值等于 e 的元素，返回其位序，未找到返回 0。
int LocateElem_L(LinkList L, ElemType e);

// 在结点 P 前插入元素 e，要求 P 指向有效结点。
Status ListPriorInsert_L(LinkList &P, ElemType &e);

// 在单链表 L 的第 i 个位置插入元素 e，i 从 1 开始。
Status ListInsert_L(LinkList &L, int i, ElemType &e);

// 删除单链表 L 的第 i 个元素，并用 e 返回被删除元素的值。
Status ListDelete_L(LinkList &L, int i, ElemType &e);

// 头插法创建含 n 个元素的单链表 L，元素从标准输入读取。
void CreatList_L(LinkList &L, int n);

// 头插法创建含 n 个元素的单链表 L，元素从标准输入读取。
void CreateList_H(LinkList &L, int n);

// 尾插法创建含 n 个元素的单链表 L，元素从标准输入读取。
void CreateList_R(LinkList &L, int n);

// 合并两个非递减有序单链表 La 和 Lb，合并结果由 Lc 指向。
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

// 依次输出单链表 L 中所有数据元素。
void PrintList_L(LinkList L);

#endif
