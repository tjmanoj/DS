#include <stdio.h>
#include<stdlib.h>
struct poly{
    int expo;
    int coef;
    struct poly *next;
};
typedef struct poly poly;
poly *list1,*list2,*list3;
poly *create(poly *head1,poly *newnode1){
    poly *ptr;
    if(head1 == NULL)
        head1=newnode1;
    else{
        ptr=head1;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next=newnode1;
    }
    return (head1);
}
void add(poly *list1,poly *list2){
    poly *ptr1,*ptr2,*newnode,*ptr3;
    ptr1=list1;
    ptr2=list2;
    while(ptr1!=NULL && ptr2!=NULL){
        newnode=(struct poly*)malloc(sizeof(struct poly));
        if(ptr1->expo == ptr2->expo){
            newnode->coef=ptr1->coef+ptr2->coef;
            newnode->expo=ptr1->expo;
            newnode->next=NULL;
            list3=create(list3,newnode);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    ptr3=list3;
    while(ptr3!=NULL){
        printf("%d %d",ptr3->expo,ptr3->coef);
        ptr3=ptr3->next;
    }
}
int main() {
    poly *temp,*temp1;
    temp=(struct poly *)malloc(sizeof(struct poly));
    temp->expo=2;
    temp->coef=5;
    temp->next=NULL;
    list1=temp;
    temp1=(struct poly *)malloc(sizeof(struct poly));
    temp1->expo=2;
    temp1->coef=5;
    temp1->next=NULL;
    list2=temp1;
    add(list1,list2);
}
