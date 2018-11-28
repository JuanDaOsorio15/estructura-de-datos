//N = NUMERO ESTUDIANTES DE LA RIFA
//k = cant movimientos
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
//----------------------------------------------------------------------------------------------
struct node *addstudents (struct node *tail, int cant_students)
{
       for(int index=1;index <= cant_students; index++)
               tail = InsertInCircularBoundlyLinkedList ( tail, index);
       return tail;
}
//----------------------------------------------------------------------------------------------
struct node *moveleft(struct node *tail, int quantity_movements)
{
	struct node *reference;
	for(int index=1;index < quantity_movements; index++)
		tail = tail->next;
	tail->next->prev = tail->prev;
	tail->prev->next = tail->next;
	reference = tail;
	tail=tail->next;
	free(reference);

	return tail;
}
//----------------------------------------------------------------------------------------------
struct node *moveright(struct node *tail, int quantity_movements)
{
	struct node *reference;
	for(int index=1;index < quantity_movements; index++)
		tail= tail->prev;
	tail->next->prev = tail->prev;
	tail->prev->next = tail->next;
	reference = tail;
	tail=tail->prev;
	free(reference);

	return tail;
}
//---------------------------------------------------------------------------------------------
int main()
{
    struct node *tail,*reference;
    int students, k,result,movements;
    tail= NULL;


    while(scanf("%d %d",&students,&k) && ((students!= 0) && (k != 0)))
    {
    	int LoR=0,newstudents=students;
		tail= addstudents(tail,students);
    	tail= tail->next;

    	if(k==1)
    		result= ceil(newstudents/2)+1;

    	while(tail != tail->next)
    	{
    		if(k % newstudents == 0)
    		{
    			if(LoR % 2 == 0)
				{
					tail=tail->prev;
					tail->prev->next=tail->next;
					tail->next->prev=tail->prev;
					reference=tail;
					tail=tail->next;
					free(reference);
				}
				else
				{
					tail=tail->next;
					tail->next->prev=tail->prev;
					tail->prev->next=tail->next;
					reference = tail;
					tail=tail->prev;
					free(reference);
				}
				newstudents--;
				LoR++;
			}
			else
    		{
    			movements = k % newstudents;
				if(LoR % 2 == 0)
					tail=moveleft(tail,movements);
				else
					tail=moveright(tail,movements);
				newstudents--;
				LoR++;
			}
		}
		result=tail->key;
		printf("%d\n",result);
		free(tail);
		tail=NULL;
    }
    return 0;
}

/*
if(students == k)
    			{
    				if(LoR % 2 == 0)
						tail=moveleft(tail,(k-newstudents));
					else
						tail=moveright(tail,(k-newstudents));
					newstudents--;
					LoR++;
				}
				else
				{
			*/
