#include <stdio.h>
#define num 10

int isearch(int a[], int n, int x){
    int mid, low, high;
    low = 0;
    high = n-1;

    while(low <= high){
        mid = (low+high)/2;
        if(a[mid] == x){
            printf("Jackpot\t");
            return mid;
        }
        else if(a[mid]>x)
            high = mid-1;
        else 
            low = mid+1;
    }
    return -1;
}

void bubble_sort(int a[], int n){
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=n-1;j>i;j--)
            if(a[i]>a[j]){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
}

int main(int argc, char *arg[]){
    int i,j,k=0;
    int a[num];

    srand((unsigned)time(NULL));
    for(i=0;i<num;i++){
        a[i] = rand()%20;
    }

    bubble_sort(a,num);
    printf("The sorted queue is \n");
    for(i=0;i<num;i++){
        printf("%d ", a[i]);
    }

    printf("\nTell me you want:");
    scanf("%d",&j);
    k = isearch(a,num,j);
    printf("What u want in %d",k);

    puts("\nPieces of cake");
    return 0;
}
