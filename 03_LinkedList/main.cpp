#include "singly_linked_list.h"

#include <stdio.h>

int main(void) {
    printf("hello world\n");
    LinkList La;
    CreatList_L(La,10);
    int i, j = 0;
    for (i = 1; i <= 10; i++) {
        GetElem_L(La, i, j);
        printf("%d\t", j);
    }
    LinkList Lb;
    CreatList_L(Lb,10);
    LinkList Lc;
    MergeList_L(La,Lb,Lc);
    for (i = 1; i <= 10; i++) {
        GetElem_L(Lc, i, j);
        printf("%d\t", j);
    }
    return 0;
}
