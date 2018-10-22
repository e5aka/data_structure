#include <stdio.h>
#define N 10

struct student{
    char *number;
    char *name;
    char sex;
    int age;
    float score;
};

int main(int argc, char *argv[]){

    struct student stu[3]={{"06001", "Wang C", 'm', 22, 78.5},
            {"06002", "Li H", 'f', 21, 87.0},
            {"06003", "Zhang Y", 'm', 22, 90.0}};
    struct student *p;
    printf("学生基本情况表：\n");
    printf("编号\t\t姓名\t   性别     年龄    成绩\n");
    for(p=stu;p<stu+3;p++)
        printf("%-8s %12s %8c %8d %8.2f\n", p->number, p->name, p->sex, p->age, p->score);

    return 0;
}
