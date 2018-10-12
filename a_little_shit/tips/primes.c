//primes n.质数
#include <stdio.h>
#include <math.h>

#define N 100

void main(){
    int i, j, num, a[N+1];
    for(i=2;i<=N;i++)
        a[i]=i;
    for(i=2;i<=sqrt(N);i++)
        if(a[i]!=0)
            for(j=i+1;j<=N;j++)
                if(a[j]!=0)
                    if(a[j]%a[i]==0)
                        a[j]=0;
    printf("\n");
    for(i=2,num=0;i<=N;i++){
        if(a[i]!=0){
            printf("%3d:%d\t",i,a[i]);
            num++;
        }
        if(num==10){
            printf("\n");
            num=0;
        }
    }
    printf("\n\n");
}
