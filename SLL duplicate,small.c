#include<stdio.h>
#include<stdlib.h>

int main(){
int ch=0,num,tt=0;
typedef struct{
    int data;
    struct node* next;
}node;
node *head=0,*tail=0,*temp,*newnode,*tp;
printf("MENU\n1.creat 2.display Reverse 3.smallest 4.Non Duplicate insert\n");
while(ch!=5){
    printf("Enter choice:");
    scanf("%d",&ch);
    if(ch==1){
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==0)
            head=tail=newnode;
        else{
            tail->next=newnode;
            tail=newnode;;
        }
    }
    else if(ch==2){
        if(head==NULL)
            printf("Empty");
        else{
            int a[10],i=0,j=0;
            for(temp=head;temp!=NULL;temp=temp->next){
                a[i]=temp->data;
                i++;
            }
            for(j=i-1;j>=0;j--)
                printf("%d\n",a[j]);
        }
    }
    else if(ch==3){
        int small=head->data;
        for(temp=head;temp!=NULL;temp=temp->next){
            if(small>temp->data){
                small=temp->data;
            }
        }
        printf("small no:%d\n",small);
    }
    else if(ch==4){
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        num=newnode->data;
        newnode->next=NULL;
        if(head==0)
            head=tail=newnode;
        else{
            for(temp=head;temp!=NULL && temp->data!=num;temp=temp->next);
            if(temp!=NULL)
                printf("Element found");
            else{
                tail->next=newnode;
                tail=newnode;
            }
        }
    }
}}
