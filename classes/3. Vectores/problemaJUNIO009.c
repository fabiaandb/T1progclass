#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LIM 8
int main()
{ 
 int V[LIM];
 int i,j,aux;
 
 // INICIALIZACION CON NUMEROS ALEATORIOS
 printf("\n\n");
 srand((unsigned)time(NULL));
 for(i=0;i<LIM;i++)
   V[i]=rand()%100+1;
 printf("\n\n");  
 
 // MOSTRAR CONTENIDO DEL VECTOR
 printf("\nORDEN ORIGINAL...\n");
 for(i=0;i<LIM;i++)
   printf("%5d",V[i]);
 printf("\n\n");  

 // METODO DE ORDENAMIENTO
    for(j=0;j<(LIM-1);j++)
	   for(i=0;i<(LIM-1);i++)    
	      if(V[i] > V[i+1])
	        {
	          aux=V[i];
	          V[i]=V[i+1];
	          V[i+1]=aux;
			}	      

 // MOSTRAR CONTENIDO DEL VECTOR
 printf("\nORDENADO...\n");
 for(i=0;i<LIM;i++)
   printf("%5d",V[i]);
 printf("\n\n");    
 
 return 0;
}
      




