#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    ElemType elem;
    struct Node *next;
}LNode;
typedef struct Node *LinkList;

//10.判断为空否
bool listEmpty(LinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

//0.初始化
void initList(LinkList *L){
    *L = (LNode*)malloc(sizeof(LNode));
    if(L == NULL)
        exit(0);
    (*L)->next = NULL;
}

//1.头插法创建单链表
LinkList createList(LinkList L){
    LinkList s;
    int x;

    L = (LNode*)malloc(sizeof(LNode));  //Head Node
    L->next = NULL;

    scanf("%d", &x);
    while(x != 999){
        s = (LNode*)malloc(sizeof(LNode));
        s->elem = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//2.采用尾插法创建单链表
LinkList createList2(LinkList L){
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LinkList s, r = L;   //r为表尾指针
    
    scanf("%d", &x);
    while(x != 999){
        s = (LNode*)malloc(sizeof(LNode));
        s->elem = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//3.按序号查找结点值,取出带头指针的第i个位置的结点指针
LinkList getElem(LinkList L, int i){
    int j = 1;
    LinkList p = L->next;

    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while(p && j<i){
        p = p->next;
        j++;
    }
    return p;
}

//4.按值查找表节点
LinkList locateElem(LinkList L, ElemType e){
    LinkList p = L->next;
    
    while(p!=NULL && p->elem!=e)
        p = p->next;
    return p;
}

//4.1.按值查找表节点,返回列序
int locatePos(LinkList L, ElemType e){
    LinkList p = L->next;
    int i = 1;

    if(listEmpty(L))
        return 0;
    while(p && p->elem!=e){
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else 
        return 0;
}

//5.插入结点操作
void listInsert(LinkList L, int i, ElemType e){
    LinkList p, s;

    s = (LNode*)malloc(sizeof(LNode));
    s->elem = e;
    p = getElem(L, i-1);
    if(p != NULL){
        s->next = p->next;
        p->next = s;
    }
}

//6.删除结点,按序号
void listDelete(LinkList L, int i, ElemType *e){
    LinkList p, q;

    p = getElem(L, i-1);
    q = p->next;
    *e = q->elem;
    p->next = q->next;
    free(q);
}

//7.求表长
int getLength(LinkList L){
    int i = 0;
    LinkList p = L->next;

    while(p != NULL){
        p = p->next;
        i++;
    }

    return i;
}

//8.销毁链表
void destroyList(LinkList L){
    LinkList p, q;
    p = L->next;

    while(p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
}

//9.遍历链表,当ElemType为int时
void traverseList(LinkList L){
    LinkList p = L->next;
    while(p != NULL){
        printf("%4d", p->elem);
        p = p->next;
    }
    putchar('\n');
}

