#include <stdlib.h>
#include <stdio.h>
#define myinfinite 2147483647
int heapsize = 0;
//---------------------------------------------------------------------------------------------
struct node
{
    int key;
    struct node *next;
};
//---------------------------------------------------------------------------------------------
//COLAS..
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
	return element;
}
//---------------------------------------------------------------------------------------------------
//PILAS
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
	
	return element;
}

//------------------------------------------------------------------------------------------------------
//COLAS DE PRIORIDAD

int F_parent(int index)
{
	return index/2;
}
int F_left (int index)
{
	return 2*index;
}
int F_right(int index)
{
	return 2*index+1;
}
void MinHeapify(int Array[],int index)
{
	int left, right,least, temp;
	left = F_left(index);
	right = F_right(index);
	if((left <= heapsize) && (Array[left] < Array[index]))
		least = left;
	else
		least = index;
	if((right <= heapsize) && (Array[right]<Array[least]))
		least = right; 
	if(least != index)
	{ 
		temp = Array[index];
		Array[index] = Array[least];
		Array[least] = temp;
		MinHeapify(Array,least); 
	}
}
int MinPQ_minimun(int Array[])
{
	return Array[1];
}

int MinPQ_extract(int Array[])
{
	long long int min = -1*myinfinite;
	long long int max = myinfinite;

	max = Array[heapsize];
	heapsize = heapsize - 1;
	MinHeapify(Array,1);
		
	return max;
}

void MinPQ_DecreaseKey (int Array[],int index,int key)
{
     int temp;
     if( key > Array[index] )
         printf(" Warning "" Key new is higher than current key  ");
     else
         Array[index] = key;
     while ((index > 1) && ((Array[F_parent(index)])> Array[index]))
     {
          temp = Array[index];
          Array[index] = Array[F_parent(index)];
          Array[F_parent(index)] = temp;  
          index = F_parent(index);     
     }
     
}
void MinPQ_insert(int Array[],int key)
{
     heapsize = heapsize+1;
     Array[heapsize]= (myinfinite);
     MinPQ_DecreaseKey(Array,heapsize,key);
}
//---------------------------------------------------------------------------------------------------
int main()
{
	int cant_operations;
	while(scanf("%d",&cant_operations) && (cant_operations != EOF))
	{
		int element, operation,cont_stack =1,cont_queue=1,cont_PQ=1;
		struct node *tail,*top;
		tail=NULL;
		top = NULL;
		int array[cant_operations + 5];
		
		for(int index=1; index <= cant_operations;index++)
		{
			scanf("%d",&operation);
			
			if(operation == 1)
			{
				scanf("%d",&element);
				tail = ENQUEUE(tail,element);
				top = PUSH(top,element);
				MinPQ_insert(array,element);
			}
			else
			{
				if(operation == 2)
				{
					scanf("%d",&element);
					
					int element_stack = POP(&top);
					int element_queue = DEQUEUE(&tail);
					int element_priority_queue = MinPQ_extract(array);
					
					if(cont_PQ == 1)
						if(element_priority_queue != element)
							cont_PQ = 0;
					if(cont_stack == 1)
						if(element_stack != element)
							cont_stack = 0;
					if(cont_queue == 1)
						if(element_queue != element)
							cont_queue = 0;	
				}
			}
						
		}
		int cont = cont_stack + cont_queue + cont_PQ;
		
		if((cont_stack == 1)&&(cont_PQ==0)&&(cont_queue==0))
			printf("stack\n");
		else
			if((cont_queue == 1)&&(cont_stack == 0) && (cont_PQ== 0))
				printf("queue\n");
			else
				if((cont_PQ == 1) && (cont_stack == 0) && (cont_queue== 0))
					printf("priority queue\n");
				else
					if(cont==2)
						printf("not sure\n");
					else
						printf("impossible\n");	
	}
	return 0;
}
