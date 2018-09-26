#include <stdio.h>
#define PI 3.1415926

float area(float r);
float perimeter(float r);

int main(int arg, char *rgv[]){
    float r;
    float s, l;

    printf("Please give me ridus of the round:");
    scanf("%f",&r);

    s = area(r);
    l = perimeter(r);

    printf("The ridus is %.2f,which area is %.2f \n",r,s);
    printf("The ridus is %.2f,which perimeter is %.2f \n",r,l);
    char j=getchar();
    printf("getchr");

    return 0;
}

float area(float r){
    float s;
    s = PI*r*r;
    return s;
}

float perimeter(float r){
    float l;
    l = PI*r*2;
    return l;
}
