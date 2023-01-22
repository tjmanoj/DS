#include<stdio.h>
int arr[100];
void sort();
void merge();
int main(){
	int i,n;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(0,n-1);
	printf("Sorted array:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
void sort(int start,int end){
	if(start < end){
		int mid=(start+end)/2;
		sort(start,mid);
		sort(mid+1,end);
		merge(start,mid,end);
	}
}
void merge(int start,int mid,int end){
	int temp[100],i=start,j=mid+1,k=start;
	while((i <= mid)&& (j<=end)){
		if(arr[i] < arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=mid)
		temp[k++]=arr[i++];
	while(j<=end)
		temp[k++]=arr[j++];
	for(i=start;i<=end;i++)
		arr[i]=temp[i];
}

