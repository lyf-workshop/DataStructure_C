#include "bst.h"

BTNode *BST_Insert(BTree T, ElemType e) {
    if (!T) return BT_NewNode(e);
    if (e < T->data)      T->left  = BST_Insert(T->left,  e);
    else if (e > T->data) T->right = BST_Insert(T->right, e);
    return T;
}

BTNode *BST_Search(BTree T, ElemType e) {
    if (!T || T->data == e) return T;
    if (e < T->data) return BST_Search(T->left,  e);
    else             return BST_Search(T->right, e);
}

static BTNode *BST_MinNode(BTree T) {
    while (T->left) T = T->left;
    return T;
}

BTNode *BST_Delete(BTree T, ElemType e) {
    if (!T) return NULL;
    if (e < T->data) {
        T->left  = BST_Delete(T->left,  e);
    } else if (e > T->data) {
        T->right = BST_Delete(T->right, e);
    } else {
        if (!T->left) {
            BTNode *tmp = T->right;
            free(T);
            return tmp;
        } else if (!T->right) {
            BTNode *tmp = T->left;
            free(T);
            return tmp;
        }
        BTNode *succ = BST_MinNode(T->right);
        T->data  = succ->data;
        T->right = BST_Delete(T->right, succ->data);
    }
    return T;
}
