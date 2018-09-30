#define MaxSize 100
#define InitSize 10
#define ElemType int

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    ElemType *data;
    int length;
}D_SqList;

bool listInsert(D_SqList *L, int i, ElemType e)
{
    int j;
    if(i<1 || i>L->length+1)    //插入位置非法
        return false;
    if(L->length >= MaxSize)    //数组长度已满
        return false;
    for(j=L->length;j>=i;j--)   //第i位及之后元素后移
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;           //赋值与第i-1位
    L->length++;                //表长增加
    return true;
}

int main()
{
    D_SqList L;

    L.data = (int*)malloc(sizeof(int)*InitSize);
    for(int i=1;i<=10;i++){
        if(!listInsert(&L, i, i))
            printf("插入位置非法\n");
    }

    return 1;
}
