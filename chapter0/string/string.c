#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char str[] = "Devil may cry";
    char *pstr = str;
    int i, len = strlen(str);

    puts("Point output:");
    for(i=0;i<len;i++)
        printf("%c ", *(pstr+i));
    putchar('\n');

    puts("Array output");
    for(i=0;i<len;i++)
        printf("%c ", pstr[i]);
    putchar('\n');

    puts("Address output");
    for(i=0;i<len;i++)
        printf("%c ", *(str+i));
    putchar('\n');

    printf("pstr is %d\n", sizeof(pstr));
    printf("str is %d\n", sizeof(str));

    return 0;
}
