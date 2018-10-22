#include <stdio.h>

enum DAY{MON=1, TUE, WED, THU=7, FRI, SAT, SUN};

void main(){
    enum DAY day;

    day = FRI;
    printf("Currently, day = %d\n", day);

    puts("not able to traverse by enum");
    for(day=MON;day<=SUN;day++)
        printf("Day = %d\n", day);
}
