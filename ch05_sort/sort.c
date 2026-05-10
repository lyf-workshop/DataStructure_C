#include "sort.h"

static void swap(ElemType *a, ElemType *b) {
    ElemType t = *a; *a = *b; *b = t;
}

void Sort_Bubble(ElemType arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
}

void Sort_Select(ElemType arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        swap(&arr[i], &arr[min]);
    }
}

void Sort_Insert(ElemType arr[], int n) {
    for (int i = 1; i < n; i++) {
        ElemType key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
        arr[j + 1] = key;
    }
}

static void merge(ElemType arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    ElemType *L = malloc(n1 * sizeof(ElemType));
    ElemType *R = malloc(n2 * sizeof(ElemType));
    memcpy(L, arr + l, n1 * sizeof(ElemType));
    memcpy(R, arr + m + 1, n2 * sizeof(ElemType));
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

static void merge_sort(ElemType arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void Sort_Merge(ElemType arr[], int n) {
    merge_sort(arr, 0, n - 1);
}

void Sort_Quick(ElemType arr[], int l, int r) {
    if (l >= r) return;
    ElemType pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (arr[j] <= pivot) swap(&arr[++i], &arr[j]);
    swap(&arr[i + 1], &arr[r]);
    int p = i + 1;
    Sort_Quick(arr, l, p - 1);
    Sort_Quick(arr, p + 1, r);
}

void Sort_Print(ElemType arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
