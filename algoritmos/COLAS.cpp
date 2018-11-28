//COLAS POR MEDIO DE LISTAS CIRCULARES
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define myinfinite -2147483647

struct node {
	int key;
	struct node *next;
};

struct node *ENQUEUE (struct node *tail, int element)
{
	struct node *newnode;
	newnode = (struct node *) malloc (sizeof(struct node));
	newnode -> key = element;
	
	if(tail == NULL)
	{
		newnode->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
	return tail;
}

int DEQUEUE(struct node **tail)
{
	struct node *temp;
	int element = myinfinite;
	if(*tail == NULL)
		printf("the queue is empty.\n");
	else
	{
		if(*tail == (*tail)->next)
		{
			element = (*tail)->key;
			free(*tail);
			*tail=NULL;
		}
		else
		{
			temp = (*tail)->next;
			element = temp->key;
			(*tail)->next = temp->next;
			free(temp);
		}
	}
	return element;
}

int main()
{
	struct node *tail;
	int operation, element;
	tail = NULL;
	while(scanf("%d",&operation) != EOF)
	{
		if(operation == 1)
		{
			scanf("%d",&element);
			tail= ENQUEUE(tail,element);
		}
		else
		{
			if(operation == 2)
			{
				element = DEQUEUE(&tail);
				if( element != myinfinite)
					printf("%d\n",element);
			}
		}
	}
	return 0;
}

