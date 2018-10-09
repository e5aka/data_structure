#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char *argv[]){

    int i, j;
    int s[3][4];

    srand((unsigned)time(NULL));
    for(j=0;j<3;j++)
        for(i=0;i<4;i++)
            s[j][i] = rand()%10; 
    for(j=0;j<3;j++){
        for(i=0;i<4;i++)
            printf("%-3d ", s[j][i]);
        putchar('\n');
    }
    printf("RAND_MAX is %d\n",RAND_MAX);
    putchar('\n');

    time_t t;
    printf("time_t is %d\n",t);
    printf("time is %d\n",time);
    time(&t);
    printf("time() is %d\n",t);
    char buf[1024];
    ctime_r(&t,buf);
    printf("The time is %s",buf); 
}
