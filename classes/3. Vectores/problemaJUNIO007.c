#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LIM 5
int main()
{ 
 int V[LIM];
 int i;

 // INICIALIZACION MANUAL DEL VECTOR
 printf("\n\n");
 for(i=0;i<LIM;i++)
   { 
     printf("%3d) Ingrese Valor: ",i);
     scanf("%d",&V[i]);
   };
 printf("\n\n");  
 
 // MOSTRAR CONTENIDO DEL VECTOR
 printf("\n\n");
 for(i=0;i<LIM;i++)
   printf("%5d",V[i]);
 return 0;
}
      




