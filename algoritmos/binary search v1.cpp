#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

int binary_search (int Arreglo[], int i, int j, int n){
	
	int m;
	if( i> j){
		return -1;
	}
	else{
		m= (i+j)/2;
		if(Arreglo[m]== n){
			return m;
		}
		else{
			if (n> Arreglo[m])
				return binary_search(Arreglo, m+1,j,n);
			else
				return binary_search(Arreglo, i, m-1,n);
			
		}
	}
		
}

int main(){
	
	int Arreglo[100005], element, index,n,q;
	int position;
	
	while(scanf("%d", &n) != EOF){
		for(index= 1; index <= n; index++){
			scanf("%d", &element);
			Arreglo[index]= element;
		}
		scanf("%d", &q);
		for(index=1;index <= q; index++){
			scanf("%d", &element);
			position= binary_search(Arreglo, 1 ,n,element);
			if(position== -1)
				printf(" the element %d is not in the array\n ", element);
			else
				printf(" the element %d is in the position %d\n", element, position);
			
		}
	}
	return 0;
}
