#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//LISTAS CIRCULARES DOBLEMENTE ENLAZADAS

struct node {
	int key;
	struct node *next;
	struct node *prev;
};
//----------------------------------------------------------------------------------------------------
struct node *InsertInCircularBoundlyLinkedList (struct node *tail, int element)
{
	struct node *newnode;
	newnode = (struct node *) malloc (sizeof(struct node));
	newnode->key = element;
	
	if (tail == NULL)
	{
		newnode->next=newnode;
		newnode->prev=newnode;
		tail=newnode;
	}
	else
	{
		newnode->next = tail->next;
		tail->next->prev = newnode;
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode; 
	}
	return tail;
}
//------------------------------------------------------------------------------------------------
struct node *DeleteInDoubleLinkedList (struct node *tail, int element)
{
	struct node *previo, *actual;
	if(tail == NULL)
		printf("imposible delete. empty list.\n");
	else
	{
		if(tail == tail->next)
		{
			if(element == tail->key)
			{
				free(tail);
				tail = NULL;
			}
			else
				printf("element %d is not in list.\n", element);
		}
		else
		{
			previo = NULL;
			actual = tail->next;
			while(( previo != tail) && (actual->key != element))
			{
				previo = actual;
				actual = actual->next;
			}
			if(previo==tail)
				printf("element %d is not in list.\n", element);
			else
			{
				if(previo == NULL)
					previo=tail;
				if(actual == tail)
					tail=tail->prev;
				previo->next = actual->next;
				actual->next->prev = previo;
				free(actual);
			}
		}
	}
	return tail;
}
//--------------------------------------------------------------------------------------------------------
void PrintFromRightToLeftList (struct node *tail)
{
	struct node *front, *back;
	if(tail == NULL)
		printf("empty list.\n");
	else
	{
		back = NULL;
		front = tail;
		while(back != tail->next)
		{
			printf("<-- %d ",front->key);
			back = front;
			front = front->prev;
		}
		printf("...\n");
	}
}

void PrintFromLeftToRight(struct node *tail)
{
	struct node *front,*back;
	if(tail == NULL)
		printf("empty list.\n");
	else
	{
		back = NULL;
		front = tail->next;
		while(back != tail)
		{
			printf("%d -->",front->key);
			back = front;
			front = front->next;
		}
		printf("...\n");
	}
}
//------------------------------------------------------------------------------------------------------------
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
			tail = InsertInCircularBoundlyLinkedList(tail, element);
			PrintFromRightToLeftList(tail);
			PrintFromLeftToRight(tail);
		}
		if(operation == 2)
		{
			scanf("%d",&element);
			tail =  DeleteInDoubleLinkedList(tail,element);
			PrintFromRightToLeftList(tail);
			PrintFromLeftToRight(tail);
		}
	}
	return 0;
}
