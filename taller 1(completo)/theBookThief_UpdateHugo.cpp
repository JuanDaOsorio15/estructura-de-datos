#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int s, n, triangular;

	while(scanf("%d", &s) && (s != 0))
	{
	    n = (int)((-1 + sqrt(1 + 8 * ((double) s))) / 2);
        triangular = (n * (n + 1)) / 2;

        if(triangular == s)
        {
            printf("%d %d\n", n + 1, n + 1);
        }
        else
        {
            printf("%d %d\n", (n + 1)*(n + 2)/2 - s, n + 1);
        }
	}

	return 0;
}
