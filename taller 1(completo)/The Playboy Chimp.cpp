#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//print two numbers in one line
//first one : tallest lady
//second one: shortest lady
//if u dont find put x
//----------------------------------------------------------------------------------------------
int BB(int A[], int i, int j, int n) {
  int m, result = -1;
  while(i <= j){
    m =(i+j) >> 1;
    if (A[m]==n) {
      result = m;
      break;
    } else {
      if(n>A[m]) {
        i=m+1;
      } else {
        j=m-1;
      }
    }
  }
  if(result == -1) {
    result = (-1)*i;
  }
  return result;
}
//---------------------------------------------------------------------------------------------
int main()
{
	int index,array_chimps[100005],array_lucho[100005],position,size_array2=0,element,array_chimps2[100005],index2=1;
	unsigned long long queries,lady_chimps,heights,heights_lucho;
	
	scanf("%llu",&lady_chimps);
	for(index=1;index<=lady_chimps;index++)
	{
		scanf("%llu",&heights);
		array_chimps[index]=heights;
	}
	
	scanf("%llu",&queries);
	
		for(index=1;index<=queries;index++)
		{
			scanf("%llu",&heights_lucho);
			array_lucho[index]=heights_lucho;
		}
		
	index=1;
	
	while(index<=lady_chimps)
	{
		if(array_chimps[index]==array_chimps[index+1])
		{
			if(index==lady_chimps)
			{
				size_array2++;
				element=array_chimps[index];
				array_chimps2[index2]=element;
			}
			index++;
		}
		else
		if(array_chimps[index] != array_chimps[index+1])
		{
			size_array2++;
			element=array_chimps[index];
			array_chimps2[index2]=element;
			index++;
			index2++;
		}
	}	
	
		for(index=1;index<=queries;index++)
		{
			position=BB(array_chimps2,1,size_array2,array_lucho[index]);
			if(position>0)
			{
				if(position==size_array2)
					printf("%llu" " %s\n",array_chimps2[position-1],"X");
				else
				if(position==1)
					printf("%s" " %llu\n","X",array_chimps2[position+1]);
				else
				if(position>size_array2)
					printf("%llu" " %s\n",array_chimps2[size_array2],"X");
				else	
					printf("%llu" " %llu\n",array_chimps2[position-1],array_chimps2[position+1]);
			}else
			if(position<0)
			{
				if((-1*position)>size_array2)
					printf("%llu" " %s\n",array_chimps2[size_array2],"X" );
				else 
				if((-1*position)==1)
					printf("%s" " %llu\n", "X" ,array_chimps2[1]);
				else
					printf("%llu" " %llu\n",array_chimps2[(-1*(position))-1],array_chimps2[-1*position]);	
			}
		}
	return 0;
}
