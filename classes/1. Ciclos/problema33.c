#include<stdio.h>
#include<conio.h>
int main()
{
  /* EUP QUE LEA 10 NUMEROS ENTEROS DESDE EL
     TECLADO Y DETERMINE CUANTOS SON POSITIVOS
   */
  int cont,num,x;
  
     cont=0;      
     for(x=0;x<3;x++)
       {	   
	     printf("Ingrese Valor: ");
	     scanf("%d",&num);
	     if(num>0) cont++;
	   }          
     printf("CANT. POSITIVOS >> %d",cont);
  
 return 0;
}