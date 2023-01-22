#include<stdio.h>
int main(){
	int i,j,n,s,t=0,t1=0;
	printf("Enter number of elements:");
	scanf("%d",&n);
	int ar[n];
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
		scanf("%d",&ar[i]);
	//Linear Search
	printf("Enter search element:");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		if(ar[i]== s){
			printf("Element found at index %d\n",i+1);
			t=1;
		}
	}
	if(t==0)
		printf("Element not found!\n");
	//Binary Search
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(ar[i]>ar[j]){
				t=ar[i];
				ar[i]=ar[j];
				ar[j]=t;
			}
	printf("Enter search element:");
	scanf("%d",&s);
	printf("Sorted Array:\n");
	for(i=0;i<n;i++)
		printf("%d ",ar[i]);
	int st=0,sp=n-1,mid;
	for(i=0;i<n;i++){
		mid=(st+sp)/2;
		if(s==ar[mid]){
			printf("\nElement found at index %d\n",mid+1);
			t1=1;
			break;
		}
		else if(s>ar[mid])
			st=mid+1;
		else
			sp=mid-1;
	}
	if(t1==0)
		printf("\nElement not found!\n");
}
