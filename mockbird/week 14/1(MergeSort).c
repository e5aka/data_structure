#include<stdio.h>
#include<stdlib.h>
typedef int KeyType;

typedef struct
{
	KeyType key;
}DataType;

void Merge(DataType a[], int n, DataType swap[] ,int k)
{
	int m=0,u1,l2,i,j,u2;
	int l1=0;

	while(l1+k<=n-1)
	{
		l2=l1+k;
		u1=l2-1;
		u2=(l2+k-1<=n-1)?l2+k-1:n-1;
	
		for(i=l1,j=l2;i<=u1&&j<=u2;m++)
		{
			if(a[i].key<=a[j].key)
			{
				swap[m]=a[i];
				i++;
			}
			else
			{
				swap[m]=a[j];
				j++;
			}
		}

		while(i<=u1)
		{
			swap[m]=a[i];
			m++;
			i++;
		}

		while(j<=u2)
		{
			swap[m]=a[j];
			m++;
			j++;
		}
		l1=u2+1;
	}
	for(i=l1;i<n;i++,m++)
		swap[m]=a[i];
}

void MergeSort(DataType a[], int n)
{
	int i,k=1;
	DataType *swap;

	swap=(DataType *)malloc(sizeof(DataType) *n);

	while(k<n)
	{
		Merge(a,n,swap,k);
		for(i=0;i<n;i++)
			a[i]=swap[i];
		k=2*k;
	}
	free(swap);
}

void main(void)
{
	DataType test[10]={43,5,47,1,19,11,59,15,48,41};
	int i,n=10;
	
	MergeSort(test,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d   ",test[i].key);
	}
}