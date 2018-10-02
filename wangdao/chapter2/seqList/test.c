#include <stdio.h>

void func();

int count = 10;

void main()
{
    while(count--)
        func();
}

void func()
{
    static int thingy = 5;
    thingy++;
    printf("Thingy = %d; Count = %d\n", thingy, count);
}
