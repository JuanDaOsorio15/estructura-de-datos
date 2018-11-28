#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MyNegativeInfinite 0

struct node
{
	char key;
	struct node *next;
};

//----------------------------------------------------------------------------
//PILAS

struct node *ENQUEUE(struct node *tail, char element)
{
	struct node *newnode;
	newnode = ( struct node *) malloc (sizeof (struct node));
	newnode -> key = element;
	if (tail == NULL)
	{
		newnode -> next = newnode;
		tail = newnode;
	}
	else
	{
		newnode -> next = tail -> next;
		tail -> next = newnode;
		tail = newnode;
	}
	return tail;
}

char DEQUEUE (struct node **tail)
{
	struct node *q;
	char element = MyNegativeInfinite;
	if (*tail != NULL)
	{
		if(*tail == (*tail) -> next)
		{
			element = ((*tail) -> key);
			free(*tail);
			*tail = NULL;
		}
		else
		{
			q = (*tail) -> next;
			element = q -> key;
			(*tail) -> next = q -> next;
			free(q);
		}
	}
	return element;
}


//----------------------------------------------------------------------------
//COLAS

struct node *PUSH(struct node *top, char element)
{
	struct node *newnode;
	newnode = (struct node *) malloc (sizeof(struct node));
	newnode -> key = element;
	newnode -> next = top;
	top = newnode;
	return top;
}

char POP (struct node **top)
{
	struct node *temp;
	char element = MyNegativeInfinite;
	if(*top != NULL)
	{
		temp = *top;
		element = temp->key;
		*top = (*top)->next;
		free(temp);
	}
	return element;
}

int Comparar (char element)
{
	if (element == 'A' || element == 'H' || element == 'I'|| element == 'M' || element == 'O'
		|| element == 'T' || element == 'U' || element == 'V' || element == 'W' || element == 'X'
		|| element == 'Y')
		return 1;
	else
		return 0;
}

struct node *EmptyQueue(struct node *tail)
{
    char element;
    while(tail != NULL)
    {
        element = DEQUEUE(&tail);
    }
    tail = NULL;
    return tail;
}

struct node *EmptyStack(struct node *top)
{
    char element;
    while(top != NULL)
    {
        element = POP(&top);
    }
    top = NULL;
    return top;
}



int main()
{

	char palabra[105];
	struct node *top, *tail;
	int index, flag, totaltowers, contador, length;
	char  element1, element2;
	scanf("%d", &totaltowers);

	for(contador = 1; contador <= totaltowers; contador++)
	{
        top = NULL;
        tail = NULL;
		flag = 1;
		length = 0;
		scanf("%s", palabra);
		for(index=0; palabra[index] != '\0'; index++)
		{
                top = PUSH(top, palabra[index]);
                tail = ENQUEUE(tail, palabra[index]);
                length++;
        }

            while (length > 0)
            {
                element1 = POP(&top);
                element2 = DEQUEUE(&tail);
                length--;

                if (element1 != element2)
                {
                    flag = 0;
                    tail = EmptyQueue(tail);
                    top = EmptyStack(top);
                    length = 0;
                }
            	else
            	{
            		if(Comparar(element1) == 1)
            		{
            			length--;
					}
					else
					{
						flag = 0;
						tail = EmptyQueue(tail);
                    	top = EmptyStack(top);
                    	length = 0;
					}
            	}
			}
            if (flag == 1)
                printf("YES\n");
            else
                printf("NO\n");

        }

	return 0;
}
