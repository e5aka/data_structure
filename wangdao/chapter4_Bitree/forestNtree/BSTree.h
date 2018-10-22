//typedef int ElemType;
//#define MaxSize 20

typedef struct BSTNode{
    ElemType key;
    struct BSTNode *lc, *rc;
}BSTNode,*BSTree;      //not origin

BSTNode *search_BST_nr(BSTree T, ElemType key);
BSTNode *search_BST_rec(BSTree T, ElemType key);
int insert_BST(BSTree *T, ElemType k);
void create_BST(BSTree *T, ElemType str[], int n);
void delNode(BSTree *T);
int delete_BST(BSTree *T, ElemType x);

BSTNode *search_BST_nr(BSTree T, ElemType key){
    BSTNode *p = NULL;
    while(T && key!=T->key){
        p = T;
        if(key < T->key)
            T = T->lc;
        else
            T = T->rc;
    }
    return T;
}

//BSTNode *search_BST_rec(BSTree T, ElemType key);

int insert_BST(BSTree *T, ElemType k){
    if(!(*T)){
        (*T) = (BSTNode*)malloc(sizeof(BSTNode));
        (*T)->key = k;
        (*T)->lc = (*T)->rc = NULL;
        return 1;
    }
    else if(k == (*T)->key)
        return 0;
    else if(k < (*T)->key)
        return insert_BST(&(*T)->lc, k);
    else
        return insert_BST(&(*T)->rc, k);
}


void create_BST(BSTree *T, ElemType *str, int n){
    int i = 0;
    *T = NULL;

    while(i<n){
        insert_BST(&(*T), str[i]);
        i++;
    }
}

void inOrder(BSTree T){
    if(T){
        inOrder(T->lc);
        printf("%d ", T->key);
        inOrder(T->rc);
    }
}

void delNode(BSTree *T){
    BSTree q, x, y;
    if(!(*T)->rc){          //go left if right null
        q = *T;
        *T = (*T)->lc;
        free(q);
    }else if(!(*T)->lc){
        q = *T;
        *T = (*T)->rc;
        free(q);
    }else{                  //go back if both left and right is null
        x = *T;
        y = (*T)->lc;
        while(y->rc){
            x = y;
            y = y->rc;
        }
        (*T)->key = y->key;
        if(x != (*T))
            x->rc = y->lc;
        else
            x->lc = y->lc;
        free(y);
    }
}
    
int delete_BST(BSTree *T, ElemType x){
    if(*T){
        if(x == (*T)->key)
            delNode(T);
        else if((*T)->key > x)
            delete_BST(&(*T)->lc, x);
        else
            delete_BST(&(*T)->rc, x);
        return 1;
    }else
        return 0;
}
