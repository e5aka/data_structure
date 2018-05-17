#include<stdio.h>

typedef int KeyType;

typedef struct
{
	KeyType key;
}DataType;

void ShellSort(DataType a[], int n, int d[], int numOfD)
{
	int i,j,k,m,span;
	DataType temp;

	for(m=0;m<numOfD;m++)
	{
		span=d[m];
		for(k=0;k<span;k++)
		{
			for(i=k;i<n-span;i=i+span)
			{
			temp=a[i+span];
			j=i;
			while(j>-1&&temp.key<=a[j].key)
			{
				a[j+span]=a[j];
				j=j-span;
			}
			a[j+span]=temp;
			}
		}
	}
}

void main(void)
{
	DataType test[10]={43,5,47,1,19,11,59,15,48,41};
	int i,n=10;
	int a[3]={5,2,1};

	ShellSort(test,n,a,3);

	for(i=0;i<n;i++)
	{
		printf("%d   ",test[i].key);
	}
}