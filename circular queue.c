#include<stdio.h>
int main(){
	int n,front=-1,i,rear=-1,ch,e;
	printf("Enter circular queue size:");
	scanf("%d",&n);
	int cir_queue[n];
	printf("MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	while(ch!=4){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1)
		 if( (rear+1)%n ==front)
		  printf("Circular queue is full\n");
		 else if(front ==-1 && rear==-1){
		 	printf("Enter element:");
		 	scanf("%d",&e);
		 	front=rear=0;
		 	cir_queue[rear]=e;
		 }
		 else{
		 	printf("Enter element:");
		 	scanf("%d",&e);
		 	rear=(rear+1)%n;
		 	cir_queue[rear]=e;
		 }
		else if(ch==2)
		 if(front==-1 && rear==-1)
		  printf("Circular Queue Underflow\n");
	     else if(front==rear){
		  printf("Removed element:%d\n",cir_queue[front]);
		  front=rear=-1;}
		 else{
		 	printf("Removed element:%d\n",cir_queue[front]);
		 	front=(front+1)%n;
		 }
		else if(ch==3)
		 if(front==-1 && rear==-1)
		  printf("Circular Queue Underflow\n");
	     else{
	     	i=front;
	     	while(i!=rear){
	     	 printf("%d\n",cir_queue[i]);
	     	 i=(i+1)%n;}
	     	printf("%d\n",cir_queue[rear]);}
		else if(ch==4)
		 printf("Exit");
	    else
	     printf("Invalid choice!\n");
}}
