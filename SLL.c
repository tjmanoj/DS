#include<stdio.h>
#include <stdlib.h>
int main(){
	int ch,item,t=0;
	struct node{
		int data;
		struct node *next;
	};
	struct node *head,*newnode,*temp,*ptr,*ptr1;
	head=NULL;
	printf("MENU\n1.Insert 2.Display 3.Delete 4.Search 5.Exit\n");
	while(ch!=5){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1){
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head==NULL){
			 	head=temp=newnode;}
			else{
				temp->next=newnode;
				temp=newnode;
			}
		}
		else if(ch==2){
		    if(head==NULL)
		        printf("List empty!\n");
		    else{
			ptr=head;
			while(ptr!=NULL){
				printf("%d\n",ptr->data);
				ptr=ptr->next;}
		}}
		else if(ch==3){
		 if(head==NULL)
		  printf("List empty!\n");
		 else{
		 	printf("Removed element is %d\n",head->data);
		 	head=head->next;
		 }}
		else if(ch==4){
			printf("Enter search element:");
			scanf("%d",&item);
		 	ptr1=head;
			while(ptr1!=NULL){
				if(ptr1->data == item){
					printf("Element found\n");
					t=1;}
			    ptr1=ptr1->next;
			}
			if(t==0)
				 printf("Element not found\n");
		}
		else if(ch==5)
		 printf("Exit");
		else
		    printf("Invalid choice!\n");
	}}
