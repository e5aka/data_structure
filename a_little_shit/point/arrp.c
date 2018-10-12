#include <stdio.h>

int main(int agrc, char *agrv[]){
    int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int (*p)[4];
    int row, col;
    p = a;

    printf("*p = %p\n", *p);
    for(row=0;row<3;row++){
        for(col=0;col<4;col++)
            printf("a[%d,%d] = %-4d ", row, col, *(*(p+row)+col));
        printf("\n");
    }
    for(p=a,row=0;p<a+3;p++,row++){
        for(col=0;col<4;col++)
            printf("(*p[%d])[%d]=%p ", row, col, ((*p)+col));
        putchar('\n');
    }

}
