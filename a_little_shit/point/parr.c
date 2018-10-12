#include <stdio.h>

int main(int agrc, char *agrv[]){

    char *book[4] = {
        "C Program Language","Assembly Language","Java Language","Natural Language"
    };
    int n=4;
    int row;
    char *arrayPtr;
    int *ii;

    printf("The char* size is %d\n", sizeof(book[2]));
    printf("a char* is %d\n",sizeof(arrayPtr));
    printf("a int* is %d\n",sizeof(ii));

    printf("Output(by array name):\n");
    for(row=0;row<n;row++)
        printf("Str %d: %s\n", row+1, book[row]);

    putchar('\n');

    printf("Output2(by point array):\n");
    for(arrayPtr=book[0],row=0;row<n;arrayPtr=book[row]){
        printf("Str %d: %s\n", (row++)+1, arrayPtr);
    }
}
