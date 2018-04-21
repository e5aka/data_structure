#include <stdio.h>
#define MAXSIZE 255
typedef unsigned char Sstring[MAXSIZE+1];

int indexSerach(Sstring S, Sstring T, int pos){
    int i = pos;
    int j = 1;
    while(i<=S[0]&&j<=T[0]){
        if(S[i]==T[j]){
            i++;
            j++;
        }else{
            i = i-j+2;
            j = 1;
        }
    }
    if(j>T[0])
        return i-T[0];
    else 
        return 0;
}

int countString(Sstring s){
    int i = 0;
    while(i+1){
        if(s[i+1]!='\0')
            i++;
        else
            return i;
    }
    return 9;
}

void main(){
    Sstring a, b;
    printf("Please input a string:\n");
    scanf("%s",&a[1]);
    a[0] = countString(a);
    printf("Please input the string you want to search:\n");
    scanf("%s",&b[1]);
    b[0] = countString(b);
    printf("The string you search in the %d\n",indexSerach(a,b,1));
}

