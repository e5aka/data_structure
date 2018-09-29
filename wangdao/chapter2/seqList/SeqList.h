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

int locateElem(SqList L, ElemType e)
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i] == e)
            return i+1;
    return 0;
}

int listLength(SqList L)
{
	return L.length;
}

bool listInsert(SqList &L, int i, ElemType e)
{
    int j;
    if(i<1 || i>L.length+1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for(j=L.length;j>=i;j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

int listDelete(SqList &L, int i, ElemType &e)
{
    return 1;
}
