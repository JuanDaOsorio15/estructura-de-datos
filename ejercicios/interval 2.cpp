#include <stdio.h>
#include <stdlib.h>
//-----------------------------------binary trees------------------------------------------------------------------------------
struct binary{
	int key;
    int frecuency;
	struct binary *left;
	struct binary *right;
	struct binary *parent;
};
//-----------------------------------------print the binary tree----------------------------------------------------------------
void InorderTreeWalk (struct binary *root)
{
	if(root != NULL)
	{
		InorderTreeWalk(root->left);
		printf("[%d]-", root->key);
		InorderTreeWalk(root->right);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
//----------------------------------iterative tree search-----------------------------------------------------------------------
struct binary *IterativeTreeSearch(struct binary *root, int element)
{
	while((root != NULL) && (element != (root->key)))
	{
		if(element < (root->key))
			root = root->left;
		else
			root = root->right;
	}
	return root; //returns a pointer to the node with the element
}
//--------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------minimum and maximum------------------------------------------------------
//--------------------------------------------------------minimum-----------------------------------------------------------------
struct binary *TreeMinimum(struct binary *root)
{
	while((root->left) != NULL)
	{
		root = root->left;
	}
	return root;//returns a pointer to the minimun element
}
//--------------------------------------------------------maximum-----------------------------------------------------------------
struct binary *TreeMaximum(struct binary *root)
{
	while((root->right) != NULL)
	{
		root = root->right;
	}
	return root;//returns a pointer to the minimun element
}
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------successor and predeccessor----------------------------------------------------------
//-------------------------------------------------successor----------------------------------------------------------------------
struct binary *TreeSuccessor(struct binary *node)
{
	struct binary *y;
	if((node->right) != NULL)
		return TreeMinimum (node->right);
	y = node->parent;
	while((y!=NULL)&&(node==(y->right)))
	{
		node = y;
		y = y->parent;
	}
	return y;
}
//-------------------------------------------------------predeccessor----------------------------------------------------------------
struct binary *TreePredeccessor(struct binary *node)
{
	struct binary *y;
	if((node->left) != NULL)
		return TreeMaximum (node->left);
	y = node->parent;
	while((y!=NULL)&&(node==(y->left)))
	{
		node = y;
		y = y->parent;
	}
	return y;
}
//-------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------add elements---------------------------------------------------------------------
struct binary *TreeInsert(struct binary *root, int element)
{
	struct binary *temporal,*x,*y;
	temporal = (struct binary *)malloc(sizeof(struct binary));
	temporal->key=element;
	temporal->frecuency=1;
	temporal->left=NULL;
	temporal->right=NULL;
	y=NULL;
	x=root;
	while(x != NULL)
	{
		y = x;
		if((temporal->key) < (x->key))
			x = x->left;
		else
			x = x->right;
	}
	temporal->parent = y;
	if(y == NULL)
		root = temporal;
	else
	{
		if((temporal->key)<(y->key))
			y->left = temporal;
		else
			y->right = temporal;
	}
	return root;
}
//-------------------------------------------------------delete elements---------------------------------------------------------------
struct binary *TreeDelete(struct binary *root,struct binary *NTD)
{
	struct binary *y,*x;
	if((NTD->left==NULL)||(NTD->right==NULL))
		y=NTD;
	else
		y = TreeSuccessor(NTD);
	
	if(y->left != NULL)
		x = y->left;
	else
		x =y->right;
	
	if(x != NULL)
		x->parent = y->parent;
	
	if(y->parent == NULL)
		root == x;
	else
	{
		if(y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}

	if(y != NTD)
    {
        NTD->key = y->key;
        NTD->frecuency = y->frecuency;
        //copy another camps here
    }
	free(y);

	return root;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	int test_cases,lenght_list,element,operation,queries;
	struct binary *tree,*z,*succ,*predecc;
	tree=NULL;

	scanf("%d", &test_cases);
	for(int index=1;index<= test_cases;index++)
	{
		scanf("%d", &lenght_list);
		for(int Index1=1;Index1<=lenght_list;Index1++)
		{
			scanf("%d", &element);
			z = IterativeTreeSearch (tree,element);
			if( z == NULL)
				tree = TreeInsert(tree,element);
			else
				z->frecuency = z->frecuency+1;
		}

		scanf("%d",&queries);
		for(int Index2 = 1; Index2 <= queries; Index2++)
		{
			scanf("%d",&operation);
			scanf("%d",&element);
			z = IterativeTreeSearch (tree,element);
			if( operation == 1)
			{
				if( z == NULL)
				{
					tree = TreeInsert ( tree , element);
					z = IterativeTreeSearch (tree,element);
					predecc = TreePredeccessor(z);
					succ = TreeSuccessor(z);
					if((predecc == NULL) && (succ == NULL))
						printf("-1 100001\n");
					if((predecc == NULL) && (succ != NULL))
						printf("-1 %d\n",(succ->key));
					if((predecc != NULL) && (succ == NULL))
						printf("%d 100001\n", (predecc->key));
					if((predecc != NULL) && ( succ != NULL))
						printf("%d %d\n",(predecc->key),(succ->key));
					tree = TreeDelete(tree,z);
				}
				else
				{
					predecc = TreePredeccessor(z);
					succ = TreeSuccessor(z);
					if((predecc == NULL) && (succ == NULL))
						printf("-1 100001\n");
					if((predecc == NULL) && (succ != NULL))
						printf("-1 %d\n",(succ->key));
					if((predecc != NULL) && (succ == NULL))
						printf("%d 100001\n", (predecc->key));
					if((predecc != NULL) && ( succ != NULL))
						printf("%d %d\n",(predecc->key),(succ->key));
				}
			}
			else if(operation == 2)
			{
				if( z != NULL)
					z->frecuency = z->frecuency+1;
				else
					tree = TreeInsert(tree,element);
			}
			else if (operation == 3)
			{
				if( z != NULL)
				{
					if((z->frecuency) == 1)
						tree = TreeDelete(tree,z);
					else
						z->frecuency = z->frecuency-1;
				}
			}
		}
		tree = NULL;
	}
	return 0;
}