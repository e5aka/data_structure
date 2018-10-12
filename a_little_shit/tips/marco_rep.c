#include <stdio.h>
#define PRT(k) printf("%d\n",k)
#define MIN(x,y) x<y?x:y
#define Result(x,y) x*y

void main(){
    int a=3, b=5, m, r;
    m = MIN(a+b,a*b);
    printf("The minimum is : ");
    PRT(m);
    r = Result(a-b,a*b);
    printf("The result is : ");
    PRT(r);
}
