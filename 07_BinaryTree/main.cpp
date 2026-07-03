#include "binary_tree.h"
#include "Stack.h"

Status CreateBiTree(BiTree &T) {
    TElemType ch;
    scanf(" %c", &ch);
    if (ch == '#') {
        T = NULL;
    }
    else {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType)) {
    if (T == NULL) return OK;
    if (Visit(T->data) == ERROR) return ERROR;
    if (PreOrderTraverse(T->lchild, Visit) == ERROR) return ERROR;
    if (PreOrderTraverse(T->rchild, Visit) == ERROR) return ERROR;
    return OK;
}

// 非递归先序遍历：根结点先访问，再让右子树后进栈、左子树后出栈先处理。
Status PreOrderTraverse_NR(BiTree T, Status (*Visit)(TElemType)) {
    SqStack S;
    InitStack(S);

    BiTree p = T;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            if (Visit(p->data) == ERROR) {
                DestroyStack(S);
                return ERROR;
            }
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            p = p->rchild;
        }
    }

    DestroyStack(S);
    return OK;
}

// 非递归中序遍历：一路向左压栈，到底后出栈访问，再转向右子树。
Status InOrderTraverse(BiTree T, Status (*Visit)(TElemType)) {
    SqStack S;
    InitStack(S);

    BiTree p = T;
    while (p != NULL || !StackEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->lchild;
        }
        else {
            Pop(S, p);
            if (Visit(p->data) == ERROR) {
                DestroyStack(S);
                return ERROR;
            }
            p = p->rchild;
        }
    }

    DestroyStack(S);
    return OK;
}

// 简单的访问函数：打印结点数据。
Status PrintElem(TElemType e) {
    printf("%c ", e);
    return OK;
}

int main(void) {
    BiTree T;
    printf("请按先序输入二叉树（'#' 表示空结点，例如 AB#D##C##）：");
    CreateBiTree(T);

    printf("先序遍历（递归）：");
    PreOrderTraverse(T, PrintElem);
    printf("\n");

    printf("先序遍历（非递归）：");
    PreOrderTraverse_NR(T, PrintElem);
    printf("\n");

    printf("中序遍历（非递归）：");
    InOrderTraverse(T, PrintElem);
    printf("\n");

    return 0;
}
