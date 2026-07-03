#ifndef BINARY_TREE_STACK_H
#define BINARY_TREE_STACK_H

#include "../common/utils.h"
#include "binary_tree.h"

// 二叉树遍历用的顺序栈，栈中存放结点指针 BiTree。
typedef BiTree SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

// 构造一个空栈 S。
Status InitStack(SqStack &S);

// 销毁栈 S，释放空间。
Status DestroyStack(SqStack &S);

// 清空栈 S，保留已分配的空间。
Status ClearStack(SqStack &S);

// 判断栈 S 是否为空，空栈返回 TRUE，否则返回 FALSE。
Status StackEmpty(SqStack S);

// 返回栈 S 中元素个数。
int StackLength(SqStack S);

// 用 e 返回栈 S 的栈顶元素，栈空时返回 ERROR。
Status GetTop(SqStack S, SElemType &e);

// 将元素 e 压入栈 S，必要时自动扩容。
Status Push(SqStack &S, SElemType e);

// 弹出栈 S 的栈顶元素，并用 e 返回，栈空时返回 ERROR。
Status Pop(SqStack &S, SElemType &e);

#endif
