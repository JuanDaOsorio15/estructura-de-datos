#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define infinite 2147483647
long long int inv=0;
long long int Array[1000005];
int AL[500005], AR[500005];

void Merge (long long int Array[],int first,int half,int last)
{
	int num1, num2, index2, k, index1;
	num1= half - first + 1;
	num2= last - half;
	
	for(index1=1;index1<=num1;index1++)
		AL[index1]=Array[first + index1 -1];
		
	for(index2=1;index2<=num2;index2++)
		AR[index2]=Array[half + index2];
		
	AL[num1+1]=infinite;
	AR[num2+1]=infinite;
	
	index1=1;
	index2=1;
	
	for(k=first;k<= last; k++)
	{
		if(AL[index1]<= AR[index2])
		{
			Array[k]=AL[index1];
			index1++;
		}else
		{
			Array[k]=AR[index2];
			index2++;
			inv= inv + num1 - index1 + 1;
		}
	}
}

void MergeSort (long long int Array[],int first, int last)
{
	int half;
	if(first< last)
	{
		half=floor((first + last)/2);
		MergeSort(Array,first,half);
		MergeSort(Array,(half + 1),last);
		Merge(Array,first,half,last);
	}
}

int main()
{
	int lenghtarray,element,index;
	while(scanf("%d",&lenghtarray) && (lenghtarray != 0) && (lenghtarray < 1000005))
	{
		inv=0;
		for(index=1; index<= lenghtarray; index++)
		{
			scanf("%d", &element);
			Array[index]= element;
		}
		
		MergeSort(Array,1,lenghtarray);
		printf("%ull\n", inv);
	}
	return 0;
}
