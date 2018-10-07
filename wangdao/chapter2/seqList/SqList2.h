/************************************************************************/
// 功    能：声明常量和函数原型的头文件,线性表的动态分配顺序存储结构
// 作    者：dashuai
/************************************************************************/
#define List_InitSize 100
#define ListIncrement 10

#include <stdbool.h>

typedef int ElemType;
typedef struct{//此时可以省去结构标记
    int *elem;//线性表基址
    int length;//当前表长
    int listsize;//当前为线性表分配的存储容量
}SqList;//为结构起的别名SqList

//线性表常用的有13个操作，归为4类

/************************************************************************/
/*第一类：初始化操作，记住各种数据结构开始使用都要初始化                */
/************************************************************************/

//1、线性表的初始化，构造一个空的线性表
int initList(SqList *L)//因为要改变线性表，必须用指针做参数
{   
    L->elem = (ElemType*)malloc(List_InitSize*sizeof(ElemType));

    if(!L->elem){
        printf("线性表分配失败");
        exit(0);
    }
    
    L->length = 0;
    L->listsize =List_InitSize;
    return 1;
}

/************************************************************************/
/*第二类：销毁操作，记住各种数据结构使用了都要有销毁的步骤              */
/************************************************************************/

//2、销毁，释放内存操作
void destory(SqList *L)//直接把内存释放的操作！类似与free（）
{
    if(L->elem){
        free(L->elem);
        printf("线性表已销毁");
    }
}

/************************************************************************/
/* 第三类：引用型操作，操作不改变线性表里的数据元素，也不改变他们之间的关系*/
/************************************************************************/

//3、判空操作,若线性表已经存在，为空白则返回true，否则返回false
bool listEmpty(SqList L)
{
    if(L.elem){
        if(0 == L.length)
            return true;
        return false;
    }else
        puts("此表不存在");
    return false;
}

//4、求长度操作，若线性表已经存在，则返回表L中元素个数
int listLength(SqList L)
{
    if(L.elem)
        return L.length;
    return 0;
}

//5、定位操作：线性表 L 已存在，返回 L 中第 1 个与 e 满足相等关系的元素的位序。
//若这种元素不存在，则返回 0。 
int locateElem(SqList L, ElemType e)
{
    int i;
    for(i=0;i<L.length;i++)
        if(e == L.elem[i-1])
            return i+1;
    return 0;  //未匹配到元素
}

//6、求元素后继,初始条件：线性表 L 已存在。若 cur_e是 L 中的元素，则打印它的后继
//否则操作失败
int nextElem(SqList L, ElemType cur_e)
{
    int i = locateElem(L, cur_e);
    if(i){
        if(i == L.length){
            return 0;
        }else{
            return i+1;     //返回后继在序列中的位数
        }
    }
    puts("无此元素");
    return 0;
}

//7、得到指定的元素值，线性表 L 已存在
//1≤i≤表长。用 e 返回 L 中第 i 个元素的值。 
bool getElem(SqList L, int i, ElemType *e)
{
    if(i<1 || i>L.length)
        return false;
    *e = L.elem[i-1];
    return true;
}

//8、求元素前驱，线性表L已经存在，若cur_e是L的数据元素，则返回前驱
//否则操作失败
int priorElem(SqList L, ElemType cur_e)
{
    int i = locateElem(L, cur_e);
    if(i){
        if(i == L.length){
            return 0;
        }else{
            return i-1;     //返回后继在序列中的位数
        }
    }
    puts("无此元素");
    return 0;
}

//9、遍历表中元素，线性表 L 已存在，打印出表中每个元素
//无法遍历，则操作失败。 
void traverseList(SqList L)
{
    int i;
    for(i=0;i<L.length;i++){
        printf("%4d", L.elem[i]);   //当ElemType为int时
    }
    putchar('\n');
}

/************************************************************************/
/* 第四类：加工型操作                                                   */
/************************************************************************/

//10、把表清空（不释放内存）：线性表 L 已存在，将 L 重置为空表。 
void clearList(SqList *L)
{
    if(L->elem)
        L->length = 0;
}

//11、给表某元素赋值，线性表 L 已存在
//L 中第 i 个元素赋值为 e 的值。 
void putElem(SqList *L, int i, ElemType e)
{
    if(i<1 || i>L->length)
        puts("超出表范围");
    L->elem[i-1] = e;
}

//12、插入操作，线性表 L 已存在，在 L 的第 i 个元素之前插入新的元素 e，L 的长度增 1。 
void listInsert(SqList *L, int i, int e)
{
    SqList *NL;
    int *j, *k;

    if(i<1 || i>L->length+1){
        puts("插入位置非法");
    }else if(L->length >= L->listsize){
        NL->elem = (int *)realloc(L->elem, (L->listsize+ListIncrement)*sizeof(int));
        if(!NL->elem)
            exit(0);
        L->elem = NL->elem;
    }

    j = &(L->elem[i-1]);
    for(k=&(L->elem[L->length-1]);k>=j;k--){
        *(k+1) = *k;
    }
    *j = e;
    L->length++;
}

//13、删除操作，表 L 已存在且非空，。删除 L 的第 i 个元素，并用 e 返回其值，长度减 1。 
void listDelete(SqList *L, int i, int *e )
{
    int *p;

    if(i<1 || i>L->length+1){
        puts("插入位置非法");
    }else{
        p = &(L->elem[i-1]);
        *e = L->elem[i-1];
        for(;p<&(L->elem[L->length-1]);p++){
            *p = *(p+1);
        }
        L->length--;
    }
}

/************************************************************************/
/* 额外的几个复杂操作                                                   */
/************************************************************************/

//1、合并线性表AB，把在线性表B里，但不存在于线性表A的元素插入到A中
//只改变A，不修改B
void Union(SqList *LA, SqList LB);

//2、合并线性表AB，AB的元素按值非递减有序的排列，要把A和B归并为一个新表C，且C的元素依然是按照值非递减的有序排列
void MergeList(SqList LA, SqList LB, SqList *LC);
