#include <stdio.h>
#define MaxSize 100
typedef struct
{
	char str[MaxSize];
	int length;
} String;

int Insert(String *S, int pos, String T)
{
	int i;
	if(pos < 0)
	{
		printf("参数pos出错！");
		return 0;
	}
	else if(S->length + T.length > MaxSize)
	{
		printf("数组空间不足无法插入！");
		return 0;
	}
	else
	{
		for(i = S->length-1; i >= pos; i--)
			S->str[i+T.length] = S->str[i];		
		for(i = 0; i < T.length; i++)
			S->str[pos+i] = T.str[i];			
		S->length += T.length;					
		return 1;
	}
}

int Delete(String *S, int pos, int len)
{
	int i;
	if(S->length <= 0)
	{
		printf("数组中未存放字符无元素可删! \n");
		return 0;
	}
	else if(pos < 0 || len < 0 || pos+len > S->length)
	{
		printf("参数pos和len出错");
		return 0;
	}
	else
	{
		for(i = pos+len; i <= S->length-1; i++)
			S->str[i-len] = S->str[i];				
		S->length -= len;					
		return 1;
	}
}

int BFIndex(String S,int start,String T)
{
	int i=start,j=0,v;

	while(i<S.length&&j<T.length)
	{
		if(S.str[i]==T.str[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j==T.length) v=i-T.length;
	else v=-1;
	return v;
}

int Replace(String *S,int start,String T,String V)
{
	int Q,pos,i=start,j=0;

	while(i<S->length&&j<T.length)
	{
		if(S->str[i]==T.str[j])
		{
			i++;
			j++;
			pos=i-T.length;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j==T.length)
	{
	Delete(S,pos,T.length);
	Insert(S,pos,V);
	Q=1;
	}
	else Q=0;
	return Q;
}