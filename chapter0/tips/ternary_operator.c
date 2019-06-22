#include <stdio.h>

int main(){
    int a, b;

    a = 10;
    b = (a==1) ? 20:30;
    printf("b = %d\n", b);

    b = (a==10) ? 20:30;
    printf("b = %d\n", b);
}
