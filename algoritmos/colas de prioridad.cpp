#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myinfinite 2147483647
int heapsize = 0;
//---------------------------------------------------------------------------------------------
int F_parent(int index)
{
	return index/2;
}
//---------------------------------------------------------------------------------------------
int F_left (int index)
{
	return 2*index;
}
//---------------------------------------------------------------------------------------------
int F_right(int index)
{
	return 2*index+1;
}
//---------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------
int MinPQ_minimun(int Array[])
{
	return Array[1];
}

//-----------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
void MinPQ_insert(int Array[],int key)
{
     heapsize = heapsize+1;
     Array[heapsize]= (myinfinite);
     MinPQ_DecreaseKey(Array,heapsize,key);
}
//---------------------------------------------------------------------------------------------------

int main()
{
    int Array[100000], operation, value;
    heapsize = 0;
    while(scanf("%d", &operation) != EOF)
    {
    if(operation==1)
    {
         scanf("%d", &value);
         MinPQ_insert(Array, value);
    }
    else
    {
        if(operation == 2)
        {
            value = MinPQ_extract(Array);
            if(value != myinfinite)
                  printf("%d\n",value);
        }
        else
            printf("invalid operation\n");
    }
    }
}
