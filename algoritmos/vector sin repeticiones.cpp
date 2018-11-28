#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int ta;
	scanf("%d",&ta);
	int a1[ta],a2[ta],i,m,num,i2,ta2=0;
	i=1;
	i2=1;
	
	for(int i3=1;i3<=ta;i3++)
	{
		scanf("%d",&num);
		a1[i3]=num;
	}
//------------------------------------------------------------------------------------	
		while(i<=ta)
	{
		if(a1[i]==a1[i+1])
		{
			if(i==ta)
			{
				ta2++;
				m=a1[i];
				a2[i2]=m;
			}
			i++;
		}else
		if(a1[i]!=a1[i+1])
		{
			ta2++;
			m=a1[i];
			a2[i2]=m;
			i++;
			i2++;
		}
	}
//------------------------------------------------------------------------------------------	
	for(int i4=1;i4<=ta2;i4++)
	{
		printf("%d\n",a2[i4]);
	}
	printf("%d",ta2);
}


