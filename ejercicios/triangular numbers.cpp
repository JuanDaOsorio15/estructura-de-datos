#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    unsigned long long n,x,s;
    
    while(scanf("%llu",&n)&&(n!=0))
    {
		x=(-1+sqrt(1+(8*(double)n)))/2;
 		s=(x*(x+1))/2;
           if(s==n)
               printf("YES\n");
           else
               printf("NO\n");
    }
    return 0;
}

