#include <stdbool.h>

typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void initList(SqList *L)
{
	L->length=0;
}

int locateElem(SqList L, ElemType e)    //按值查找
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i] == e)
            return i+1;
    return 0;
}

ElemType getElem(SqList L, int i)       //按位查找
{
    if(i<1 || i>L.length)
        return 0;
    return L.data[i-1];
}

bool empty(SqList *L)   //判空
{
    if(L->length == 0)
        return true;
    return false;
}

int listLength(SqList L)
{
	return L.length;
}

bool listInsert(SqList *L, int i, ElemType e)
{
    int j;
    if(i<1 || i>L->length+1)    //判断范围
        return false;
    if(L->length >= MaxSize)    //数组长度已满
        return false;
    for(j=L->length;j>=i;j--)
        L->data[j] = L->data[j-1];
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool listDelete(SqList *L, int i, ElemType *e)
{
    if(i<1 || i>L->length)  //判断范围
        return false;
    *e = L->data[i-1];
    for(int j=i;j<L->length;j++)
        L->data[j-1] = L->data[j];
    L->length--;
    return true;
}

void destroyList(SqList *L)     //销毁线性表
{
    L->length = 0;
}

void printList(SqList L){
    for(int i=0;i<L.length;i++)
        printf("%d ",L.data[i]);
}
