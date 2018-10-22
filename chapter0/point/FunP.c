#include <stdio.h>

void MyFun(int x, char *c);
void (*FunP)(int, char *);

int main(int argc, char *argv[]){
    char *a, *b;
    a = "Dante";
    b = "Danteng"; 
    char *c;
    c = "Dante";
    MyFun(10, a);
    FunP = &MyFun;
    (*FunP)(20, b);

    return 0;
}

void MyFun(int x, char *c){
    printf("x = %d\n",x);
    printf("He is %s\n",c);
}
