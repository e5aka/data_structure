typedef int ElemType;
#define MaxSize 20

#include <stdio.h>
#include <stdlib.h>
#include "CSTree.h"
//The tree
//               A
//             / | \
//            B  C  D
//           / \     \
//          E   F     G
//            / | \
//           H  I  J
void main(){
    int test[] = {'A','B','E',0,'F','H',0,'I',0,'J',0,0,0,'C',0,'D','G',0,0,0,0};
    int h = 0;
    CSTree T;
    initCSTree(&T);
    createCSTree(&T, test, &h);
    puts("Preroot traverse Tree:");
    preTraverseCST(T);
    putchar('\n');
    puts("Postroot traverse Tree:");
    postTraverseCST(T);
    putchar('\n');

    printf("The depth of tree is : %d\n", getDepthCST(T));
    printf("depth by wda : %d\n", getDepthWD(T));
    printf("The leaves : %d\n", getLeaves(T));
    putchar('\n');

    destroyCSTree(&T);
}
