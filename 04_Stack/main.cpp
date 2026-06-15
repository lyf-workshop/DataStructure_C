#include "../common/utils.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define EXPRESSION_MAX_SIZE 200

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
    if (S.base == NULL) return 0;
    return S.top - S.base;
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

// 判断 ch 是否为操作数，这里支持数字和单个英文字母变量。
Status IsOperand(SElemType ch) {
    if (ch >= '0' && ch <= '9') return TRUE;
    if (ch >= 'a' && ch <= 'z') return TRUE;
    if (ch >= 'A' && ch <= 'Z') return TRUE;
    return FALSE;
}

// 判断 ch 是否为当前支持的四则运算符。
Status IsOperator(SElemType ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return TRUE;
    }
    return FALSE;
}

// 返回运算符优先级，数值越大优先级越高。
int Priority(SElemType ch) {
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

// 向后缀表达式数组追加一个字符，并检查是否越界。
Status AddPostfixChar(char postfix[], int &k, SElemType ch) {
    if (k >= EXPRESSION_MAX_SIZE - 1) return ERROR;
    postfix[k++] = ch;
    return OK;
}

// 在后缀表达式中添加空格，用于分隔多位数和运算符。
Status AddPostfixBlank(char postfix[], int &k) {
    if (k > 0 && postfix[k - 1] != ' ') {
        return AddPostfixChar(postfix, k, ' ');
    }
    return OK;
}

// 将中缀表达式 infix 转换为后缀表达式 postfix。
// 算法规则：操作数直接输出，运算符按优先级入栈/出栈，括号控制出栈范围。
Status InfixToPostfix(const char infix[], char postfix[]) {
    SqStack S;
    InitStack(S);

    int i = 0;
    int k = 0;
    SElemType ch;

    while (infix[i] != '\0' && infix[i] != '\n') {
        ch = infix[i];

        // 忽略表达式中的空格和制表符。
        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        // 多位整数需要连续读取，整体输出到后缀表达式中。
        if (ch >= '0' && ch <= '9') {
            while (infix[i] >= '0' && infix[i] <= '9') {
                if (AddPostfixChar(postfix, k, infix[i]) == ERROR) {
                    DestroyStack(S);
                    return ERROR;
                }
                i++;
            }(())
            if (AddPostfixBlank(postfix, k) == ERROR) {
                DestroyStack(S);
                return ERROR;
            }
            continue;
        }

        // 单个字母变量直接输出，例如 a+b*c。
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (AddPostfixChar(postfix, k, ch) == ERROR ||
                AddPostfixBlank(postfix, k) == ERROR) {
                DestroyStack(S);
                return ERROR;
            }
            i++;
            continue;
        }

        // 左括号直接入栈，等待右括号触发出栈。
        if (ch == '(') {
            Push(S, ch);
            i++;
            continue;
        }

        // 右括号弹出栈中运算符，直到遇到对应的左括号。
        if (ch == ')') {
            SElemType topElem;
            Status foundLeftBracket = FALSE;

            while (!StackEmpty(S)) {
                Pop(S, topElem);
                if (topElem == '(') {
                    foundLeftBracket = TRUE;
                    break;
                }
                if (AddPostfixChar(postfix, k, topElem) == ERROR ||
                    AddPostfixBlank(postfix, k) == ERROR) {
                    DestroyStack(S);
                    return ERROR;
                }
            }

            if (!foundLeftBracket) {
                DestroyStack(S);
                return ERROR;
            }

            i++;
            continue;
        }

        // 当前运算符优先级低于或等于栈顶运算符时，先弹出栈顶运算符。
        if (IsOperator(ch)) {
            SElemType topElem;

            while (!StackEmpty(S)) {
                GetTop(S, topElem);
                if (topElem == '(') break;

                if (Priority(topElem) >= Priority(ch)) {
                    Pop(S, topElem);
                    if (AddPostfixChar(postfix, k, topElem) == ERROR ||
                        AddPostfixBlank(postfix, k) == ERROR) {
                        DestroyStack(S);
                        return ERROR;
                    }
                }
                else {
                    break;
                }
            }

            Push(S, ch);
            i++;
            continue;
        }

        // 遇到不支持的字符，认为表达式非法。
        DestroyStack(S);
        return ERROR;
    }

    // 表达式扫描完成后，把栈中剩余运算符依次输出。
    while (!StackEmpty(S)) {
        SElemType topElem;
        Pop(S, topElem);

        // 栈中仍有左括号，说明括号不匹配。
        if (topElem == '(') {
            DestroyStack(S);
            return ERROR;
        }

        if (AddPostfixChar(postfix, k, topElem) == ERROR ||
            AddPostfixBlank(postfix, k) == ERROR) {
            DestroyStack(S);
            return ERROR;
        }
    }

    // 去掉最后一个多余空格，并补上字符串结束符。
    if (k > 0 && postfix[k - 1] == ' ') {
        k--;
    }
    postfix[k] = '\0';

    DestroyStack(S);
    return OK;
}

// 从标准输入读取中缀表达式，并输出转换后的后缀表达式。
void InfixToPostfixTest() {
    char infix[EXPRESSION_MAX_SIZE];
    char postfix[EXPRESSION_MAX_SIZE];

    printf("请输入中缀表达式：");
    if (fgets(infix, EXPRESSION_MAX_SIZE, stdin) == NULL) {
        printf("输入失败\n");
        return;
    }

    if (InfixToPostfix(infix, postfix) == OK) {
        printf("后缀表达式：%s\n", postfix);
    }
    else {
        printf("表达式转换失败\n");
    }
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
    //LineEdit();
    InfixToPostfixTest();

    return 0;
}
