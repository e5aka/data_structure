#include <stdio.h>
#define MaxSize 20

int fact_r(int n);
int fact_nr(int n);

void main(){
    int f, n;
    printf("Please give me a Interger(n<15):");
    scanf("%d", &n);

    puts("Devise with recur");
    f = fact_r(n);
    printf("n! = %4d\n", f);

    puts("Devise without recur");
    f = fact_nr(n);
    printf("n! = %4d\n", f);
}

int fact_r(int n){
    if(n == 1)
        return 1;
    else
        return n*fact_r(n-1);
}

int fact_nr(int n){
    int s[MaxSize][2];
    int top = -1;   //stack top

    s[++top][0] = n;    //n
    s[top][1] = 0;      //n*(n-1)

    while(top>=0){
        if(s[top][0] == 1){ //Recursion's exit
            s[top][1] = 1;
            printf("1.n = %4d, fact = %4d\n", s[top][0], s[top][1]);
        }
        if(s[top][0]>1 && s[top][1]==0){    //push in order
            s[++top][0] = s[top-1][0]-1;
            s[top][1] = 0;
            printf("2.n = %4d, fact = %4d\n", s[top][0], s[top][1]);
        }
        if(s[top][1] != 0){                 //pop output 
            s[top-1][1] = s[top][1]*s[top-1][0];
            printf("3.n = %4d, fact = %4d\n", s[top-1][0], s[top-1][1]);
            top--;
        }
    }

    return s[0][1];
}
