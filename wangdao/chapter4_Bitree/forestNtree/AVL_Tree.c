typedef int ElemType;
#define MaxSize 20

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode{
    ElemType key;
    int bf;             //balanced factor
    struct BSTNode *lc, *rc;
}BSTNode,*AVLtree;       //not origin

//balance
void rightRotate(AVLtree *T);    //LL
void leftRotate(AVLtree *T);     //RR
void leftBalance(AVLtree *T);    //LR
void rightBalance(AVLtree *T);   //RL
//basic operations
BSTNode *search_AVL_nr(AVLtree T, ElemType key);
BSTNode *search_AVL_rec(AVLtree T, ElemType key);
int insert_AVL(AVLtree *T, ElemType k, int *taller);
void create_AVL(AVLtree *T, ElemType str[], int n);
void delNode(AVLtree *T);
int delete_AVL(AVLtree *T, ElemType x);

void rightRotate(AVLtree *T);    //LL
void leftRotate(AVLtree *T);     //RR
void leftBalance(AVLtree *T){    //LR
}
void rightBalance(AVLtree *T){   //RL
}

int insert_AVL(AVLtree *T, ElemType k, int *taller){
    if(!(*T)){
        (*T) = (BSTNode*)malloc(sizeof(BSTNode));
        (*T)->key = k;
        (*T)->lc = (*T)->rc = NULL;
        (*T)->bf = 0;   //init bf
        *taller = 1;    //init taller
        return 1;
    }else{
        if(k == (*T)->key){
            *taller = 0;
            return 0;
        }else if(k < (*T)->key){
            if(insert_AVL(&(*T)->lc, k, taller))
                return 0;
            if(*taller){            //insed and LST is taller
                switch((*T)->bf){   //check balance
                    case 1:
                        leftBalance(T); //lst>rst, before ins
                        *taller = 0;
                        break;
                    case 0:             //lst=rst, before ins
                        (*T)->bf = 1;
                        *taller = 1;
                        break;
                    case -1:            //lst<rst, before ins
                        (*T)->bf = 0;   //lst=rst, now
                        *taller = 0;
                }
            }
        }else{  //k > (*T)->key
            if(insert_AVL(&(*T)->rc, k, taller))
                return 0;
            if(*taller){
                switch((*T)->bf){   //check balance
                    case 1:
                        (*T)->bf = 0;   //lst>rst, before ins
                        *taller = 0;    //lst=rst, now
                        break;
                    case 0:             //lst=rst, before ins
                        (*T)->bf = -1;
                        *taller = 1;
                        break;
                    case -1:            //lst<rst, before ins
                        rightBalance(T);
                        *taller = 0;
                }
            }
        }
    }
    return 1;
}

void create_AVL(AVLtree *T, ElemType str[], int n);

void main(){

    puts("Devil may cry");

}
