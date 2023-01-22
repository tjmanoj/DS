#include<stdio.h>
#include<stdlib.h>
int main(){
	int ch;
	struct node{
		int data;
		struct node *next;
	};
	struct node *top=0,*newnode,*temp;			//top is the head here
	printf("MENU\n1.Push\n2.Peek\n3.Pop\n4.Display\n5.Exit\n");
	while(ch!=5){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1){
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter element:");
			scanf("%d",&newnode->data);
			newnode->next=top;
			top=newnode;			
		}
		else if(ch==2)
			if(top==0)
			 printf("Stack Underflow\n");
			else{
				printf("Top element is %d\n",top->data);
			}
		else if(ch==3)
			if(top==0)
			 printf("Stack Underflow\n");
			else{
				temp=top;
				printf("Top element is %d\n",top->data);
				top=temp->next;
				free(temp);
			}
		else if(ch==4)
			if(top==0)
			 printf("Stack Underflow\n");
			else{
				temp=top;
				while(temp!=0){
				printf("%d\n",temp->data);
				temp=temp->next;
			}}
		else if(ch==5)
		 printf("Exit");
		else
		 printf("Invalid choice!\n");
}}
