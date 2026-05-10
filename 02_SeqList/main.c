#include <stdio.h>
#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
}Sqlist;

void InitList(Sqlist *L)
{
    for (int i=0; i<MaxSize; i++)
    {
        L->data[i]=0;
    }
    L->length = 0;
}

int main()
{
    Sqlist L;
    InitList(&L);
    for (int i=0; i<MaxSize; i++)
    {
        printf("%d\n",L.data[i]);
    }
    return 0;
}