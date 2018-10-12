#include <stdio.h>

void main(){
    int i, j;
    char a, b;
    int key;
    char str[100];
    char *p, *q;

    printf("Give me a num\n");
    scanf("%d", &key);
    getchar();
    putchar('\n');

    switch(key){
        case 1:
            puts("字符I/O");

            printf("getchar input : ");
            a = getchar();  //marco defination
            printf("putchar output : ");
            putchar(a);
            break;

        case 2:
            puts("格式化行I/O");

            printf("fscanf input : ");
            fscanf(stdin, "%d", &i);
            printf("fprintf output : ");
            fprintf(stdout, "i = %d\n", i);

            //return int成功读取的数量,遇到文件结尾返回EOF
            printf("scanf input : ");
            scanf("%d ", &i);   //Attention "space"
            printf("printf output : ");
            printf("i = %d\n", i);

            printf("sscanf input : ");
            printf("sprintf output : ");

            break;

        case 3:
            puts("未格式化行I/O");

            //return char*
            printf("fgets input : ");
            p = fgets(str, 10, stdin);
            printf("fputs output : ");
            fputs(str, stdout);
            printf("point output : ");
            fputs(p, stdout);

            printf("gets input : ");
            gets(str);
            printf("puts output : ");
            puts(str);

            break;
    }
    //getc(a, stdin);
    //putc(a, stdout);
}
