#include "array_list.h"

void AL_Init(ArrayList *L) {
    L->length = 0;
}

Status AL_Insert(ArrayList *L, int i, ElemType e) {
    if (L->length == MAXSIZE) return ERROR;
    if (i < 1 || i > L->length + 1) return ERROR;

    for (int j = L->length; j >= i; j--)
        L->data[j] = L->data[j - 1];

    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status AL_Delete(ArrayList *L, int i, ElemType *e) {
    if (L->length == 0) return ERROR;
    if (i < 1 || i > L->length) return ERROR;

    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
        L->data[j - 1] = L->data[j];

    L->length--;
    return OK;
}

Status AL_GetElem(ArrayList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    *e = L->data[i - 1];
    return OK;
}

int AL_LocateElem(ArrayList *L, ElemType e) {
    for (int i = 0; i < L->length; i++)
        if (L->data[i] == e) return i + 1;
    return 0;
}

int AL_Length(ArrayList *L) {
    return L->length;
}

void AL_Print(ArrayList *L) {
    printf("ArrayList [%d]: ", L->length);
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    printf("\n");
}
