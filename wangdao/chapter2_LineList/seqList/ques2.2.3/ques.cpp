typedef int ElemType;
#define MaxSize 100

#include <stdio.h>
#include "../SqList.h"

int ques1_delmin(SqList *S){
    int i, value ,pos;

    if(!S->length)
        return 0;
    puts("Devil may cry");
    value = S->data[0];
    for(i=1;i<S->length;i++)
        if(S->data[i] < value)
            pos = i;
    
    value = S->data[pos];
    S->data[pos] = S->data[i-1];
    S->length--;
    
    return value;
}

bool que2_reverse(SqList &S){
    ElemType t;

    if(!S.length)
        return false;
    for(int i=0;i<S.length/2;i++){
        t = S.data[i];
        S.data[i] = S.data[S.length-1-i];
        S.data[S.length-1-i] = t;
    }

    return true;
}

bool que3_del_x(SqList &S, ElemType x){
    int i, j, k;
    ElemType t;

    k = 0;
    for(i=0;i<S.length;i++)
        if(S.data[i] != x){
            S.data[k] = S.data[i];
            k++;
        }
    S.length = k;
}

int main(){
    int i, j, flag;
    ElemType e;
    SqList A,B;
    ElemType arr1[] = {3,2,3,3,1,10,7,3,3,6,8};
    
    initList(&A);
    for(i=1;i<=sizeof(arr1)/sizeof(arr1[0]);i++){
        if(!insList(&A,i,arr1[i-1])){
            printf("插入位置非法");
            return 0;
        }
    }

    printf("The origin SeqList:\n");
    traverseList(A);

    que3_del_x(A, 3);
    printf("After function exe:\n");
    traverseList(A);

    return 1;
}
