#include <stdio.h>
#include<string.h>
#define Maxlength 100
#include"SString.h"
void main(void)
{
	String myString1,myString2,myString3;
	int start=0;

	printf("����������myString1:");
	gets(myString1.str);
	printf("�������Ӵ�myString2:");
	gets(myString2.str);
	printf("�������Ӵ�myString3:");
	gets(myString3.str);

	myString1.length=strlen(myString1.str);
	myString2.length=strlen(myString2.str);
	myString3.length=strlen(myString3.str);

	if(Replace(&myString1,start,myString2,myString3)==0)
	{
		printf("���ɹ�\n");
	}
	else
	{
		printf("�޸ĺ������Ϊ��");
		puts(myString1.str);
	}

}
