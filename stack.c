#include<stdio.h>
int main(){
	int i,n,top=-1,ch,push,pop;
	printf("Enter stack size:");
	scanf("%d",&n);
	int stack[n];
	printf("MENU\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
	while(ch!=5){
		printf("Enter choice:");
		scanf("%d",&ch);
		if(ch==1)
		    if(top==n-1)
			 printf("Stack overflow\n");
		    else{
			 printf("Enter element:");
			 scanf("%d",&push);
			 stack[++top]=push;
		}
		else if(ch==2)
		 if(top<1)
		  printf("Stack underflow\n");
		 else{
		 	pop=stack[top];
		 	top--;
		 	printf("Popped element is %d\n",pop);
		 }
		else if(ch==3)
		 if(top==-1)
		  printf("Stack is empty");
		 else
		 	printf("Top element is %d\n",stack[top]);
		else if(ch==4){
			printf("Stack elements:\n");
		    for(i=top;i>=0;i--)
		  		printf("%d\n",stack[i]);
		  }
		else if(ch==5)
		 printf("End");
		else
		 printf("Invalid choice");
}}

