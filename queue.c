#include<stdio.h>
int main(){
	int n,front=-1,rear=-1,i,ch,e;
	printf("Enter queue size:");
	scanf("%d",&n);
	int queue[n];
	printf("MENU\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit");
	while(ch!=5){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1)
		 if(rear==n-1)
		  printf("Queue Overflow\n");
		 else if(front==-1 && rear==-1){
		 	printf("Enter element:");
		 	scanf("%d",&e);
		 	front=rear=0;
		 	queue[rear]=e;
		 }
		 else{
		  printf("Enter element:");
		  scanf("%d",&e);
		  queue[++rear]=e;
		}
		else if(ch==2)
		 if(front==-1 && rear==-1)
		  printf("Queue Underflow\n");
		 else if(front==rear){
		 	printf("Removed element:%d\n",queue[front]);
		 	front=rear=-1;}
		 else{
		 	printf("Removed element:%d\n",queue[front]);
		 	++front;
		 }
		else if(ch==3)
		 if(front==-1 && rear==-1)
		  printf("Queue Underflow\n");
		  else
		   printf("Peek element:%d\n",queue[front]);
		else if(ch==4)
		 for(i=front;i<rear+1;i++)
		  printf("%d\n",queue[i]);
		else if(ch==5)
		 printf("End");
		else
		 printf("Invalid choice!");
	}
}
