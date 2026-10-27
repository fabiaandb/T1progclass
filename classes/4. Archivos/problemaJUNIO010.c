#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LIM 8

typedef struct p
{
 int cod;
 int monto;	 
}nodo;

int main()
{ 
 nodo V[LIM],aux;
 int i,j;
 
 // INICIALIZACION CON NUMEROS ALEATORIOS
 printf("\n\n");
 srand((unsigned)time(NULL));
 for(i=0;i<LIM;i++)
   {   
    V[i].cod=(i+1)*100;
	V[i].monto=rand()%100+1;
   }
 printf("\n\n");  
 
 // MOSTRAR CONTENIDO DEL VECTOR
 printf("\nORDEN ORIGINAL...\n");
 for(i=0;i<LIM;i++)
   printf("%5d-%d\n",V[i].cod,V[i].monto);
 printf("\n\n");  
 
 // METODO DE ORDENAMIENTO
    for(j=0;j<(LIM-1);j++)
	   for(i=0;i<(LIM-1);i++)    
	      if(V[i].monto > V[i+1].monto)
	        {
	          aux=V[i];
	          V[i]=V[i+1];
	          V[i+1]=aux;
			}
				      
 // MOSTRAR CONTENIDO DEL VECTOR
 printf("\nORDENADO...\n");
 for(i=0;i<LIM;i++)
   printf("%5d-%d\n",V[i].cod,V[i].monto);
 printf("\n\n");  
 return 0;
}
      




