#include <stdio.h>
#include <stdlib.h>
//-----------------------------------binary trees------------------------------------------------------------------------------
struct binary{
	int key;
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
//-----------------------------------------------------------------------------------------------------------------------------
//------------------------------search in tree---------------------------------------------------------------------------------
struct binary *TreeSearch(struct binary *root,int element)
{
	if((root == NULL) || (element == root->key))
		return root; //returns a pointer to the node with the element
	if(element < (root->key))
		return TreeSearch((root->left), element);
	else
		return TreeSearch((root->right), element);
}
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
struct binary *TreeSuccessor(struct binary *root)
{
	struct binary *y;
	if((root->right) != NULL)
		return TreeMinimum (root->right);
	y = root->parent;
	while((y!=NULL)&&(root==(y->right)))
	{
		root = y;
		y = y->parent;
	}
	return y;
}
//-------------------------------------------------------predeccessor----------------------------------------------------------------
struct binary *TreePredeccessor(struct binary *root)
{
	struct binary *y;
	if((root->left) != NULL)
		return TreeMaximum (root->left);
	y = root->parent;
	while((y!=NULL)&&(root==(y->left)))
	{
		root = y;
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
		NTD->key = y->key;
	
	free(y);

	return root;
}
//---------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------other functions----------------------------------------------------------------------------------
struct binary *FillTrees (struct binary *root, int lenght_tree)
{
	int element;
	struct binary *z;
	for(int index =1;index<=lenght_tree;index++)
	{
		scanf("%d", &element);
		z = TreeSearch(root,element);
		if( z == NULL)
		root = TreeInsert(root,element);
	}	
	return root;
}
//--------------------------------------------------------------------------------------------------------------------------------------
void printanswer(struct binary *min, struct binary *max)
{
	if(min == NULL)
	{
		if(max == NULL)
			printf("X X\n");
		else
			printf("X %d\n",max->key);
	}
	else
	{
		if(max == NULL)
			printf("%d X\n",min->key);
		else
			printf("%d %d\n",min->key,max->key);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
int main()
{
   struct binary *TreeLadies, *TreeLuchu,*z,*min,*max,*copy;
   int lady_chimps,queries,height;
   TreeLadies = NULL;
   TreeLuchu = NULL;

   scanf("%d", &lady_chimps);
   TreeLadies = FillTrees(TreeLadies,lady_chimps);

   scanf("%d", &queries);
   for(int index=1;index <= queries;index++)
	{
		scanf("%d",&height);
		z = IterativeTreeSearch(TreeLadies,height);
		if( z != NULL)
		{
			min = TreePredeccessor(z);
			max = TreeSuccessor(z);
			printanswer(min,max);
		}
		else
		{
			TreeLadies = TreeInsert(TreeLadies,(height));
			z = IterativeTreeSearch(TreeLadies,(height));
			min = TreePredeccessor(z);
			max = TreeSuccessor(z);
			printanswer(min,max);
			TreeLadies = TreeDelete (TreeLadies,z);
		}
	}
   return 0;  
}