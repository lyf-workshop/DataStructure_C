#include <stdio.h>
#include "array_list.h"
#include "linked_list.h"

int main(void) {
    /* --- 顺序表测试 --- */
    printf("=== 顺序表 ===\n");
    ArrayList al;
    AL_Init(&al);
    for (int i = 1; i <= 5; i++) AL_Insert(&al, i, i * 10);
    AL_Print(&al);

    ElemType e;
    AL_Delete(&al, 2, &e);
    printf("删除第2个元素: %d\n", e);
    AL_Print(&al);

    /* --- 单链表测试 --- */
    printf("\n=== 单链表 ===\n");
    LinkedList ll;
    LL_Init(&ll);
    for (int i = 1; i <= 5; i++) LL_Insert(ll, i, i * 10);
    LL_Print(ll);

    LL_Delete(ll, 2, &e);
    printf("删除第2个元素: %d\n", e);
    LL_Print(ll);

    LL_Destroy(&ll);
    return 0;
}
