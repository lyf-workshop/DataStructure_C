#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0
#define INFEASIBLE   -1
#define OVERFLOW     -2
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
typedef int Status;
#include <stdio.h>

#define ElemType int

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}Sqlist;



int main(void) {
    printf("hello");
    return 0;
}

