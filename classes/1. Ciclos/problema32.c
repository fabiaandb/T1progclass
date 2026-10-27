#include<stdio.h>
#include<conio.h>
int main()
{
  /* EUP QUE MUESTRE LOS PRIMERO 10 NUMEROS PARES */
  int X;  
  
  /* F1 */
  for(X=0;X<10;X++)
     printf("%5d",2*X);  
  
  /* F2 
  for(X=0;X<20;X+=2)
     printf("%5d",X);
  */
  
  /* F1
  for(X=0;X<20;X++)
     if((X%2)==0)
       printf("%5d",X);
  */     
  
 return 0;
}