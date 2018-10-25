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

//Savage Sadistic Sensational
bool que4_del_sq_range(SqList &S, ElemType s, ElemType t){
    int i, j;
    
    if(s>=t || !S.length)
        return false;

    for(i=0;i<S.length&&S.data[i]<=s;i++);   //locate first of data>s
    if(i>S.length)
        return false;
    for(j=i;j<S.length&&S.data[j]<t;j++);  //locate t<data

    for(;j<S.length;i++,j++)
        S.data[i] = S.data[j];
    //i = 6;

    S.length = i;

    return true;
}

bool que5_del_nsq_range(SqList &S, ElemType s, ElemType t){
    int i, j, k;

    if(s>=t || !S.length)
        return false;

    k=0;
    for(i=0;i<S.length;i++){
        if(S.data[i]>=s && S.data[i]<=t)
            k++; 
        else
            S.data[i-k] = S.data[i];    //Sweet
    }

    S.length-=k;

    return true;
}

bool que6_del_repeated(SqList &s1, SqList &s2){


}

int main(int argc, char *argv[]){
    int i, j, flag;
    ElemType e;
    SqList A,B,S;
    ElemType arr1[] = {1,2,3,4,7,8,11,13,15};
    ElemType arr2[] = {1,3,5,6,9,2,4,6,8,10};
    ElemType arr3[] = {1,3,11,12,13};
    
    initList(&S);
    for(i=1;i<=sizeof(arr1)/sizeof(arr1[0]);i++){
        if(!insList(&S,i,arr1[i-1])){
            printf("插入位置非法");
            return 0;
        }
    }

    printf("The origin SeqList:\n");
    traverseList(S);

    que5_del_nsq_range(S, 3, 11);
    printf("After function exe:\n");
    traverseList(S);
    printf("Finally the length = %d\n", S.length);

    return 1;
}
