#include<stdio.h>
int main()
{
	int n,a[n],i,j,pos,swap;
	printf("Enter number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter element %d:",i+1);
	scanf("%d",&a[i]);
    }
	for(i=0;i<n;i++)
	{
	pos=i;
	for(j=i+1;j<n;j++)
		if(a[pos]>a[j])
		    pos=j;
    swap=a[i];
    a[i]=a[pos];
    a[pos]=swap;
}
    printf("Sorted array:");
    for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
