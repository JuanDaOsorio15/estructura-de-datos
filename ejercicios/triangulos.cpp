#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BinarySearch(int A[], int i, int j, int n){

    int m, result=-1;

    while(i<=j){
        m=(i+j)>>1;
        if (A[m]==n){
            result=m;
            break;
        }
        else{
            if(n>A[m])
                i=m+1;
            else
                j=m-1;
        }
    }
    if(result==-1)
        result=(-1)*i-1;
    return result;
}

int cant_triangulos(int arr[], int cant_elementos){
  int respuesta = 0;
  int max_value = arr[cant_elementos - 1];

  if(max_value % 3 == 0)
  {
      int lado = max_value/3;
    /*
      printf("%d   %d\n",max_value,lado );
    */
      //se define el inicio y el final de la segunda y tercera particion
      int inicio_BB1 = abs(BinarySearch(arr, 0, cant_elementos - 1, lado))-1;
      int fin_BB1 = abs(BinarySearch(arr, 0, cant_elementos - 1, lado * 2))-1 - 1;
      int inicio_BB2 = fin_BB1 + 1;
      int fin_BB2 = abs(BinarySearch(arr, 0, cant_elementos - 1, lado * 3))-1;

      //se evalua si hay elementos relacionados a la primera particion
      for (int i=0; i<inicio_BB1; i++){
        if((BinarySearch(arr, inicio_BB1, fin_BB1, arr[i]+lado)-1 != -1) &&
        (BinarySearch(arr, inicio_BB2, fin_BB2, arr[i]+(lado*2))-1 != -1))
        {
          respuesta++;
        }
      }
  }

  return respuesta;
}

int main()
{
    int cant_elementos, val, arr[100000];

    while(scanf("%d", &cant_elementos) != EOF)
    {
        for(int i=0; i<cant_elementos; i++)
        {
            scanf("%d", &val);
            if(i==0)
            {
                arr[i] = val;
            }
            else
            {
                arr[i] = arr[i-1] + val;
            }
        }
        printf("%d\n", cant_triangulos(arr, cant_elementos));

    }


    return 0;
}
