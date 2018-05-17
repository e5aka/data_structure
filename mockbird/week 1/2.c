#include<stdio.h>
struct student
	{
		long number;
		char name[10];
		double mark;
	}stu[4];

int main()
{	int i,k;

	struct student stu[4]=
	{
	{101,"zhang",95.6},
	{102,"wang",99.4},
	{103,"zhao",85.7},
	{104,"li",92.1},
	};


	for (i=1;i<=3;i++)
	{	if (stu[0].mark<stu[i].mark) 
		{	stu[0].mark=stu[i].mark;
			k=i;
		}	
	}
	printf("学号：%d\t姓名：%s\t成绩：%f\n",stu[k].number,stu[k].name,stu[k].mark);
    return 0;
}

