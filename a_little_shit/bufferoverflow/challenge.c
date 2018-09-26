#include <stdio.h>
#include <string.h>

void challenge(char *str){
    char temp[9] = {0};
    strncpy(temp, str, 8);
    printf("temp=%s\n", temp);
    if(strcmp(temp, "Please!@") == 0){
        printf("KEY: ****");
    }
}

int main(int argc, char *argv[]){
    char buf2[30];
    int check = 1;
    char buf[8];
    strcpy(buf2, "give me key!!");
    strcpy(buf, argv[1]);
    if(check == 65){
        challenge(buf);
    }else{
        printf("Check is not 65(%d) \n Program terminated!!\n", check);
    }
    return 0;
}
