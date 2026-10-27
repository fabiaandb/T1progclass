#include<stdio.h>
#include<conio.h>
int main()
{
 int cont,acum,num;
 
 /* EUP QUE LEA UNA LISTA DE NUMEROS ENTEROS DESDE EL
    TECLADO Y CALCULE SU PROMEDIO; EL ULTIMO NUMERO 
	DE LA LISTA ES EL CERO.
 */
 acum=0;
 cont=0; 
 printf("Ingrese Primer Numero: ");
 scanf("%d",&num);  
 while(num!=0)
   {
   	  cont++;
   	  acum+=num;
   	  //system("cls");
      printf("Ingrese sig. Numero: ") ;
     scanf("%d",&num);
   }
 printf("CANT. NUMEROS: %d \n",cont);
 printf("ACUM. NUMEROS: %d \n",acum);
 printf("     PROMEDIO: %.2f \n",((float)acum/cont));
 
 return 0;
}
