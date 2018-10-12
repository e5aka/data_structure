#define MaxSize 9
typedef char ElemType;

#include <stdio.h>
#include <stdlib.h>//exit(0)
#include <stdbool.h> 
#include "../SqStack.h" 

bool validate(char *arr){
    int i=0;
    int j=0, k=0;
    while(arr[i] != '\0'){
        switch(arr[i]){
            case 'i':
                j++;
                break;
            case 'o':
                k++;
                if(k>j){
                    printf("Seq ERROR!\n");
                    exit(0);
                }
                break;
        }
        i++;
    }
    if(j != k){
        printf("Seq ERROR!\n");
        return false;
    }else{
        printf("Seq Right\n");
        return true;
    }
}

bool validate2(char *arr){
    int a, b, i, j;
    a=b=i=j=0;

    while(*(arr+i) != '\0'){
        if(*(arr+i) == 'i')
            a++;
        else if(*(arr+i) == 'o'){
            if(a <= b){
                printf("ERROR_1\n");
                exit(0);
            }else
                b++;
        }
    i++;
    }
    if(a != b)
        printf("ERROR_2\n");
    else if(a == b)
        printf("Right\n");
}

int main(int argc, char *argv[]){
    char arr[MaxSize];
    int i;

    puts("Please give me a operation seq");
    for(i=0;i<MaxSize-1;i++){
        scanf("%c", &arr[i]);
    }
    printf("\n\n");

    puts("The IO seq is the following");
    for(i=0;i<MaxSize;i++)
        printf("%c. ", *(arr+i));
    putchar('\n');

    validate2(arr);
    return 0;
}
