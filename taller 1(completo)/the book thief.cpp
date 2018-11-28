#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int array[100005],result, missing_page, page_number, index,index2;
	 
	array[0]=0;
	for(index=1;index<=100005; index++)
	{
	 	array[index]=array[index-1]+index;
	}
	 
	while(scanf("%d",&result) && (result != 0))
	{
	 	for(index2=1; index2<=100005;index2++)
	 	{
	 		if(result<array[index2])
	 		{
	 			page_number=index2;
	 			missing_page=-1*(result-array[index2]);
	 			break;
			}
		}
		 
		printf("%d"" %d\n",missing_page,page_number);
	}
	 
	return 0;
}
