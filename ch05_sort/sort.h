#ifndef SORT_H
#define SORT_H

#include "utils.h"

void Sort_Bubble(ElemType arr[], int n);     /* 冒泡排序 O(n²) */
void Sort_Select(ElemType arr[], int n);     /* 选择排序 O(n²) */
void Sort_Insert(ElemType arr[], int n);     /* 插入排序 O(n²) */
void Sort_Merge(ElemType arr[], int n);      /* 归并排序 O(nlogn) */
void Sort_Quick(ElemType arr[], int l, int r); /* 快速排序 O(nlogn) */
void Sort_Print(ElemType arr[], int n);

#endif
