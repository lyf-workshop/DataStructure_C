#include "../common/utils.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


Status InitStack(SqStack &S) {
    S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &S) {
    if (S.base == NULL) return ERROR;
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    return OK;
}

Status ClearStack(SqStack &S) {
    if (S.base == NULL) return ERROR;
    S.top = S.base;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S.top == S.base) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int StackSize(SqStack S) {

}

Status GetTop(SqStack S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(S.top-1);
    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType*)realloc(S.base, (S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);
        S.top = S.base+S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *(S.top++) = e;
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;

}

Status StackTraverse(SqStack &S,Status (*visit)(SElemType)) {
    return OK;
}

// void conversion() {
//     SqStack S;
//     InitStack(S);
//     int N;
//     printf("Enter the number of elements you would like to convert: ");
//     scanf("%d", &N);
//     while (N) {
//         Push(S,N%8);
//         N/=8;
//     }
//     int e=0;
//     while (!StackEmpty(S)) {
//         Pop(S,e);
//         printf("%d ",e);
//     }
//     DestroyStack(S);
// }

void BracketMatch() {
    SqStack S;
    InitStack(S);
    char str[100];
    printf("请输入括号表达式：");
    scanf("%s",str);

    for (int i=0;i<strlen(str);i++) {
        char ch = str[i];
        if (ch == '('||ch == '['||ch == '{') {
            Push(S,ch);
        }
        else if (ch == ')'||ch == ']'||ch == '}') {
            if (StackEmpty(S)) {
                printf("括号匹配失败：右括号 %c 没有对应的左括号\n", ch);
                DestroyStack(S);
                return;
            }
            SElemType topElem;
            Pop(S,topElem);
            if ((ch == ')'&&topElem !='(')||(ch == ']'&&topElem !='[')||(ch == '}'&&topElem !='{')) {
                printf("括号匹配失败：%c 和 %c 不匹配\n", topElem, ch);
                DestroyStack(S);
                return;
            }

        }
    }
    if (StackEmpty(S)) {
        printf("括号匹配成功\n");
    }
    else {
        printf("括号匹配失败：存在多余的左括号\n");
    }

    DestroyStack(S);

}

void LineEdit() {
    SqStack S;
    InitStack(S);

    char ch;

    while ((ch = getchar()) != EOF) {
        while (ch != EOF && ch != '\n') {
            if (ch == '#') {
                SElemType c;

                if (!StackEmpty(S)) {
                    Pop(S, c);
                }
            }
            else if (ch == '@') {
                ClearStack(S);
            }
            else {
                Push(S, ch);
            }

            ch = getchar();
        }


        SElemType* p = S.base;

        while (p < S.top) {
            printf("%c", *p);
            p++;
        }

        printf("\n");
        ClearStack(S);

        if (ch == EOF) {
            break;
        }
    }

    DestroyStack(S);
}



int main(void) {
    // conversion();
    //BracketMatch();
    LineEdit();

    return 0;
}

