#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../common/utils.h"

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 按先序输入字符序列建立二叉树，'#' 表示空结点。
// 例如输入 AB#D##C## 可建立根为 A 的二叉树。
Status CreateBiTree(BiTree &T);

// 先序遍历二叉树（递归），对每个结点调用 Visit。
Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType));

// 中序遍历二叉树（非递归，借助栈实现）。
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType));

// 先序遍历二叉树（非递归，借助栈实现）。
Status PreOrderTraverse_NR(BiTree T, Status (*Visit)(TElemType));

#endif
