#include<stdio.h>
struct node {
	int data,p;
}a[100];
int pos=0,n;
int insert(struct node num,int i){
	int parent = (i-1)/2;
	if(i >= n){
		printf("Heap Overflow");
		pos=n-1;
		return 0;
	}
	if(i == 0){
		a[i]=num;
		return 0;
	}
	if(num.p < a[parent].p){
		a[i]=a[parent];
		a[parent]=num;
		insert(num,parent);
	}
	else{
		a[i]=num;
		return 0;
	}
}
int Delete(int n){
	int left,right,i=0;
	struct node last= a[n-1],root;
	if(n == 0){
		printf("Heap Empty");
	}
	root=a[0];
	pos=n=n-1;
	left=(i*2)+1,right=(i*2)+2;
	while(right <= n){
		if(last.p < a[left].p && last.p < a[right].p){
			a[i]=last;
			return 0;
		}
		if(a[left].p > a[right].p){
			a[i]=a[right];
			i=right;
		}
		else{
			a[i]=a[left];
			i=left;
		}
		left=(i*2)+1,right=(i*2)+2;
	}
	if(left == n && last.p > a[left].p){
			a[i]=a[left];
			i=left;
		}
		a[i]=last;
		printf("Deleted element:%d\n",root.data);
}
void display(){
    if(pos==0)
		printf("Heap is Empty");
	else{
	for(int i=0;i<pos;i++)
		printf("%d  ",a[i].data);
}}
int main(){
	int ch=0;
	struct node num;
	printf("Enter number of Elements:");
	scanf("%d",&n);
	printf("Menu\n1.Insert 2.Delete 3.Display 4.Exit\n");
	while(ch!=4){
	printf("Enter choice:");
	scanf("%d",&ch);
	if(ch==1){
		printf("Enter element:");
		scanf("%d",&num.data);
		printf("Enter priority:");
		scanf("%d",&num.p);
		if(num.p==0)
			continue;
		insert(num,pos);
		pos++;
	}
	else if(ch==2)
		Delete(pos);
	else if(ch==3)
	   display();    
}
}
