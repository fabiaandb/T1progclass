#include<stdio.h>
#include<conio.h>
int main()
{	
 /*
 EUP que muestre todos los numeros de 0 a 100 que 
 cumpla con la condicion de ser igual a la suma de 
 sus divisores excluyendo a el mismo
   12  >> 6 4 3 2 1  NO
    6  >> 3 2 1      SI
 */

 int x,i,acum; 
 for(x=1;x<=100;x++)
   {
    printf("%5d >> ",x); 
    acum=0;
    for(i=1;i<x;i++)
        if((x%i)==0) 
		  {
		  	printf("%3d ",i);
		  	acum=acum+i;
		  }
	if(acum==x)printf(" >> CUMPLE");
    printf("\n");    
   } 
 return 0;
}










