#include<stdio.h>

typedef int KeyType;

typedef struct
{
	KeyType key;
}DataType;

void QuickSort(DataType a[], int low, int high)
{
	int i=low,j=high;
	DataType temp=a[low];

	while(i<j)
	{
		while(i<j&&temp.key<=a[j].key)j--;
		if(i<j)
		{
			a[i]=a[j];
			i++;
		}

		while(i<j&&a[i].key<=temp.key)i++;
		if(i<j)
		{
			a[j]=a[i];
			j--;
		}
	}
	a[i]=temp;
	if(low<i) QuickSort(a,low,i-1);
	if(i<high) QuickSort(a,j+1,high);
}


void main(void)
{
	DataType test[10]={43,5,47,1,19,11,59,15,48,41};
	int i,n=10;
	
	QuickSort(test,0,9);
	
	for(i=0;i<n;i++)
	{
		printf("%d   ",test[i].key);
	}
}