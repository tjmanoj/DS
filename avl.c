#include<stdio.h>
#include<stdlib.h>
typedef struct nd{
	int data;
	struct nd *left,*right;
	int ht;
}node;
node *root=NULL;
node *createNode(int data){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	newnode->ht=0;
	return newnode;
}
int max(int a,int b){
	return a>b?a:b;
}
int height(node *root){
	if(root==NULL)
	  return -1;
	return root->ht;  
}
int changeHeight(node *root){
	return 1+max(height(root->left),height(root->right));
}
int BalanceFactor(node *root){
	if(root==NULL)
	  return 0;
	return   height(root->left)-height(root->right);
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d  Balance_Factor %d\n",root->data,BalanceFactor(root));
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
node *rightRotate(node *z){
	node *y=z->left;
	node *ychild=y->right;
	y->right=z;
	z->left=ychild;
	z->ht=changeHeight(z);
	y->ht=changeHeight(y);
	return y;
}
node *leftRotate(node *z){           
	node *y=z->right;              
	node *ychild=y->left;       
	y->left=z;               
	z->right=ychild;         
	z->ht=changeHeight(z);
	y->ht=changeHeight(y);
	return y;
}	
int SmallestElement(node *root){
	if(root->left==NULL || root==NULL)
	   return root->data;
	else
	   return SmallestElement(root->left);   
}
node *insert(node *root,int data){
	if(root==NULL)
	    return createNode(data);
	if(data<root->data)
	   root->left=insert(root->left,data);  
	else if(data>root->data)
	   root->right=insert(root->right,data); 
	else 
	   return root;
	root->ht=changeHeight(root);//1+max(height(root->left),height(root->right));    
	int bf=BalanceFactor(root);
	//LL
	if(bf>1 && root->left->data > data)
		return rightRotate(root);
	//lR
	if(bf>1 && root->left->data < data){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}//RR
	 if(bf<-1 && root->right->data < data)
		return leftRotate(root); 
	//RL
	if(bf<-1 && root->right->data > data){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}return root;
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
		}}
		if(root==NULL)
		   return root;
		root->ht=changeHeight(root);
	int bf=BalanceFactor(root);
	//LL
	if(bf>1 && BalanceFactor(root->left) >= 0)
		return rightRotate(root);
	//lR
	if(bf>1 && BalanceFactor(root->left) < 0){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}//RR
	 if(bf<-1 && BalanceFactor(root->right) <= 0)
		return leftRotate(root); 
	//RL
	if(bf<-1 && BalanceFactor(root->right) > 0){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}return root;
	}
int main(){
	int ch,data;
	printf("Choice\n1.insert\n2.delete\n3.preorderTraversal\n4.inorderTraversal\n5.postorderTraversal\
	\n6.Find Smallest\n7.Exit");
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
	}else if(ch==3)
     preorder(root);	
	else if(ch==4)
		inorder(root);
	else if(ch==5)
	   postorder(root);
	else if(ch==6)
	   printf("%d",SmallestElement(root));         
	}while(ch!=7);
}
