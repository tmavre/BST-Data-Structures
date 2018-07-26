#include <stdio.h>
#include <stdlib.h>

//Data Structures 
//With this program you can insert , delete , find minimoum element, find maximoum element in Binary Search tree 
//traverse in Binary Search tree  with pre-order , in-order, post-order.

//You must pass the value by hand inside in main() every time when you make a call of any function in this file

typedef struct NodePtr{

	int value;
	struct NodePtr *left;
	struct NodePtr *right;
	}Node;
	
	Node *createNode(int value)
	{
		Node *node;
		node = (Node*)malloc(sizeof(Node));
		node->value=value;
		node->left = node->right = NULL;
		return node;
	}

	Node *insert(Node *root,int value)
	{
		if(root == NULL)
		{
			root = createNode(value); 
			
		}
		else if(value<root->value)
		{
			root->left=insert(root->left,value);

		}
		else if(value>root->value)
		{
			root->right=insert(root->right,value);
		}

		return root;
	}
	
	Node *FindMin(Node *root)
	{
		
		if(root==NULL)
		{
			return root;
		}
		while(root->left!=NULL)
		{
			root = root->left;
		}
		return root->value;

	}

	Node *FindMax(Node *root)
	{
		if(root==NULL){
			return root;
		}
		while(root->right!=NULL)
		{
			root=root->right;
		}
		return root->value;

	}

	Node *DeleteNode(Node *root,int data)
	{
		if(root==NULL)
		{
			return root;
		}
		else if(data < root->value)
		{
			root->left = DeleteNode(root->left,data);
		}
		else if (data > root->value)
		{
			root->right = DeleteNode(root->right,data);
		}
		else
		{
			//No child
			if(root->right==NULL && root->left==NULL)
			{
				root = NULL;
				free(root);
			}
			//One Child
			else if(root->right==NULL)
			{
				Node *tmp;
				tmp = root;
				root = root ->left;
				free(tmp);
			}
			else if(root->left==NULL)
			{
				Node *tmp;
				tmp = root;
				root = root->right;
				free(tmp);
			}
			//Two Childern
			else 
			{
				Node *tmp;
				tmp= FindMin(root->right);
				root->value = tmp->value;
				root->right = DeleteNode(root->right,tmp->value);
			}

		}

	return root;



	}

	void *preorder(Node *p)
	{
		if(p!=NULL)
		{
			printf("%d,",p->value);
			preorder(p->left);
			preorder(p->right);


		}
	}

	void *inorder(Node *p)
	{
		if(p!=NULL)
		{
			inorder(p->left);
			printf("%d,",p->value);
			inorder(p->right);


		}
	}

	void *postorder(Node *p)
	{
		if(p!=NULL)
		{
			postorder(p->left);
			postorder(p->right);
			printf("%d,",p->value);

		}
	}

	Node *search(Node *root,int value)
	{
		if (root==NULL||root->value==value)
		{
			
			return root;
		}
		if (value > root->value)
		{
			return search(root->right,value);
		}
		return search(root->left,value);
	}


	void print(Node *root)
	{
		if(root)
		{
			printf("%d,",root->value);
			print(root->left);
			print(root->right);
		}				
	}

	
	int main()
	{
		
		Node *max,*min;
		Node *root = NULL;
		int flag=0;
		int ar=0;
		//
		root =insert(root,30);
		root =insert(root,25);
		root =insert(root,27);
		root =insert(root,40);
		root =insert(root,66);
		root =insert(root,5);
		root =insert(root,3);
		min = FindMin(root);
		max = FindMax(root);
		
		flag = search(root,50);
		//root=DeleteNode(root,40);
		
		printf("The Tree\n");
		print(root);
		printf("\n\n\n");
		printf("Minimum element in Tree\n");
		printf("%d\n",min);
		printf("Maximum element in Tree\n");
		printf("%d\n",max);
		printf("\n");
		printf("THE preorder\n");
		preorder(root);
		printf("\n");
		printf("THE Iorder\n");
		inorder(root);
		printf("\n");
		printf("THE postorder\n");
		postorder(root);
		printf("\n");
		printf("\n\n");
		printf("Results from search: ");
		
		if(flag)
		{
			printf("The element found\n");
		}
		else
		{
			printf("Not found\n");
		}
		
		return 0;
	}