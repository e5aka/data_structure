#include<stdio.h>
int Add (int a[], int n)
{
	if(n<0)
	{
		printf("参数错！");
		return -1;
	}

	if(n==0) return a[0];
	else return a[n]+Add(a,n-1);

}

void main(void)
{
	int a[]={1,3,5,7,9,11,13,15,17},n;
	printf("请输入累加的个数N：");
	scanf("%d",&n);
	printf("%d\n",Add(a,n-1));
}