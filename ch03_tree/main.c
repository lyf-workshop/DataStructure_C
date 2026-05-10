#include <stdio.h>
#include "binary_tree.h"
#include "bst.h"

int main(void) {
    /* --- 手动构建二叉树测试遍历 --- */
    printf("=== 二叉树遍历 ===\n");
    BTree root = BT_NewNode(1);
    root->left  = BT_NewNode(2);
    root->right = BT_NewNode(3);
    root->left->left  = BT_NewNode(4);
    root->left->right = BT_NewNode(5);

    printf("先序: "); BT_PreOrder(root);  printf("\n");
    printf("中序: "); BT_InOrder(root);   printf("\n");
    printf("后序: "); BT_PostOrder(root); printf("\n");
    printf("树高: %d\n", BT_Height(root));
    printf("结点数: %d\n", BT_NodeCount(root));
    BT_Destroy(&root);

    /* --- 二叉搜索树 --- */
    printf("\n=== 二叉搜索树 ===\n");
    BTree bst = NULL;
    int vals[] = {5, 3, 7, 1, 4, 6, 8};
    for (int i = 0; i < 7; i++) bst = BST_Insert(bst, vals[i]);

    printf("中序(升序): "); BT_InOrder(bst); printf("\n");

    BTNode *found = BST_Search(bst, 4);
    printf("查找4: %s\n", found ? "找到" : "未找到");

    bst = BST_Delete(bst, 3);
    printf("删除3后中序: "); BT_InOrder(bst); printf("\n");

    BT_Destroy(&bst);
    return 0;
}
