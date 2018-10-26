typedef int ElemType;
#define MaxSize 100

#include <stdio.h>
#include "../SqList.h"

bool reverse(ElemType *arr, int lf, int rt, int arraySize){
    ElemType temp;
    if(lf>=rt || rt>=arraySize)
        return false;
    int mid = (lf+rt)/2;
    for(int i=0;i<=mid-lf;i++){
        temp = arr[lf+i];
        arr[lf+i] = arr[rt-i];
        arr[rt-i] = temp;
    }
}

bool exchange(ElemType *arr, int m, int n, int arraySize){
    reverse(arr, 0, arraySize-1, arraySize);
    reverse(arr, 0, n-1, arraySize);
    reverse(arr, n, arraySize-1, arraySize);
}

int main(int argc, char *argv[]){
    int i, j;
    ElemType arr[] = {1,3,5,7,9,2,4,6,8};
    int arraySize = sizeof(arr)/sizeof(arr[0]);

    printf("The arraySize is %d\n",sizeof(arr));
    puts("Before exchange:");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf(" %d", arr[i]);
    printf("\n");

    exchange(arr, 5, 4, arraySize);
    puts("After exchange:");
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 1;
}
