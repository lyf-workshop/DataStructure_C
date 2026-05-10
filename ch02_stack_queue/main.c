#include <stdio.h>
#include "stack.h"
#include "queue.h"

int main(void) {
    /* --- 栈测试 --- */
    printf("=== 顺序栈 ===\n");
    Stack S;
    Stack_Init(&S);
    for (int i = 1; i <= 5; i++) Stack_Push(&S, i * 10);

    ElemType e;
    Stack_GetTop(&S, &e);
    printf("栈顶元素: %d\n", e);

    printf("出栈顺序: ");
    while (!Stack_IsEmpty(&S)) {
        Stack_Pop(&S, &e);
        printf("%d ", e);
    }
    printf("\n");

    /* --- 队列测试 --- */
    printf("\n=== 循环队列 ===\n");
    Queue Q;
    Queue_Init(&Q);
    for (int i = 1; i <= 5; i++) Queue_Enqueue(&Q, i * 10);
    printf("队列长度: %d\n", Queue_Length(&Q));

    printf("出队顺序: ");
    while (!Queue_IsEmpty(&Q)) {
        Queue_Dequeue(&Q, &e);
        printf("%d ", e);
    }
    printf("\n");

    return 0;
}
