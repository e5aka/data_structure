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

//按值查找,返回位置
int locateElem(SqList L, ElemType e)    
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i] == e)
            return i+1;
    return 0;
}

//按位查找，返回值
bool getElem(SqList L, int i, ElemType *e)       
{
    if(i<1 || i>L.length)
        return false;
    *e=L.data[i-1];
    return true;
}

//判空
bool empty(SqList *L)   
{
    if(L->length == 0)
        return true;
    return false;
}

int listLength(SqList L)
{
	return L.length;
}

//按位置插入顺序表元素
bool listInsert(SqList *L, int i, ElemType e)   
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

//按位置删除顺序表元素,并将其赋值于e
bool listDelete(SqList *L, int i, ElemType *e)  
{
    if(i<1 || i>L->length)  //插入位置非法
        return false;
    *e = L->data[i-1];      //删除元素赋予e
    for(int j=i;j<L->length;j++)    //前移
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
    putchar('\n');
}
