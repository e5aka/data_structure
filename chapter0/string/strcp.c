#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int cmpstring(char *s1, char *s2);
    int ret;
    char str1[80], str2[80];

    printf("Please give me a string:\n");
    scanf("%s",str1);

    printf("A string again:\n");
    scanf("%s",str2);

    ret = cmpstring(str1, str2);
    printf("ret = %d\n",ret);
    if(ret>0)
        printf("str1 > str2\n");
    else if(ret<0)
        printf("str1 < str2\n");
    else
        printf("str1 = str2\n");

    return 0;
}

int cmpstring(char *s1, char *s2){
    while(*s1)
        if(*s1 - *s2){
            printf("s1 = %c,ascii=%d\n",*s1,*s1);
            printf("s2 = %c,ascii=%d\n",*s2,*s2);
            printf("s1 != s2\n"); 
            return *s1-*s2;
        }
        else{
            s1++;
            s2++;
        }
}
