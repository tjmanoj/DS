#include<stdio.h>
#include<stdlib.h>
int main(){
	int ch;
	struct node{
		int data;
		struct node *next;
	};
	struct node *front=0,*rear=0,*temp,*newnode;
	printf("MENU\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
	while(ch!=0){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1){
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter element");
			scanf("%d",newnode->data);
			if(front==0 && rear==0){
				front=rear=newnode;
				rear->next=0;}
			else{
				rear->next=newnode;
				rear=newnode;}}
		else if(ch==2){
			if(front==0 && rear==0)
				printf("Queue Underflow\n");
			else{
				printf("Removed element is %d",front->data);
				temp=front;
				front=temp->next;
				free(temp);}}
		else if(ch==3){
			if(front==0 && rear==0)
				printf("Queue Underflow\n");
			else{
				temp=front;
				while(temp!=NULL){
					printf("%d",temp->data);
					temp=temp->next;
				}
			}}
		}
		}
