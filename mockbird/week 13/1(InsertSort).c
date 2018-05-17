#include<stdio.h>

typedef int KeyType;

typedef struct
{
	KeyType key;
}DataType;

void InsertSort(DataType a[],int n)
{
	int i,j;
	DataType temp;

	for(i=0;i<n-1;i++)
	{
		temp=a[i+1];
		j=i;
		while(j>-1&&temp.key<a[j].key)
		{
		a[j+1]=a[j];
		j--;
		}
		a[j+1]=temp;
	}
}

void main(void)
{
	DataType test[10]={43,5,47,1,19,11,59,15,48,41};
	int i,n=10;

	InsertSort(test,n);

	for(i=0;i<n;i++)
	{
		printf("%d   ",test[i].key);
	}
}