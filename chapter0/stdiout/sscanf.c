#include <stdio.h>

int main(int argc, char *argv[]){

    int i;
    unsigned int j;
    float f;
    char input[] = "22 0x1a zdevi may 0.2";
    char s[5];

    sscanf(input,"%d %x %5[a-z] %*s %f", &i, &j, s, &f);
    printf("%d, %d, %s, %f\n",i,j,s,f);
}
