#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i,top=-1,stack[100];
char a[100],infix[100],postfix[100];
void push();
int pop();
void evalpostfix();
void infixtopost();
int isEmpty();
int main(){
	int ch;
	printf("Menu\n1.Evaluate Postfix 2.Infix to Postfix 3.Exit\n");
	while(ch!=3){
 	printf("Enter choice:");
 	scanf("%d",&ch);
 	if(ch==1)
		evalpostfix();
	else if(ch==2)
		infixtopost();
	}
	}
void evalpostfix(){
	printf("Enter an expression:");
	scanf("%s",a);
	for(i=0;a[i];i++){
		if(isdigit(a[i]))
			push(a[i]-'0');
		else{
			int p1=pop();
			int p2=pop();
			switch(a[i]){
				case '+':push(p2+p1);break;
				case '-':push(p2-p1);break;
				case '*':push(p2*p1);break;
				case '/':push(p2/p1);break;
			}
		}
	}
	printf("%d\n",pop());
}
void push(int n){
	stack[++top]=n;
}
int pop(){
	return stack[top--];
}
int precedence(char symbol){
	switch(symbol){
		case '^':return 3;
		case '/':
		case '*':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
void infixtopost(){
	printf("Enter an infix expression:");
	scanf("%s",infix);
	int j=0;
	char temp,symbol;
	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
		switch(symbol){
			case '(':
				push(symbol);
				break;
			case ')':
				while((temp=pop())!='(')
					postfix[j++]=temp;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
					postfix[j++]=pop();
				push(symbol);break;
			default:
				postfix[j++]= symbol;
		}
	}
	while(!isEmpty())
		postfix[j++]=pop();
	postfix[j]='\0';
	puts(postfix);
}
int isEmpty(){
	if(top==-1)
		return 1;
	else
		return 0;}

