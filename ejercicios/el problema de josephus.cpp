//EL PROBLEMA DE JOSEPHUS
//se tiene un conjunto de n soldados en un circulo numerados del (1 al n), el problema consiste en
//contar a partir de un soldado dado k soldados y cuando se hayan contado k soldados, el soldado 
//debe retirarse y contar de nuevo, apartir del siguiente soldado, repitiendo el proceso hasta que 
//quede 1.

//scan cant soldiers
//scan cont switch
 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
//-----------------------------------------------------------------------------------------------------------
struct node *newtail(struct node *tail, int element)
{
	struct node *front,*back;
	if(tail != tail->next)
	{
		back=NULL;
		front=tail->next;
		while((back!=tail) && (front->key != element))
		{
			back = front;
			front = front->next;
		}
		tail=front->prev;
	}
	return tail;
}
//-----------------------------------------------------------------------------------------------------------
int main()
{
	struct node *tail,*back,*front;
	int cant_soldiers,first_sold, k,index;
	tail = NULL;
	
	while(scanf("%d",&cant_soldiers) != EOF)
	{
		scanf("%d",&k);
		for(index=1; index <= cant_soldiers;index++)
		{
			int element = index;
			tail = InsertInCircularBoundlyLinkedList ( tail, index);			
		}
		scanf("%d",&first_sold);
		if(first_sold > cant_soldiers)
			scanf("%d",&first_sold);
		tail = newtail(tail,first_sold);
		while(tail->next != tail)
		{
			index=1;
			back=NULL;
			front=tail->next;
	
			while(index < k)
			{
				back=front;
				front=front->next;
				index++;
			}
			tail=front;
			tail=DeleteInDoubleLinkedList (tail,tail->key);	
		}
		printf("%d\n", tail->key);
		tail = NULL;
	}
	return 0;
}


