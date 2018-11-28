//INPUT
// total transactions
//operation:  
// 1 priority name: add new patient;
// 2 && hour(seconds): attent patient
//Ends with EOF
//OUTPUT
//the same lines as transactions of type 2
//in the same line=
//hour arrival
//hour attended
//wait time
//name

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define myinfinite 2147483647;
//-------------------------------------------------------------------------------------------------
int heapsize = 0;
//-------------------------------------------------------------------------------------------------
struct system{
  int time;//hour arrival
  int triage;// urgency priority (1 to 5)
  char name[25];//name
};
//-------------------------------------------------------------------------------------------------
struct system patient[105];
//--------------------------------------------------------------------------------------------------
int Parent(int index)
{
  return (int) floor(index/2);
}
//--------------------------------------------------------------------------------------------------
int f_left(int index)
{
    return (2 * index);
}
//---------------------------------------------------------------------------------------------------
int f_right(int index)
{
  return ((2 * index) + 1);
}
//---------------------------------------------------------------------------------------------------
void MinHeapify(struct system patient[], int index)
{
  int left,right,least;
  struct system temp;
   
  left=f_left(index);
  right=f_right(index);

  if((left <= heapsize) && (patient[left].triage < patient[index].triage))
    	least = left;
	else
    	least = index;

  if((left <= heapsize) && (patient[left].triage == patient[index].triage))
  {
    if(patient[left].time < patient[index].time)
      least = left;
    else
      least = index;
  }

  if((right <= heapsize) && (patient[right].triage < patient[least].triage))
    least = right;

  if((right <= heapsize) && (patient[right].triage == patient[least].triage))
  {
    if (patient[right].time < patient[least].time)
      least = right;
  }

  if (least != index)
  {
    temp = patient[index];
    patient[index] = patient[least];
    patient[least] = temp;
    MinHeapify(patient, least);
  }
}
//----------------------------------------------------------------------------------------------------
struct system MinPQ_Minimum(struct system patient[])
{
  return patient[1];
}
//-----------------------------------------------------------------------------------------------------
struct system MinPQ_Extract(struct system patient[])
{
  struct system minimun;
  minimun.triage = myinfinite;
  if(heapsize < 1)
    printf("Error (Heap underflow!)\n");
  else 
  {
    minimun = patient[1];
    patient[1] = patient[heapsize];
    heapsize = heapsize - 1;
    MinHeapify(patient, 1);
  }
  return minimun;
}
//--------------------------------------------------------------------------------------------------------
void MinPQ_DecreaseKey(struct system patient[], int index, struct system element)
{
	struct system temp;
	if(element.triage > patient[index].triage)
    	printf("Error (New key is higher than current key)");
	else
	{
		patient[index] = element;
    	while ((index > 1) && (patient[Parent(index)].triage > patient[index].triage))
		{
    		temp = patient[index];
    		patient[index] = patient[Parent(index)];
    		patient[Parent(index)] = temp;
    		index = Parent(index);
    	}
  	}
}
//-------------------------------------------------------------------------------------------------------------
void MinPQ_Insert(struct system patient[], struct system element)
{
	struct system temp;
	heapsize = heapsize + 1;
	temp.triage = myinfinite;
	patient[heapsize] = temp;
	MinPQ_DecreaseKey(patient, heapsize, element);
}
//--------------------------------------------------------------------------------------------------------------
int main()
{
	int transaction, operation, hour_arrival, triage, hour_attention;
	char name[25], *n;
	struct system temp;
  
	while (scanf("%d", &transaction) != EOF)
	{
		heapsize = 0;
		int index=1;
		while(index <= transaction)
		{
			scanf("%d", &operation);
			if (operation == 1)
			{
				scanf("%d %d %s", &hour_arrival, &triage, name);
        		temp.time = hour_arrival;
        		temp.triage = triage;
        		strcpy(temp.name, name);
        		MinPQ_Insert(patient, temp);
			}
			else
			{
				if(operation == 2)
				{
					scanf("%d", &hour_attention);
					temp = MinPQ_Extract(patient);
					hour_arrival = temp.time;
					n = temp.name;
					printf("%d %d %d %s\n", hour_arrival, hour_attention,(hour_attention - hour_arrival), n);
        		}
        		else
		  		{
					printf("wrong command.\n 1). Insert new patient.\n 2).attend a patient\n");
		  		}
      		}	
      	index++;
		}
  	}
  return 0;
}
