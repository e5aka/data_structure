#include <stdio.h>
#include <string.h>

int verify(char *password){
    int auth;
    char buffer[8];
    auth = strcmp(password, "PASSWORD");
    strcpy(buffer, password);
    return auth;
}

int main(){
    int key, i;
    char pw[8] = "";
    printf("Please input a password:");
    gets(pw);
    //fgets(pw, 9, stdin);
    for(i=0;i<8;i++)
        printf("char[%d] = %c \n", i, pw[i]);
    key = verify(pw);
    printf("The result is %d\n", key);
    return 0;
}

