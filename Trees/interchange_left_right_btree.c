#include <stdio.h>
#include <stdlib.h>
 
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
 
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
     return(node);
}

void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data); 
     printInorder(node->right);
}

 
void swapTree(struct node*node)
{
	if(node==NULL) return;
	struct node*temp=node->left;
	node->left=node->right;
	node->right=temp;
	swapTree(node->left);
	swapTree(node->right);
}
int main()
{
     struct node *root  = newNode(1);
     root->left          = newNode(2);
     root->right         = newNode(3);
     root->left->left    = newNode(4);
     root->left->right   = newNode(5);
     printf("Inorder traversal of binary tree is : ");
     printInorder(root); 
     swapTree(root);
     printf("\nAfter swap Inorder traversal of binary tree is : ");
     printInorder(root); 
	 printf("\n");
      return 0;
}
