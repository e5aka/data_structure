#include <stdio.h>

int main(void){
    printf("Broken wings will flay\n");
    printf("int:%d Bytes\n",sizeof(int));
    float s = 3.3f*4.2f;
    printf("s=%f\n",s);
    int i;
    printf("int=%d\n",(i=2*4,i*3),i*8);
    if(5>3||3>5)
        printf("Logoc computer\n");

    int a, b;
    a = 4;
    b = a+++a+++a++;
    while(getchar()!='y');
    printf("b = %d\n",b);

    char str[8];
    printf("Please input at least 8 char:");
    puts(str);
    return 0;
}
