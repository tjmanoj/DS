#include <stdio.h>
int main() {
    int ar[100],i,j,n,temp;
    printf("Enter array size:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    for(i=1;i<n;i++){
        temp=ar[i];
        j=i-1;
        while(j>=0 && ar[j]>temp){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
    }
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
}
