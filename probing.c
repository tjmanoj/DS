/*Open Addressing*/
#include<stdio.h>
int H[100],n,op;
int hash(int value){
	return value%n;
}
int insert(int value){
	int i,j=1;
	int key=hash(value);
	if(H[key]==-1)
		H[key]=value;
	else{
		i=(key+1)%n;
		while(i!=key){
			if(H[i]==-1){
				H[i]=value;
				return 0;
			}
		if(op==1)
			i=(i+1)%n;
		else{
			i=(key+(j*j))%n;
			j++;
		}}printf("Hash table FULL");
	}}
int Delete(int value){
	int i,j=1;
	int key=hash(value);
	if(H[key]==value)
		H[key]=-1;
	else{
		i=(key+1)%n;
		while(i!=key){
			if(H[i]==value){
				H[i]=-1;
				return 0;
			}
		if(op==1)
			i=(i+1)%n;
		else
			i=(key+(j*j))%n,j++;
		}printf("Element not Found");
	}}
int search(int value){
	int i,j=1;
	int key=hash(value);
	if(H[key]==value)
		printf("Element found at:%d",key);
	else{
		i=(key+1)%n;
		while(i!=key){
			if(H[i]==value){
				printf("Element found at:%d",i);
				return 0;
			}
		if(op==1)
			i=(i+1)%n;
		else
			i=(key+(j*j))%n,j++;
		}printf("Element not Found");
		}}
void display(){
	for(int i=0;i<n;i++)
		printf("%d  ",H[i]);
}
int get(){
	int value;
	printf("Enter the element:");
	scanf("%d",&value);
	return value;
}
int main(){
	int value,key,ch=0,i;
	printf("open Addressing\n1.Linear 2.Quadratic\n");
	scanf("%d",&op);
	printf("Enter the number of element");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  H[i]=-1;
	printf("Choice\n1.Insert 2.Delete 3.Search 4.Display 5.Exit");
	while(ch!=5){
		printf("\nEnter Choice:");
		scanf("%d",&ch);
		if(ch==1){
			value=get();
			insert(value);
		}else if(ch==2){
			value=get();
			Delete(value);
		}else if(ch==3){
			value=get();
			search(value);
		}else if(ch==4)
			display();
	}
}
