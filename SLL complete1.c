//SLL
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
int main(){
	int ch=0;
	struct node *head=0,*tail=0,*newnode,*temp,*ptr1,*ptr2,*tp;
	printf("Menu\n1.Begin 2.End 3.Middle 4.Del Begin 5.Del End 6.Del Middle 7.Search 8.Display 9.Small 10.NON 11.REV");
	while(ch!=12){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1){
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head == 0)
				head=tail=newnode;
			else{
				newnode->next=head;
				head=newnode;
			}
		}
		else if(ch==2){
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head == 0)
				head=tail=newnode;
			else{
				tail->next=newnode;
				tail=newnode;
			}
		}
		else if(ch==3){int e;
			newnode=(struct node*)malloc(sizeof(struct node));
			printf("Enter data:");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head == 0)
				head=tail=newnode;
			else{
				printf("Enter element after insert:");
				scanf("%d",&e);
				for(temp=head;temp->next!=NULL;temp=temp->next){
					if(temp->data==e){
						newnode->next=temp->next;
						temp->next=newnode;
						break;
					}
				}
			}
		}
		else if(ch==4){
			if(head==0)
				printf("SLL empty");
			else if(head==tail)
				head=tail=NULL;
			else{
				temp=head;
				head=head->next;
				free(temp);
			}
		}
		else if(ch==5){
			if(head==0)
				printf("SLL empty");
			else if(head==tail)
				head=tail=NULL;
			else{
				for(temp=head;temp->next!=NULL;temp=temp->next)
					tp=temp;
				tp->next=NULL;
				free(temp);
			}
		}
		else if(ch==6){int e;
			if(head==0)
				printf("SLL empty");
			else if(head==tail)
				head=tail=NULL;
			else{
				printf("Enter element after delete:");
				scanf("%d",&e);
				for(temp=head;temp->data!=e;temp=temp->next)
					tp=temp;
				tp->next=temp->next;
				free(temp);
		}}
		else if(ch==7){int s,t=0;
			printf("Enter search term:");
			scanf("%d",&s);
			temp=head;
			while(temp!=NULL){
				if(temp->data==s){
					printf("Elemet found");
					t=1;
					break;
				}
				temp=temp->next;
			}
			if(t==0)
				printf("Element not found");
		}
		else if(ch==8){
			if(head==0)
				printf("SLL empty");
			else{
				ptr1=head;
				while(ptr1!=NULL){
					printf("%d\n",ptr1->data);
					ptr1=ptr1->next;
				}
			}
		}
		
		else if(ch==9){
			int sm=head->data;
			for(temp=head;temp->next!=NULL;temp=temp->next){
				if(sm>temp->data)
					sm=temp->data;
			}
			printf("%d",sm);
		}
		else if(ch==10){
			int n;
			printf("Enter element:");
			scanf("%d",&n);
			for(temp=head;temp!=NULL && temp->data!=n;temp=temp->next);
			if(temp!=NULL)
				printf("Element already found");
			else if(temp==NULL){
				newnode=(struct node*)malloc(sizeof(struct node));
				newnode->data=n;
				newnode->next=NULL;
				tail->next=newnode;
				tail=newnode;
			}
		}
		else if(ch==11){
			int i=0,j,arr[50];
			if(head==0)
				printf("SLL empty");
			else{
				ptr1=head;
				while(ptr1!=NULL){
					arr[i]=ptr1->data;
					ptr1=ptr1->next;
					i++;
				}
				for(j=i-1;j>=0;j--)
					printf("%d\n",arr[j]);
				
			}
		}
	}
}
