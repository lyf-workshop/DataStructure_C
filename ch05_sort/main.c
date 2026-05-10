#include <stdio.h>
#include <string.h>
#include "sort.h"

#define N 8

static void test_sort(const char *name, void (*fn)(ElemType[], int)) {
    ElemType arr[] = {64, 25, 12, 22, 11, 90, 33, 47};
    fn(arr, N);
    printf("%-10s: ", name);
    Sort_Print(arr, N);
}

int main(void) {
    printf("=== 排序算法 ===\n");
    test_sort("冒泡", Sort_Bubble);
    test_sort("选择", Sort_Select);
    test_sort("插入", Sort_Insert);
    test_sort("归并", Sort_Merge);

    ElemType arr[] = {64, 25, 12, 22, 11, 90, 33, 47};
    Sort_Quick(arr, 0, N - 1);
    printf("%-10s: ", "快速");
    Sort_Print(arr, N);

    return 0;
}
