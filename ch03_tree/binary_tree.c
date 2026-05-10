#include "binary_tree.h"

BTNode *BT_NewNode(ElemType e) {
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->data  = e;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

void BT_Destroy(BTree *T) {
    if (!*T) return;
    BT_Destroy(&(*T)->left);
    BT_Destroy(&(*T)->right);
    free(*T);
    *T = NULL;
}

void BT_PreOrder(BTree T) {
    if (!T) return;
    printf("%d ", T->data);
    BT_PreOrder(T->left);
    BT_PreOrder(T->right);
}

void BT_InOrder(BTree T) {
    if (!T) return;
    BT_InOrder(T->left);
    printf("%d ", T->data);
    BT_InOrder(T->right);
}

void BT_PostOrder(BTree T) {
    if (!T) return;
    BT_PostOrder(T->left);
    BT_PostOrder(T->right);
    printf("%d ", T->data);
}

int BT_Height(BTree T) {
    if (!T) return 0;
    int lh = BT_Height(T->left);
    int rh = BT_Height(T->right);
    return (lh > rh ? lh : rh) + 1;
}

int BT_NodeCount(BTree T) {
    if (!T) return 0;
    return BT_NodeCount(T->left) + BT_NodeCount(T->right) + 1;
}
