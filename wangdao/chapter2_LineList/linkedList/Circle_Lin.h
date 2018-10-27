//typedef int ElemType;
//#defind MaxSize 99
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    ElemType data;
    struct Node *next;
}LNode;
typedef struct Node *LinkList;

bool isEmpty(LinkList L);   //diff
void initList(LinkList *L); //diff
LinkList createList(LinkList L);    //err
LinkList createList2(LinkList *L);
LinkList createList2_nh(LinkList *L);
LinkList getElem(LinkList L, int i);
LinkList locateElem(LinkList L, ElemType e);
int locatePos(LinkList L, ElemType e);
void insList(LinkList L, int i, ElemType e);    //when rear diff
void delList(LinkList L, int i, ElemType *e);   //when rear diff
int getLength(LinkList L);
void destroyList(LinkList L);
void traverseList(LinkList L);  //Any node

//10.判断为空否
bool isEmpty(LinkList L){
    if(L->next == L)
        return true;
    else
        return false;
}

//0.初始化
void initList(LinkList *L){ //head node
    *L = (LNode*)malloc(sizeof(LNode));
    if(*L == NULL)
        exit(0);
    (*L)->data = -1;
    (*L)->next = *L;
    //*L is a pointer
}

//1.头插法创建单链表
LinkList createList(LinkList L){
//2BS!!
    LinkList s;
    int x;

    L = (LNode*)malloc(sizeof(LNode));  //Head Node
    L->next = NULL;

    scanf("%d", &x);
    while(x != 999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
//2.采用尾插法创建Circle单链表 
LinkList createList2(LinkList *L){
    ElemType x;
    *L = (LNode*)malloc(sizeof(LNode));
    (*L)->next = NULL;
    (*L)->data = 99;
    LinkList s, r = *L;   //r为表尾指针
    
    while(scanf("%d", &x),x){
        puts("input again");
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;
        r->next = s;
        r = s;
    }
    r->next = *L;

    return *L;   //return rear node
}

//rear ins create,No head node
LinkList createList2_nh(LinkList *L){
    ElemType x;
    *L = (LNode*)malloc(sizeof(LNode));
    puts("The head:");
    scanf("%d", &(*L)->data);
    puts("input head");
    LinkList s, r;
    
    r = *L;
    while(scanf("%d", &x),x){
        puts("input again");
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = r->next;
        r->next = s;
        r = s;
    }
    r->next = *L;

    return r;   //return rear node
}

//3.按序号查找结点值,取出带头指针的第i个位置的结点指针
LinkList getElem(LinkList L, int i){
    int j = 1;
    LinkList p = L->next;

    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p->next != L && j<i){
        p = p->next;
        j++;
    }
    return p;
}

//4.按值查找表节点
LinkList locateElem(LinkList L, ElemType e){
    LinkList p = L->next;
    
    while(p->next!=L && p->data!=e)
        p = p->next;
    return p;
}

//4.1.按值查找表节点,返回列序
int locatePos(LinkList L, ElemType e){
    LinkList p = L->next;
    int i = 1;

    if(isEmpty(L))
        return 0;
    while(p!=L && p->data!=e){  //hardcore
        p = p->next;
        i++;
    }
    if(p != L)
        return i;
    else 
        return 0;
}

//5.插入结点操作
void insList(LinkList L, int i, ElemType e){
    LinkList p, s;

    if(i>getLength(L)+1 && i<0){
        printf("ins Error\n");
        return;
    }
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    p = getElem(L, i-1);
    if(p != NULL){
        s->next = p->next;
        p->next = s;
    }
}

//6.删除结点,按序号
void delList(LinkList L, int i, ElemType *e){
    LinkList p, q;

    p = getElem(L, i-1);
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
}

//7.求表长
int getLength(LinkList L){
    int i = 0;
    LinkList p = L->next;

    while(p != L){
        p = p->next;
        i++;
    }

    return i;
}

//8.销毁链表
void destroyList(LinkList L){
    LinkList p, q;
    p = L->next;

    while(p != L){
        q = p;
        p = p->next;
        free(q);
    }
}

//9.遍历链表,当ElemType为int时
void traverseList(LinkList L){
    LinkList p = L->next;
    printf("%4d", L->data);
    while(p != L){
        printf("%4d", p->data);
        p = p->next;
    }
    putchar('\n');
}
