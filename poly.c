#include<stdio.h>
#include<stdlib.h>
struct node{
		float co;
		int ex;
		struct node *next;
	};
struct node* insert(struct node* head,int c,int e){
		struct node* temp,*newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->co=c;
		newnode->ex=e;
		newnode->next=NULL;
		if(head==NULL || e > head->ex){
			newnode->next=head;
			head=newnode;}
		else{
			temp=head;
			while(temp->next != NULL && temp->next->ex >e)
				temp=temp->next;
			newnode->next=temp->next;
			temp->next=newnode;
		}return head;
}
void disp(struct node* head){
		struct node* temp1=head;
		while(temp1!=NULL){
			printf("(%.1fx^%d)",temp1->co,temp1->ex);
			temp1=temp1->next;
			if(temp1!=NULL)
				printf(" + ");
			else
				printf("\n");}}
void add(struct node* head1,struct node* head2){
	struct node* ptr1=head1;
	struct node* ptr2=head2;
	struct node* head3=NULL;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->ex == ptr2->ex){
			head3=insert(head3,ptr1->co + ptr2->co ,ptr1->ex);
			ptr1=ptr1->next;
			ptr2=ptr2->next;}
		else if(ptr1->ex > ptr2->ex){
			head3=insert(head3,ptr1->co ,ptr1->ex);
			ptr1=ptr1->next;}
		else if(ptr1->ex < ptr2->ex){
			head3=insert(head3,ptr2->co ,ptr2->ex);
			ptr2=ptr2->next;}}
	while(ptr1!=NULL){
		head3=insert(head3,ptr1->co ,ptr1->ex);
		ptr1=ptr1->next;}
	while(ptr2!=NULL){
		head3=insert(head3,ptr2->co ,ptr2->ex);
		ptr2=ptr2->next;}
	disp(head3);
}
int main(){
	int n,i,j,e;
	float c;
	struct node *head1=NULL,*head2=NULL;
	for(i=0;i<2;i++){
		printf("Enter polynomial %d\n",i+1);
		printf("Enter no.of terms:");
		scanf("%d",&n);
		for(j=0;j<n;j++){
			printf("Enter coefficient %d:",i+1);
			scanf("%f",&c);
			printf("Enter exponent %d:",i+1);
			scanf("%d",&e);
			if(i==0)
				head1=insert(head1,c,e);
			else
				head2=insert(head2,c,e);}}
	add(head1,head2);			
}
