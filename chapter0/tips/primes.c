//primes n.质数
#include <stdio.h>
#include <math.h>

#define N 100

void main(){
    int i, j, num=1, a[N+1];

    //generate primes
    for(i=2;i<=N;i++)
        a[i]=i;
    for(i=2;i<=sqrt(N);i++)
        if(a[i]!=0)
            for(j=i+1;j<=N;j++)
                if(a[j]!=0)
                    if(a[j]%a[i]==0)
                        a[j]=0;
    printf("\n");

    //output
    for(i=2;i<=N;i++){
        if(a[i] != 0){
            printf("%-3d:%5d\t",num,a[i]);
            if((num++)%5 == 0)
                printf("\n");
        }
    }
    printf("\n\n");
}
