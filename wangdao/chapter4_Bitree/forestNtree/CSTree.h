//typedef int ElemType;
//#define MaxSize 20

//Child Sibling Expression
typedef struct CSNode{
    ElemType data;
    struct CSNode *fc, *ns; //first child, next sibling
}CSNode, *CSTree;

void initCSTree(CSTree *T);
void destroyCSTree(CSTree *T);
void createCSTree(CSTree *T, ElemType *e, int *index);
int getDepthCST(CSTree T);
void preTraverseCST(CSTree T);
void postTraverseCST(CSTree T);
void printCST(ElemType *e);
int getLeaves(CSTree T);

void initCSTree(CSTree *T){
    *T = 0;
}

void destroyCSTree(CSTree *T){
    CSTree p = *T;
    if(p){
        destroyCSTree(&(p->fc));
        destroyCSTree(&(p->ns));
        free(p);
        *T = 0;
    }
}

void createCSTree(CSTree *T, ElemType *e, int *index){
    if(e[*index] == 0){
        *T = 0;
        (*index)++;
    }else{
        *T = (CSNode*)malloc(sizeof(CSNode));
        (*T)->data = e[(*index)++];
        createCSTree(&((*T)->fc), e, index);    //2bt
        createCSTree(&((*T)->ns), e, index);
        return;
    }
}

int getDepthCST(CSTree T){
    CSNode *p;
    int k, d = 0;
    if(!T)
        return 0;
    p = T->fc;
    while(p){
        k = getDepthCST(p);
        if(d<k)
            d = k;
        p = p->ns;
    }
    return d+1;
}

int getDepthWD(CSTree T){
    int hc, hs;
    if(!T)
        return 0;
    else{
        hc = getDepthWD(T->fc); //fc height
        hs = getDepthWD(T->ns); //ns heigth
        if(hc+1 > hs)
            return hc+1;
        else
            return hs;
    }
}

void preTraverseCST(CSTree T){
    if(T){
        printf("%c ", T->data);
        preTraverseCST(T->fc);
        preTraverseCST(T->ns);
    }
}

void postTraverseCST(CSTree T){
    if(T){
        postTraverseCST(T->fc);
        printf("%c ", T->data);
        postTraverseCST(T->ns);
    }
}

void printCST(ElemType *e){
    printf("%c ", *e);
}

int getLeaves(CSTree T){
    if(!T)
        return 0;
    else if(!T->fc)
        return getLeaves(T->ns)+1;
    else
        return getLeaves(T->fc)+getLeaves(T->ns);
}

//               A
//             / | \
//            B  C  D
//           / \     \
//          E   F     G
//            / | \
//           H  I  J
