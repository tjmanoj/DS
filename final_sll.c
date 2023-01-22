#include<stdio.h>
#include<stdlib.h>

int main(){
int ch=0,num;
typedef struct{
    int data;
    struct node* next;
}node;
node *head=0,*tail=0,*temp,*newnode,*tp;
while(ch!=9){
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
            newnode->next=head;
            head=newnode;
        }
    }
    else if(ch==2){
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==0)
            head=tail=newnode;
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    else if(ch==3){
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==0)
            head=tail=newnode;
        else{
            printf("Enter data after:");
            scanf("%d",&num);
            for(temp=head;temp!=NULL;temp=temp->next){
                if(temp->data == num){
                    newnode->next=temp->next;
                    temp->next=newnode;
                    break;
                }
                else{
                    printf("middle not found");
                    break;}
            }
        }
    }
    else if(ch==4){
        if(head==NULL)
            printf("Empty");
        else if(head == tail)
            head=tail=NULL;
        else{
            temp=head;
            head=head->next;
            free(temp);
        }
    }
    else if(ch==5){
        if(head==NULL)
            printf("Empty");
        else if(head == tail)
            head=tail=NULL;
        else{
            for(temp=head;temp->next!=NULL;temp=temp->next)
                tp=temp;
            tp->next=NULL;
            tail=tp;
        }
    }
    else if(ch==6){
        if(head==NULL)
            printf("Empty");
        else if(head == tail)
            head=tail=NULL;
        else{
            printf("Enter data after:");
            scanf("%d",&num);
            for(temp=head;temp!=NULL && temp->data!=num;temp=temp->next)
                tp=temp;
            if(temp==NULL)
                printf("Element not found");
            else{
            tp->next=temp->next;
            free(temp);}
        }
    }   
    else if(ch==7){
        printf("Enter Search Element:");
        scanf("%d",&num);
        for(temp=head;temp!=NULL && temp->data!=num;temp=temp->next);
        if(temp==NULL)
            printf("Element not found\n");
        else
            printf("Element found\n");
    }
    else if(ch==8){
        if(head==NULL)
            printf("Empty\n");
        else{
        temp=head;
        for(temp=head;temp!=NULL;temp=temp->next)
            printf("%d\n",temp->data);
    }}
}}
