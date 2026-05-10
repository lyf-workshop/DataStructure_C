#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "utils.h"

typedef struct BTNode {
    ElemType       data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode, *BTree;

BTNode *BT_NewNode(ElemType e);
void    BT_Destroy(BTree *T);
void    BT_PreOrder(BTree T);    /* 先序遍历 */
void    BT_InOrder(BTree T);     /* 中序遍历 */
void    BT_PostOrder(BTree T);   /* 后序遍历 */
int     BT_Height(BTree T);      /* 树高 */
int     BT_NodeCount(BTree T);   /* 结点数 */

#endif
