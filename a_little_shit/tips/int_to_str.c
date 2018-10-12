#include <stdio.h>

char *int_to_str(int int_value){
    static char buf[20];
    sprintf(buf, "%d", int_value);

    return buf;
}

int main(int argc, char *argv[]){
    char *str1;
    char *str2;

    str1 = int_to_str(5);
    str2 = int_to_str(10);

    printf("str1 = %s\nstr2 = %s\n", str1, str2);
    
    return 0;
}
