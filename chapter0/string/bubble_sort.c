#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30

void bubble(int *a, int n);

int main(){
    int arr[N], i;

    srand((unsigned)time(NULL));
    for(i=0;i<N;i++)
        arr[i] = rand()%100+10;

    puts("The origin queue is :\n");
    for(i=0;i<N;i++)
        printf("%d ", arr[i]);
    putchar('\n');

    bubble(arr, N);

    puts("The sorted queue is :\n");
    for(i=0;i<N;i++)
        printf("%d ", arr[i]);
    putchar('\n');

    return 0;
}

void bubble(int *a, int n){
    int i,j,k;
    for(i=0;i<N;i++)
        for(j=N-1;j>i;j--)
            if(a[i]<a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
}
