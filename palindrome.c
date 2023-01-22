#include <stdio.h>
#include<string.h>
int main() {
	int i;
    char s[100];
    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]!=s[strlen(s)-i-1]){
            printf("Not palindrome");
            break;}
        else{
            printf("Plaindrome");
            break;}
    return 0;
}}
