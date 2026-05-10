#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "utils.h"

#define MAXSIZE 100

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} ArrayList;

void AL_Init(ArrayList *L);
Status AL_Insert(ArrayList *L, int i, ElemType e);
Status AL_Delete(ArrayList *L, int i, ElemType *e);
Status AL_GetElem(ArrayList *L, int i, ElemType *e);
int    AL_LocateElem(ArrayList *L, ElemType e);
int    AL_Length(ArrayList *L);
void   AL_Print(ArrayList *L);

#endif
