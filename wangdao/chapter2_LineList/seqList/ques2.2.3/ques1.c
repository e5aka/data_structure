typedef int ElemType;
#define MaxSize 100

#include <stdio.h>
#include "../SqList.h"

bool del_identical_v(SqList *S, ElemType s, ElemType t){
    int i, j;

    for(i=0;i<S->length;i++){
    }
}

int ques1(SqList *S){
    int i, value;

    if(!S->length)
        return false;
    puts("Devil may cry");
    for(i=0;i<S->length;i++)
        if(S->data[i] < S->data[i+1])
            j = i;
    
    S->data[j] = S->data[i-1];
    S->length--;
    
    return true;
}

int main(){
    int i, j, flag;
    ElemType e;
    SqList A,B;
    ElemType arr1[] = {3,2,8,4,1,10,7,9,5,6};
    
    initList(&A);
    for(i=1;i<=10;i++){
        if(!insList(&A,i,arr1[i-1])){
            printf("插入位置非法");
            return 0;
        }
    }

    printf("The origin SeqList:\n");
    traverseList(A);

    ques1(&A);
    printf("After function exe:\n");
    traverseList(A);

    return 1;
}
