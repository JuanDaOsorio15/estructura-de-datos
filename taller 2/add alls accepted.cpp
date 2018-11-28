#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//----------------------------------------------------------------------
#define myinfinite 2147483647
int heapsize = 0;
int cost=0;
int add=0;
//-----------------------------------------------------------------------
//receive one  queues
//order it.
//extract the minimun number two times 
//add both numbers
//insert the result to the queues
//order again
//------------------------------------------------------------------------
//conditions:
//positive integer 0<n<5000
//n integers less than 100000
//end with n=0 (R)
//------------------------------------------------------------------------
int F_parent(int index)
{
	return index/2;
}
//------------------------------------------------------------------------
int F_right(int index)
{
	return 2*index+1;
}
//------------------------------------------------------------------------
int F_left (int index)
{
	return 2*index;
}
//------------------------------------------------------------------------
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
//------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
int MinPQ_extract(int Array[])
{
	long long int min = -1*myinfinite;
	if( heapsize < 1)
		printf("heap underflow\n");
	else
	{
		min = Array[1];
		Array[1] = Array[heapsize];
		heapsize = heapsize - 1;
		MinHeapify(Array,1);
  }
	return min;
}
//----------------------------------------------------------------------------------
void MinPQ_insert(int Array[],int key)
{
     heapsize = heapsize+1;
     Array[heapsize]= (myinfinite);
     MinPQ_DecreaseKey(Array,heapsize,key);
}
//----------------------------------------------------------------------------------
int main()
{
	int element, Array[5005],cant_elements,num1,num2,copy;
	while(scanf("%d",&cant_elements) && (cant_elements !=0))
	{
		heapsize=0;
		cost=0;
		add=0;
		for(int index=1; index<= cant_elements; index++)
		{
			scanf("%d",&element);
			MinPQ_insert(Array,element);
		}	

		while(heapsize > 1)
		{
			MinHeapify(Array,1);
			num1=MinPQ_extract(Array);
			num2=MinPQ_extract(Array);
			add=num1 + num2;
			cost=cost+add;
			MinPQ_insert(Array,add);	
		}
		printf("%d\n",cost);
	}
	return 0;
}
