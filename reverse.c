#include<stdio.h>
#include<string.h>
int main(){int i;
	char s[10];
	printf("Enter a string:");
	scanf("%s",s);
	for(i=strlen(s);i>=0;i--){
		printf("%c",s[i]);
}}
