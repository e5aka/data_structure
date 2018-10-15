#define MaxSize 20
typedef char ElemType;

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit
#include "SqStack.h"

typedef struct{
    float data[MaxSize];
    int top;
}OpStack;

void translateExp(char s1[], char s2[]);
float computeExp(char s[]);

void main(int argc, char *argv[]){
    char a[MaxSize], b[MaxSize];
    char c[MaxSize];
    float f;
    
    printf("Please give me a Exp:");
    fgets(a, MaxSize, stdin);
    a[strlen(a)-1] = '\0';  //kill the \n
    //Attention
    printf("The mid suffix exp: %s\n", a);
    
    translateExp(a, b);
    printf("The post suffix exp: %s\n", b);

    f = computeExp(b);
    printf("The result is : %f\n", f);
}

float computeExp(char a[]){
    OpStack S;
    int i=0, value;
    float x1, x2;
    float result;
    S.top = -1;
    
    while(a[i] != '\0'){
        if(a[i]!=' ' && a[i]>='0' && a[i]<='9'){
            value = 0;
            while(a[i] != ' '){
                value = 10*value+a[i]-'0';
                i++;
            }
            S.data[++S.top] = value;
        }else{
            switch(a[i++]){
                case '+':
                    x1 = S.data[S.top--];   //stackPush
                    x2 = S.data[S.top--];
                    result = x2+x1;
                    S.data[++S.top] = result;   //stackPop
                    break;
                case '-':
                    x1 = S.data[S.top--];   //stackPush
                    x2 = S.data[S.top--];
                    result = x2-x1;
                    S.data[++S.top] = result;   //stackPop
                    break;
                case '*':
                    x1 = S.data[S.top--];   //stackPush
                    x2 = S.data[S.top--];
                    result = x2*x1;
                    S.data[++S.top] = result;   //stackPop
                    break;
                case '/':
                    x1 = S.data[S.top--];   //stackPush
                    x2 = S.data[S.top--];
                    result = x2/x1;
                    S.data[++S.top] = result;   //stackPop
                    break;
            }
        }
    }
    if(S.top != -1){
        result = S.data[S.top--];
        if(S.top == -1)
            return result;
        else{
            puts("Exp Error!");
            exit(-1);
        }
    }
}

void translateExp(char str[], char exp[]){
    SqStack S;
    char ch;
    ElemType e;
    int i=0, j=0;

    initStack(&S);
    ch = str[i++];
    
    while(ch != '\0'){
        switch(ch){
            case '(':
                stackPush(&S, ch);
                break;
            case ')':
                while(getTop(S, &e) && e!='('){
                    stackPop(&S, &e);
                    exp[j++] = e;
                }
                stackPop(&S, &e);
                break;
            case '+':
            case '-':
                while(!isEmpty(S) && getTop(S, &e) && e!='('){
                    stackPop(&S, &e);
                    exp[j++] = e;
                }
                stackPush(&S, ch);
                break;
            case '*':
            case '/':
                while(!isEmpty(S) && getTop(S, &e) && e=='/' || e=='*'){
                    stackPop(&S, &e);
                    exp[j++] = e;
                }
                stackPush(&S, ch);
                break;
            case ' ':
                break;
            default:
                while(ch >= '0' && ch<='9'){
                    exp[j++] = ch;
                    ch = str[i++];
                }
                i--;
                exp[j++] = ' ';
        }
        ch = str[i++];
    }
    while(!isEmpty(S)){
        stackPop(&S, &e);
        exp[j++] = e;
    }
    exp[j] = '\0';
}
