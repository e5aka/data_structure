#include <stdio.h>

int main(int agrc, char *agrv[]){
    int a[4][5];
    int i,j;
    int k = 1;

    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            a[i][j] = k++;

    for(i=0;i<4;i++)
        for(j=0;j<5;j++)
            printf("a[%d][%d]=%d\n",i,j,a[i][j]);

    printf("The variable a in %p\n", a);
    printf("The variable *a in %p\n", *a);
    printf("The variable a[0] in %p\n", a[0]);
    printf("The variable a+1 is %d\n", *(*(a+1)+1));
    printf("The variable a+1 in %p\n", *(a+1)+1);

    return 0;
}
