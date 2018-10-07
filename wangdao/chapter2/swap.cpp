#include <stdio.h>

//引用
void myswap(int &x, int &y){
    int t;
    t = x;
    x = y;
    y = t;
}

int main(){
    int a, b;
    printf("Please input two num:");
    scanf("%d %d", &a, &b);
    myswap(a, b);
    printf("Afted swaped: %d , %d\n", a, b);
    return 0;
}
