#include<stdio.h>
#include<stdlib.h>
typedef struct nd{
	int data;
	struct nd *left,*right;
}node;
node *root=NULL;
node *createNode(int data){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}}
void preorder(node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}}	
void postorder(node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}}	
node *insert(node *root,int data){
	if(root==NULL)
	    return createNode(data);
	if(data<root->data)
	   root->left=insert(root->left,data);  
	else if(data>root->data)
	   root->right=insert(root->right,data);    
     return root;
}
node *Delete(node *root,int data){
	if(root==NULL){
	 printf("Element not Found");
	 return NULL;
	}
	if(data < root->data)
		root->left=Delete(root->left,data);  
	else if(data > root->data)
		root->right=Delete(root->right,data);
	else{
		if(root->left==NULL)
		    return root->right;
		else if(root->right==NULL)
		    return root->left; 
		else{
			root->data=SmallestElement(root->right);
			root->right=Delete(root->right,root->data);
		}}return root;
	}
int SmallestElement(node *root){
	if(root->left==NULL || root==NULL)
	   return root->data;
	else
	   return SmallestElement(root->left);   
}	
int LargestElement(node *root){
	if(root->right==NULL || root==NULL)
		return root->data;
	else
	   return LargestElement(root->right);  
}
int search(node *root,int data){
	if(root==NULL)
	   return 0;
	if(root->data==data)
	   return 1;
	else if(data < root->data)
	   search(root->left,data);  
	else
	   search(root->right,data);   
    }
int main(){
	int ch,data;
	printf("Choice\n1.insert\n2.delete\n3.preorderTraversal\n4.inorderTraversal\n5.postorderTraversal\
	\n6.Find Smallest\n7.Find Largest\n8.Search\n9.Exit");
	do{printf("\nEnter the Choice:");
	scanf("%d",&ch);
	if(ch==1){
	printf("Enter the Element to insert:");
	scanf("%d",&data);
	root=insert(root,data);	
	}else if(ch==2){
		printf("Enter the Element to delete:");
	scanf("%d",&data);
		root=Delete(root,data);
	}else if(ch==3 && root!=NULL)
      preorder(root);
	else if(ch==4 && root!=NULL)
      inorder(root);
	else if(ch==5 && root!=NULL)
      postorder(root);
	else if(ch==6 && root!=NULL)
     printf("Smallest Element is: %d",SmallestElement(root));
     else if(ch==7 && root!=NULL)
     printf("Largest Element is: %d",LargestElement(root));
     else if(ch==8){
     	printf("Enter the Search element:");
     	scanf("%d",&data);
     	int found=search(root,data);
     	printf(found==1?"Element Found":"Element not found");
	 }}while(ch!=9);	
}

