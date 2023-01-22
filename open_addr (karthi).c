#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
int tsize,count;
int hasht(int key) 
{ int i ;
 i = key%tsize ; 
return i; }
 //-------LINEAR PROBING------- 
int rehashl(int key)
 { int i ; 
i = (key+1)%tsize ;
 return i ; }
 //-------QUADRATIC PROBING------- 
int rehashq(int key, int j)
 { int i ; 
i = (key+(j*j))%tsize ; 
return i ; } 
int Search(int ele,int arr[],int n){
int i,t=0;
for(i=0;i<n;i++)
printf("%d\t",arr[i]);
if(ele==arr[i])
return 1;
else
return 0;
}
void main()
 { int an,key,arr[20],hash[20],i,n,s,op=0,j,k,d;
 
 printf ("Enter the size of the hash table: ");
 scanf ("%d",&tsize);
 printf ("\nEnter the number of elements: ");
 scanf ("%d",&n);
 for (i=0;i<tsize;i++)
 hash[i]=-1 ; 
printf ("Enter Elements: ");
 for (i=0;i<n;i++) 
{ scanf("%d",&arr[i]); }
 for(i=0;i<n;i++)
printf("%d\t",arr[i]);
printf("\n\n1.Linear Probing\n2.Quadratic Probing \n3.search\n4.Delete");
while(op!=4){ 
printf("Enter choice:") ;
scanf("%d",&op);
 switch(op) 
{ case 1: 
for (i=0;i<tsize;i++)
 hash[i]=-1 ;
 for(k=0;k<n;k++) 
{ key=arr[k] ;
 i = hasht(key);
 while (hash[i]!=-1) 
{ i = rehashl(i); }
 hash[i]=key ; }
 printf("\nThe elements in the array are: "); 
for (i=0;i<tsize;i++) 
{ printf("\n Element at position %d: %d",i,hash[i]); 
} break ; 
case 2: 
for (i=0;i<tsize;i++) 
hash[i]=-1 ;
; 
for(k=0;k<n;k++)
 { j=1; key=arr[k] ; 
i = hasht(key); 
while (hash[i]!=-1)
 { i = rehashq(i,j); j++ ; } 
hash[i]=key ; } 
printf("\nThe elements in the array are: ");
 for (i=0;i<tsize;i++)
 { printf("\n Element at position %d: %d",i,hash[i]); } 
break ;  
case 3:
	printf("enter the sezarch element");
scanf("%d",&an);
int i,t=0;
for(i=0;i<n;i++){
if(arr[i]==an){
printf("found");t=1;}}
if(t==0)
printf("not found");
break;
case 4:
	printf("enter the element to delete");
	scanf("%d",&d);
	for(i=0;i<tsize;i++)
	{
		if(hash[i]==d)
		hash[i]=-1;
	}
	 for (i=0;i<tsize;i++)
 { printf("\n Element at position %d: %d",i,hash[i]); } 
break ; 

default:
	printf("wrong choice");
	break;
 } }}
