#include<stdio.h>

void Add(int a[], int b[], int c[], int n)
{	
	int i;
	for(i=0;i<=n*(n+1)/2-1;i++)
		c[i]=a[i]+b[i];
}

void Multiplication (int a[], int b[], int c[], int n)
{
	int i,j,k,v,p,q,sum;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=j)
			{
				v=i*(i-1)/2+j-1;
				sum=0;
				for(k=1;k<=n;k++)
				{
					if(i>=k) p=i*(i-1)/2+k-1;
					else p=k*(k-1)/2+i-1;

					if(j>=k) q=j*(j-1)/2+k-1;
					else q=k*(k-1)/2+j-1;

					sum=sum+a[p]*b[q];
				}
				c[v]=sum;
			}
		}
	}
}

void Print(int a[], int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		if(i>=j) k=i*(i-1)/2+j-1;
		else k=j*(j-1)/2+i-1;
		printf("%d   ",a[k]);
		}
	printf("\n");
	}
}

void main(void)	
{
	int a[]={1,2,3},
		b[]={1,2,3},
		c[4];
	int n=2;

	printf("矩阵加法运算:\n");
	Add(a,b,c,n);
	Print(c,n);
	printf("\n");

	printf("矩阵乘法运算:\n");
	Multiplication(a,b,c,n);	
	Print(c,n);
	printf("\n");
}