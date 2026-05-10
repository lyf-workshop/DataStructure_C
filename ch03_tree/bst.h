#ifndef BST_H
#define BST_H

#include "binary_tree.h"

/* 二叉搜索树 */
BTNode *BST_Insert(BTree T, ElemType e);
BTNode *BST_Search(BTree T, ElemType e);
BTNode *BST_Delete(BTree T, ElemType e);

#endif
