#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define myinfinite -2147483647
//pilas por medio de listas simplemente enlazadas
struct node {
	int key;
	struct node *next;
};
struct node *PUSH (struct node *top, int element)
{
	struct node *newnode;
	newnode = (struct node *) malloc (sizeof(struct node));
	newnode->key=element;
	newnode->next=top;
	top=newnode;
	return top;
}

int POP (struct node **top)
{
	struct node *temp;
	int element = myinfinite;
	if(*top != NULL)
	{
		temp = *top;
		element = temp->key;
		*top = (*top)->next;
		free(temp);
	}
	else
		printf("the stack is empty.\n");
	return element;
}

void PrintStack(struct node *top)
{
	struct node *reference;
	if(top== NULL)
		printf(" stack is empty.\n");
	else
	{
		reference = top;
		while( reference != NULL)
		{
			printf("%d ->",reference->key);
			reference = reference->next;
		}
		printf("NULL.\n");
	}
	
}

int main()
{
	struct node *top;
	int operation,element;
	top=NULL;
	while(scanf("%d",&operation) != EOF)
	{
		if(operation == 1)
		{
			scanf("%d",&element);
			top = PUSH(top,element);
			PrintStack(top);
		}
		else
		if(operation == 2)
		{
			element = POP(&top);
			if(element != myinfinite)
				printf("%d\n",element);
		}
	}
}
