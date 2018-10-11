#include <stdio.h>
#include <stdlib.h>

int menu(){
    int num;
    printf("Which you want to text\n");
    printf("1.Dispise\n");
    printf("2.Annabel_Lee\n");
    printf("3.Dear Esther\n");
    printf("Give me number:");
    scanf("%d",&num);
    getchar();

    return num;
}

int main(int argc, char *argv[]){
    FILE *fp = NULL;
    char ch;
    int i,num;
    int flag = 1;
    
    if(argv[1] != NULL){
        printf("You have given me %s\n", argv[1]);
        if(*argv[1] == '2')
            num = 2;
        else if(*argv[1] == '1')
            num = 1;
    }
    else
        num = menu();
    fflush(stdin);

    switch(num){
        case 1:
            fp = fopen("./essay/seven","rt");
            break;
        case 2:
            fp = fopen("./essay/annabel_lee","rt");
            break;
        default:
            printf("input error\n");
            break;
    }
    
    if(fp == NULL){
        printf("File open err!\n");
        exit(0);
    }

    while(flag){
        printf(">");
        while((ch = fgetc(fp)) != '\n'){
            if(ch != EOF)
                putchar(ch);
            else{
                flag = 0;
                puts("END");
                break;
            }
        }
        printf("\n>");
        while(getchar() != '\n');
        printf("\n");
    }

    if(fclose(fp)){ printf("File close err!\n");
        exit(1);
    }

    printf("\nPiece of cake!\n");
    system("date");
}
