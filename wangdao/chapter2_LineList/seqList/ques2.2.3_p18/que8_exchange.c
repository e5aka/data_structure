typedef int ElemType;
#define MaxSize 100

#include <stdio.h>
#include "../SqList.h"

bool reverse(ElemType *arr, int lf, int rt, int arraySize){
    int i;
    ElemType temp;
    if(lf>=rt || rt>=arraySize)
        return false;
    int mid = (lf+rt)/2;
    for(i=0;i<=mid-lf;i++){
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

bool traverse_list(ElemType *arr, int arraySize){
    int i;
    for(i=0;i<arraySize;i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[]){
    int i, j;
    ElemType arr[] = {1,3,5,7,9,2,4,6,8};
    int arraySize = sizeof(arr)/sizeof(arr[0]);

    printf("The arraySize is %d\n",sizeof(arr));
    puts("Before exchange:");
    traverse_list(arr, arraySize);

    exchange(arr, 5, 4, arraySize);
    puts("After exchange:");
    traverse_list(arr, arraySize);

    printf("EOF = %d\n", EOF);

    return 1;
}
