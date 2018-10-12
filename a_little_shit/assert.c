#include <stdio.h>
#include <assert.h>

void main(){
    int a;

    puts("Please give me a valve:");
    scanf("%d", &a);
    assert(a==9);
    puts("It's over");
}
